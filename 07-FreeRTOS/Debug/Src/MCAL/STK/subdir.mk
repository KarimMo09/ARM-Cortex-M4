################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/STK/STK_prg.c 

OBJS += \
./Src/MCAL/STK/STK_prg.o 

C_DEPS += \
./Src/MCAL/STK/STK_prg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/STK/%.o Src/MCAL/STK/%.su: ../Src/MCAL/STK/%.c Src/MCAL/STK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CDUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-STK

clean-Src-2f-MCAL-2f-STK:
	-$(RM) ./Src/MCAL/STK/STK_prg.d ./Src/MCAL/STK/STK_prg.o ./Src/MCAL/STK/STK_prg.su

.PHONY: clean-Src-2f-MCAL-2f-STK

