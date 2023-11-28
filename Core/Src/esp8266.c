#include "esp8266.h"
#include "main.h"



void Rx_USART2_init(USART2_t *ring_buffer, uint8_t *buffer, uint16_t capacity)
{
	ring_buffer->buffer = buffer;
	ring_buffer->capacity = capacity;

	ring_buffer->head = 0;
	ring_buffer->tail = 0;
	ring_buffer->is_full = 0;
}
uint8_t Rx_USART2_put(USART2_t *ring_buffer, uint8_t data)
{
	ring_buffer->buffer[ring_buffer->head] = data;
	ring_buffer->head = (ring_buffer->head + 1) % ring_buffer->capacity;

	if (ring_buffer->is_full != 0) {
		ring_buffer->tail = (ring_buffer->tail + 1) % ring_buffer->capacity;
	}

	if (ring_buffer->head == ring_buffer->tail) {
		ring_buffer->is_full = 1;
		return 0;
	}
	return 1;
}

/**
 * @brief This function returns the size of the ring buffer
*/
uint16_t Rx_USART2_size(USART2_t *ring_buffer)
{
	uint16_t size = 0;

	if ((ring_buffer->is_full == 0) && (ring_buffer->tail <= ring_buffer->head)) {
		size = ring_buffer->head - ring_buffer->tail;
	} else {
		size = ring_buffer->head + (ring_buffer->capacity - ring_buffer->tail);
	}

	return size;
}

void Rx_USART2(USART2_t *ring_buffer) {
    if (LL_USART_IsActiveFlag_RXNE(USART2)){
        uint8_t received_data = LL_USART_ReceiveData8(USART2);
        Rx_USART2_put(ring_buffer, received_data); // Sin desreferenciar
        //printf("data %x \r\n", received_data);
    }
}

void Rx_USART2_reset(USART2_t *ring_buffer)
{
	ring_buffer->tail = 0;
	ring_buffer->head = 0;
	ring_buffer->is_full = 0;
}


