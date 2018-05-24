################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Ass-03-Lib.c \
../Src/Ass-03-Task-01.c \
../Src/Ass-03-Task-02.c \
../Src/Ass-03-Task-03.c \
../Src/Ass-03-Task-04.c \
../Src/CommandList.c \
../Src/Debug.c \
../Src/StringBuilder.c \
../Src/adc.c \
../Src/bsp_driver_sd.c \
../Src/dma.c \
../Src/fatfs.c \
../Src/freertos.c \
../Src/fsmc.c \
../Src/gpio.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/sdio.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/usart.c 

OBJS += \
./Src/Ass-03-Lib.o \
./Src/Ass-03-Task-01.o \
./Src/Ass-03-Task-02.o \
./Src/Ass-03-Task-03.o \
./Src/Ass-03-Task-04.o \
./Src/CommandList.o \
./Src/Debug.o \
./Src/StringBuilder.o \
./Src/adc.o \
./Src/bsp_driver_sd.o \
./Src/dma.o \
./Src/fatfs.o \
./Src/freertos.o \
./Src/fsmc.o \
./Src/gpio.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/sdio.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/usart.o 

C_DEPS += \
./Src/Ass-03-Lib.d \
./Src/Ass-03-Task-01.d \
./Src/Ass-03-Task-02.d \
./Src/Ass-03-Task-03.d \
./Src/Ass-03-Task-04.d \
./Src/CommandList.d \
./Src/Debug.d \
./Src/StringBuilder.d \
./Src/adc.d \
./Src/bsp_driver_sd.d \
./Src/dma.d \
./Src/fatfs.d \
./Src/freertos.d \
./Src/fsmc.d \
./Src/gpio.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/sdio.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Inc" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/BSP" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FatFs/src" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/include" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


