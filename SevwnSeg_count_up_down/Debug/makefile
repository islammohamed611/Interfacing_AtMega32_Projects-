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
SevwnSeg_count_up_down.lss \

FLASH_IMAGE += \
SevwnSeg_count_up_down.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SevwnSeg_count_up_down.elf secondary-outputs

# Tool invocations
SevwnSeg_count_up_down.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SevwnSeg_count_up_down.map -mmcu=atmega32 -o "SevwnSeg_count_up_down.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SevwnSeg_count_up_down.lss: SevwnSeg_count_up_down.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SevwnSeg_count_up_down.elf  >"SevwnSeg_count_up_down.lss"
	@echo 'Finished building: $@'
	@echo ' '

SevwnSeg_count_up_down.hex: SevwnSeg_count_up_down.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SevwnSeg_count_up_down.elf  "SevwnSeg_count_up_down.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SevwnSeg_count_up_down.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SevwnSeg_count_up_down.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SevwnSeg_count_up_down.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
