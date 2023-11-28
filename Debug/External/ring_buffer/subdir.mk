################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External/ring_buffer/ring_buffer.c 

OBJS += \
./External/ring_buffer/ring_buffer.o 

C_DEPS += \
./External/ring_buffer/ring_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
External/ring_buffer/%.o External/ring_buffer/%.su External/ring_buffer/%.cyclo: ../External/ring_buffer/%.c External/ring_buffer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../External/ring_buffer -I../External/ssd1306 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-External-2f-ring_buffer

clean-External-2f-ring_buffer:
	-$(RM) ./External/ring_buffer/ring_buffer.cyclo ./External/ring_buffer/ring_buffer.d ./External/ring_buffer/ring_buffer.o ./External/ring_buffer/ring_buffer.su

.PHONY: clean-External-2f-ring_buffer

