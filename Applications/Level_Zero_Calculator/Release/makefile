################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include APP/subdir.mk
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
Level_Zero_Calculator.lss \

FLASH_IMAGE += \
Level_Zero_Calculator.hex \

EEPROM_IMAGE += \
Level_Zero_Calculator.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Level_Zero_Calculator.elf secondary-outputs

# Tool invocations
Level_Zero_Calculator.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Level_Zero_Calculator.map -mmcu=atmega32 -o "Level_Zero_Calculator.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Level_Zero_Calculator.lss: Level_Zero_Calculator.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Level_Zero_Calculator.elf  >"Level_Zero_Calculator.lss"
	@echo 'Finished building: $@'
	@echo ' '

Level_Zero_Calculator.hex: Level_Zero_Calculator.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Level_Zero_Calculator.elf  "Level_Zero_Calculator.hex"
	@echo 'Finished building: $@'
	@echo ' '

Level_Zero_Calculator.eep: Level_Zero_Calculator.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Level_Zero_Calculator.elf  "Level_Zero_Calculator.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Level_Zero_Calculator.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Level_Zero_Calculator.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Level_Zero_Calculator.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
