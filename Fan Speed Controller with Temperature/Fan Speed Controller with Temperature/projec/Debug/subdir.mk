################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../motor.c \
../pwm.c \
../run_app.c 

OBJS += \
./adc.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./motor.o \
./pwm.o \
./run_app.o 

C_DEPS += \
./adc.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./motor.d \
./pwm.d \
./run_app.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


