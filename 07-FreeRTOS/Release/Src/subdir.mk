################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/croutine.c \
../Src/event_groups.c \
../Src/heap_4.c \
../Src/list.c \
../Src/main.c \
../Src/port.c \
../Src/queue.c \
../Src/stream_buffer.c \
../Src/tasks.c \
../Src/timers.c 

OBJS += \
./Src/croutine.o \
./Src/event_groups.o \
./Src/heap_4.o \
./Src/list.o \
./Src/main.o \
./Src/port.o \
./Src/queue.o \
./Src/stream_buffer.o \
./Src/tasks.o \
./Src/timers.o 

C_DEPS += \
./Src/croutine.d \
./Src/event_groups.d \
./Src/heap_4.d \
./Src/list.d \
./Src/main.d \
./Src/port.d \
./Src/queue.d \
./Src/stream_buffer.d \
./Src/tasks.d \
./Src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F401CDUx -DSTM32 -DSTM32F4 -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/croutine.d ./Src/croutine.o ./Src/croutine.su ./Src/event_groups.d ./Src/event_groups.o ./Src/event_groups.su ./Src/heap_4.d ./Src/heap_4.o ./Src/heap_4.su ./Src/list.d ./Src/list.o ./Src/list.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/port.d ./Src/port.o ./Src/port.su ./Src/queue.d ./Src/queue.o ./Src/queue.su ./Src/stream_buffer.d ./Src/stream_buffer.o ./Src/stream_buffer.su ./Src/tasks.d ./Src/tasks.o ./Src/tasks.su ./Src/timers.d ./Src/timers.o ./Src/timers.su

.PHONY: clean-Src

