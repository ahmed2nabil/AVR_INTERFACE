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
mychallenge.lss \

FLASH_IMAGE += \
mychallenge.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: mychallenge.elf secondary-outputs

# Tool invocations
mychallenge.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mychallenge.map -mmcu=atmega16 -o "mychallenge.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mychallenge.lss: mychallenge.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mychallenge.elf  >"mychallenge.lss"
	@echo 'Finished building: $@'
	@echo ' '

mychallenge.hex: mychallenge.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex mychallenge.elf  "mychallenge.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mychallenge.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 mychallenge.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) mychallenge.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
