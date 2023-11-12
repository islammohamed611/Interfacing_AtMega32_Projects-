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
Shifting_right.lss \

FLASH_IMAGE += \
Shifting_right.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Shifting_right.elf secondary-outputs

# Tool invocations
Shifting_right.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Shifting_right.map -mmcu=atmega32 -o "Shifting_right.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Shifting_right.lss: Shifting_right.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Shifting_right.elf  >"Shifting_right.lss"
	@echo 'Finished building: $@'
	@echo ' '

Shifting_right.hex: Shifting_right.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Shifting_right.elf  "Shifting_right.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Shifting_right.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Shifting_right.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Shifting_right.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
