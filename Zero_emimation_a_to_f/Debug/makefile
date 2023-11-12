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
Zero_emimation_a_to_f.lss \

FLASH_IMAGE += \
Zero_emimation_a_to_f.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Zero_emimation_a_to_f.elf secondary-outputs

# Tool invocations
Zero_emimation_a_to_f.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Zero_emimation_a_to_f.map -mmcu=atmega32 -o "Zero_emimation_a_to_f.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Zero_emimation_a_to_f.lss: Zero_emimation_a_to_f.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Zero_emimation_a_to_f.elf  >"Zero_emimation_a_to_f.lss"
	@echo 'Finished building: $@'
	@echo ' '

Zero_emimation_a_to_f.hex: Zero_emimation_a_to_f.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Zero_emimation_a_to_f.elf  "Zero_emimation_a_to_f.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Zero_emimation_a_to_f.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Zero_emimation_a_to_f.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Zero_emimation_a_to_f.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
