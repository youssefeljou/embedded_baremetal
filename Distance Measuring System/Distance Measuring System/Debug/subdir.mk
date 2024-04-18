################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GIE.c \
../gpio.c \
../lcd.c \
../main.c \
../timers.c \
../ultra_sonic.c 

OBJS += \
./GIE.o \
./gpio.o \
./lcd.o \
./main.o \
./timers.o \
./ultra_sonic.o 

C_DEPS += \
./GIE.d \
./gpio.d \
./lcd.d \
./main.d \
./timers.d \
./ultra_sonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


