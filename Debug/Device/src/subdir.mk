################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Device/src/DADCChannels.cpp \
../Device/src/DCanBus.cpp \
../Device/src/DCanBusMonitoring.cpp \
../Device/src/DDcsMoPSControlServer.cpp \
../Device/src/DMOMO.cpp \
../Device/src/DMOPS.cpp \
../Device/src/DMOPSConfiguration.cpp \
../Device/src/DMOPSHUBCrate.cpp \
../Device/src/DMOPSMonitoring.cpp \
../Device/src/DPP3Location.cpp \
../Device/src/DTemperatureModule.cpp 

OBJS += \
./Device/src/DADCChannels.o \
./Device/src/DCanBus.o \
./Device/src/DCanBusMonitoring.o \
./Device/src/DDcsMoPSControlServer.o \
./Device/src/DMOMO.o \
./Device/src/DMOPS.o \
./Device/src/DMOPSConfiguration.o \
./Device/src/DMOPSHUBCrate.o \
./Device/src/DMOPSMonitoring.o \
./Device/src/DPP3Location.o \
./Device/src/DTemperatureModule.o 

CPP_DEPS += \
./Device/src/DADCChannels.d \
./Device/src/DCanBus.d \
./Device/src/DCanBusMonitoring.d \
./Device/src/DDcsMoPSControlServer.d \
./Device/src/DMOMO.d \
./Device/src/DMOPS.d \
./Device/src/DMOPSConfiguration.d \
./Device/src/DMOPSHUBCrate.d \
./Device/src/DMOPSMonitoring.d \
./Device/src/DPP3Location.d \
./Device/src/DTemperatureModule.d 


# Each subdirectory must supply rules for building sources it contributes
Device/src/%.o: ../Device/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


