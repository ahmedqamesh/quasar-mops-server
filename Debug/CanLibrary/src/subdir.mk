################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CanLibrary/src/CanWorkerThread.cpp \
../CanLibrary/src/CanWrapper.cpp 

OBJS += \
./CanLibrary/src/CanWorkerThread.o \
./CanLibrary/src/CanWrapper.o 

CPP_DEPS += \
./CanLibrary/src/CanWorkerThread.d \
./CanLibrary/src/CanWrapper.d 


# Each subdirectory must supply rules for building sources it contributes
CanLibrary/src/%.o: ../CanLibrary/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


