#
# Build Macro
#
TARGET_ID = 8250
CHIP_ID = $(TARGET_ID)
VAR = AU

CPR_CFG_SCRIPT = $(WORKSPACE)/QcomPkg/Library/CPRLib/tools/cpr_cfg.py
CPR_CONFIG_DIR = $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Settings/CPR/$(VAR)
CPR_FUSES_DIR  = $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/target/$(TARGET_ID)

#=======================================================================
#Include the dependency file for DALConfig_<MACRO>.c file
#If any files #included by the DALConfig C file are changed,
#Then DALConfig_<MACRO>.obj/lib and the dependency file are rebuilt.
#======================================================================


OBJ =  \
    $(OUTPUT_DIR)/Library/CPRLib/common/hal/v3/src/cpr_hal.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_checksum.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_measurements.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_rail.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_smem.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_smem_vp.obj \
    $(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_utils.obj \
    $(OUTPUT_DIR)/Library/CPRLib/image/core/src/cpr_image.obj \
    $(OUTPUT_DIR)/Library/CPRLib/image/core/src/cpr_image_logs.obj \
    $(OUTPUT_DIR)/image/core/target/$(TARGET_ID)/cpr_image_target_init.obj \
    $(OUTPUT_DIR)/image/core/target/$(TARGET_ID)/cpr_image_target.obj


INC =  \
    -I$(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/target/$(TARGET_ID) \
    -I$(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/target/$(TARGET_ID)/hwio \
    -I$(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/image/core/target/$(TARGET_ID) \
    -I$(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Settings/CPR/$(VAR) \
    -I$(WORKSPACE)/QcomPkg/Library/CPRLib/image/core/inc \
    -I$(WORKSPACE)/QcomPkg/Library/CPRLib/common/inc \
    -I$(WORKSPACE)/QcomPkg/Library/CPRLib/common/hal/inc \
    -I$(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib \
    -I$(DEBUG_DIR) \
    -I$(WORKSPACE)/MdePkg \
    -I$(WORKSPACE)/MdePkg/Include \
    -I$(WORKSPACE)/MdePkg/Include/AArch64 \
    -I$(WORKSPACE)/MdeModulePkg \
    -I$(WORKSPACE)/MdeModulePkg/Include \
    -I$(WORKSPACE)/QcomPkg \
    -I$(WORKSPACE)/QcomPkg/Include \
    -I$(WORKSPACE)/QcomPkg/Include/Library \
    -I$(WORKSPACE)/QcomPkg/Include/api/dal \
    -I$(WORKSPACE)/QcomPkg/Include/api/kernel/SMMU \
    -I$(WORKSPACE)/QcomPkg/Library/MuslLib/musl/include \
    -I$(WORKSPACE)/QcomPkg/Library/MuslLib/musl/arch/arm \
    -I$(WORKSPACE)/EmbeddedPkg \
    -I$(WORKSPACE)/EmbeddedPkg/Include \
    -I$(WORKSPACE)/QcomPkg/Include/api/boot \
    -I$(WORKSPACE)/QcomPkg/Include/api/boot/qfprom \
    -I$(WORKSPACE)/QcomPkg/Include/api/systemdrivers \
    -I$(WORKSPACE)/QcomPkg/Include/api/pmic/pm \
    -I$(WORKSPACE)/QcomPkg/Include/api/buses \
    -I$(WORKSPACE)/QcomPkg/Include/api/securemsm/secboot \
    -I$(WORKSPACE)/QcomPkg/Include/api/securemsm/seccfg \
    -I$(WORKSPACE)/QcomPkg/Include/api/securemsm/secimgauth \
    -I$(WORKSPACE)/QcomPkg/Include/api/securemsm \
    -I$(WORKSPACE)/QcomPkg/Include/api/storage \
    -I$(WORKSPACE)/QcomPkg/Include/api/systemdebug \
    -I$(WORKSPACE)/QcomPkg/Include/api/wiredconnectivity \
    -I$(WORKSPACE)/QcomPkg/Include/api/services \
    -I$(WORKSPACE)/QcomPkg/Include/api/debugtools \
    -I$(WORKSPACE)/QcomPkg/Include/api/hwengines \
    -I$(WORKSPACE)/QcomPkg/Include/api/mproc \
    -I$(WORKSPACE)/QcomPkg/Include/api/kernel/libstd \
    -I$(WORKSPACE)/QcomPkg/Include/api/kernel/devcfg \
    -I$(WORKSPACE)/QcomPkg/Include/XBLLoader


#
# Default target, which will build dependent libraries in addition to source files
#
all: gen_libs $(OUTPUT_DIR)/CPRTargetLib.lib

#
# Phony target which is used to force executing commands for a target
#
force_build:
	-@

#
# Target to update the FD
#

fds: mbuild gen_fds

strdefs:
	-@$(CP) $(DEBUG_DIR)/AutoGen.h $(DEBUG_DIR)/$(MODULE_NAME)StrDefs.h

#
# GenLibsTarget
#
gen_libs:
	@cd $(MODULE_BUILD_DIR)

#
# Build Flash Device Image
#
gen_fds:
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)/Makefile fds
	@cd $(MODULE_BUILD_DIR)

#
# Individual Object Build Targets
#
$(OUTPUT_DIR)/CPRTargetLib.lib : $(OBJ)
	"$(SLINK)" -D -cr $@ $(SLINK_FLAGS) $(OBJ)

$(OUTPUT_DIR)/image/core/target/$(TARGET_ID)/cpr_image_target_init.obj : $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/image/core/target/$(TARGET_ID)/cpr_image_target_init.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/image/core/target/$(TARGET_ID)/cpr_image_target_init.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_smem.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_smem.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_smem.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_smem_vp.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_smem_vp.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_smem_vp.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_rail.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_rail.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_rail.c

$(OUTPUT_DIR)/Library/CPRLib/common/hal/v3/src/cpr_hal.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/hal/v3/src/cpr_hal.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/hal/v3/src/cpr_hal.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_checksum.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_checksum.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_checksum.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr.c

$(OUTPUT_DIR)/image/core/target/$(TARGET_ID)/cpr_image_target.obj : $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/image/core/target/$(TARGET_ID)/cpr_image_target_au.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/SocPkg/$(CHIP_ID)/Library/CPRTargetLib/image/core/target/$(TARGET_ID)/cpr_image_target_au.c

$(OUTPUT_DIR)/Library/CPRLib/image/core/src/cpr_image.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/image/core/src/cpr_image.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/image/core/src/cpr_image.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_measurements.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_measurements.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_measurements.c

$(OUTPUT_DIR)/Library/CPRLib/image/core/src/cpr_image_logs.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/image/core/src/cpr_image_logs.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/image/core/src/cpr_image_logs.c

$(OUTPUT_DIR)/Library/CPRLib/common/src/cpr_utils.obj : $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_utils.c
	"$(CC)" $(CC_FLAGS) -o $@ $(INC) $(WORKSPACE)/QcomPkg/Library/CPRLib/common/src/cpr_utils.c


#
# clean all intermediate files
#
clean:
	if exist $(OUTPUT_DIR) $(RD) $(OUTPUT_DIR)

#
# clean all generated files
#
cleanall:
	if exist $(DEBUG_DIR) $(RD) $(DEBUG_DIR)
	if exist $(OUTPUT_DIR) $(RD) $(OUTPUT_DIR)
	$(RM) *.pdb *.idb > NUL 2>&1
	$(RM) $(BIN_DIR)/$(MODULE_NAME).efi

#
# clean all dependent libraries built
#
cleanlib:
	@cd $(MODULE_BUILD_DIR)
