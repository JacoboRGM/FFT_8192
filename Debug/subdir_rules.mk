################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/jacobo.gonzalez/workspace_v10/dsp_FFT_radix2" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Include" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_TM4C129ENCPDT -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

uartstdio.obj: C:/ti/TivaWare_C_Series-2.1.2.111/utils/uartstdio.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/jacobo.gonzalez/workspace_v10/dsp_FFT_radix2" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Include" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111/utils" --include_path="C:/Users/jacobo.gonzalez/Downloads/CMSIS-master_4/CMSIS-master/CMSIS/Include" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=ARM_MATH_CM4 --define=__FPU_PRESENT=1 --define=PART_TM4C129ENCPDT -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


