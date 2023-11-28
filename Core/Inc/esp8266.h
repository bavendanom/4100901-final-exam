/*
 * esp8266.h
 *
 *  Created on: Nov 26, 2023
 *      Author: braya
 */

#ifndef INC_ESP8266_H_
#define INC_ESP8266_H_
#include <stdint.h>

typedef struct {
	uint8_t  *buffer;  /*!\ Pointer to memory location */
	uint16_t head;     /*!\ To write new data */
	uint16_t tail;     /*!\ To read old data */

	uint16_t capacity;
	uint8_t  is_full;

} USART2_t;

void Rx_USART2_init(USART2_t *ring_buffer, uint8_t *buffer, uint16_t capacity);
uint8_t Rx_USART2_put(USART2_t *ring_buffer, uint8_t data);
void Rx_USART2(USART2_t *ring_buffer);
uint16_t Rx_USART2_size(USART2_t *ring_buffer);
void Rx_USART2_reset(USART2_t *ring_buffer);
#endif /* INC_ESP8266_H_ */
