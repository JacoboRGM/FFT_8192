################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c129encpdt_startup_ccs.obj" \
"./uartstdio.obj" \
"./lib_dsp/bit_reversal.obj" \
"./lib_dsp/complex_typedefs.obj" \
"./lib_dsp/fft_dif.obj" \
"./lib_dsp/signals.obj" \
"./lib_dsp/twiddleFactor.obj" \
"./mydevices/mydevices.obj" \
"C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Lib/ARM/arm_cortexM4lf_math.lib" \
"C:/ti/TivaWare_C_Series-2.1.2.111/driverlib/ccs/Debug/driverlib.lib" \
"../tm4c129encpdt.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Lib/ARM/arm_cortexM4lf_math.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include lib_dsp/subdir_vars.mk
-include mydevices/subdir_vars.mk
-include subdir_rules.mk
-include lib_dsp/subdir_rules.mk
-include mydevices/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
dsp_FFT_radix2.out \

EXE_OUTPUTS__QUOTED += \
"dsp_FFT_radix2.out" \

BIN_OUTPUTS += \
dsp_FFT_radix2.hex \

BIN_OUTPUTS__QUOTED += \
"dsp_FFT_radix2.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "dsp_FFT_radix2.out"

# Tool invocations
dsp_FFT_radix2.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_TM4C129ENCPDT -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"dsp_FFT_radix2.map" --heap_size=0x900 --stack_size=1024 -i"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="dsp_FFT_radix2_linkInfo.xml" --rom_model -o "dsp_FFT_radix2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

dsp_FFT_radix2.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armhex" --diag_wrap=off -o "dsp_FFT_radix2.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c129encpdt_startup_ccs.obj" "uartstdio.obj" "lib_dsp\bit_reversal.obj" "lib_dsp\complex_typedefs.obj" "lib_dsp\fft_dif.obj" "lib_dsp\signals.obj" "lib_dsp\twiddleFactor.obj" "mydevices\mydevices.obj" 
	-$(RM) "main.d" "tm4c129encpdt_startup_ccs.d" "uartstdio.d" "lib_dsp\bit_reversal.d" "lib_dsp\complex_typedefs.d" "lib_dsp\fft_dif.d" "lib_dsp\signals.d" "lib_dsp\twiddleFactor.d" "mydevices\mydevices.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

