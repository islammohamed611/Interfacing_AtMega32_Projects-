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
ONE_click_ONE_count.lss \

FLASH_IMAGE += \
ONE_click_ONE_count.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ONE_click_ONE_count.elf secondary-outputs

# Tool invocations
ONE_click_ONE_count.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ONE_click_ONE_count.map -mmcu=atmega32 -o "ONE_click_ONE_count.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ONE_click_ONE_count.lss: ONE_click_ONE_count.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ONE_click_ONE_count.elf  >"ONE_click_ONE_count.lss"
	@echo 'Finished building: $@'
	@echo ' '

ONE_click_ONE_count.hex: ONE_click_ONE_count.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ONE_click_ONE_count.elf  "ONE_click_ONE_count.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ONE_click_ONE_count.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ONE_click_ONE_count.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ONE_click_ONE_count.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
