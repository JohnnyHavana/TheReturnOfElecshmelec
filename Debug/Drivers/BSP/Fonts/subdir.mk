################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Fonts/font12.c \
../Drivers/BSP/Fonts/font16.c \
../Drivers/BSP/Fonts/font20.c \
../Drivers/BSP/Fonts/font24.c \
../Drivers/BSP/Fonts/font8.c 

OBJS += \
./Drivers/BSP/Fonts/font12.o \
./Drivers/BSP/Fonts/font16.o \
./Drivers/BSP/Fonts/font20.o \
./Drivers/BSP/Fonts/font24.o \
./Drivers/BSP/Fonts/font8.o 

C_DEPS += \
./Drivers/BSP/Fonts/font12.d \
./Drivers/BSP/Fonts/font16.d \
./Drivers/BSP/Fonts/font20.d \
./Drivers/BSP/Fonts/font24.d \
./Drivers/BSP/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Fonts/%.o: ../Drivers/BSP/Fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Inc" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/BSP" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FatFs/src" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/include" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"U:/ELEC3730/jordanandevansharedworkspacefolder/ELEC3730-2018s1-Ass-03-Template-v03/Ass-03-STM32/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


