################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/EXTI/EXTI_prg.c 

OBJS += \
./Src/MCAL/EXTI/EXTI_prg.o 

C_DEPS += \
./Src/MCAL/EXTI/EXTI_prg.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/EXTI/%.o Src/MCAL/EXTI/%.su: ../Src/MCAL/EXTI/%.c Src/MCAL/EXTI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CDUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-EXTI

clean-Src-2f-MCAL-2f-EXTI:
	-$(RM) ./Src/MCAL/EXTI/EXTI_prg.d ./Src/MCAL/EXTI/EXTI_prg.o ./Src/MCAL/EXTI/EXTI_prg.su

.PHONY: clean-Src-2f-MCAL-2f-EXTI

