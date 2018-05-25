################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/ili9325.c \
../Drivers/BSP/openx07v_c_lcd.c \
../Drivers/BSP/touch_panel.c 

OBJS += \
./Drivers/BSP/ili9325.o \
./Drivers/BSP/openx07v_c_lcd.o \
./Drivers/BSP/touch_panel.o 

C_DEPS += \
./Drivers/BSP/ili9325.d \
./Drivers/BSP/openx07v_c_lcd.d \
./Drivers/BSP/touch_panel.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o: ../Drivers/BSP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Inc" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Drivers/BSP" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Middlewares/Third_Party/FatFs/src" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Jordan/Documents/SystemWorkbench/TheReturnOfElecshmelec-master/TheReturnOfElecshmelec-master/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


