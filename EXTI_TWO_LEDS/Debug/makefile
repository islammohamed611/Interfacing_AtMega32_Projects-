################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
EXTI_TWO_LEDS.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: EXTI_TWO_LEDS.elf secondary-outputs

# Tool invocations
EXTI_TWO_LEDS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXTI_TWO_LEDS.map -mmcu=atmega32 -o "EXTI_TWO_LEDS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXTI_TWO_LEDS.lss: EXTI_TWO_LEDS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXTI_TWO_LEDS.elf  >"EXTI_TWO_LEDS.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXTI_TWO_LEDS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EXTI_TWO_LEDS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXTI_TWO_LEDS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
