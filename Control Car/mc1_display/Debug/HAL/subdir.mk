################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SevenSegment.c \
../HAL/external_eeprom.c \
../HAL/keypad.c \
../HAL/lcd.c \
../HAL/motor.c \
../HAL/ultra_sonic.c 

OBJS += \
./HAL/SevenSegment.o \
./HAL/external_eeprom.o \
./HAL/keypad.o \
./HAL/lcd.o \
./HAL/motor.o \
./HAL/ultra_sonic.o 

C_DEPS += \
./HAL/SevenSegment.d \
./HAL/external_eeprom.d \
./HAL/keypad.d \
./HAL/lcd.d \
./HAL/motor.d \
./HAL/ultra_sonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


