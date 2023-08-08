THISFILE1 = $(WORKSPACE)/QcomPkg/SocPkg/Settings/devcfg/devcfg_xblconfig_rules.mk

TOOLSDIR = $(CC:clang=)
LLVMLINK = $(TOOLSDIR)ld.qcld
OBJDUMP = $(TOOLSDIR)llvm-objdump
LLVMAR = $(TOOLSDIR)llvm-ar
ARMLINK = $(TOOLSDIR)arm-link

# \
TRIM = "$(WORKSPACE)/BaseTools/Bin/Win32/Trim"
# \
# \
!IF 0
  TRIM = python $(WORKSPACE)/BaseTools/Source/Python/Trim/Trim.py # \
!ENDIF

DEVCFG_DIR = $(WORKSPACE)/QcomPkg/SocPkg/8250/Settings/DALConfig
DEVCFG_XBLCONFIG_O = $(OUTPUT_DIR)/devcfg_xblconfig.o
DEVCFG_XBLCONFIG_C = $(OUTPUT_DIR)/devcfg_xblconfig.c
DEVCFG_DATA_XBLCONFIG_C = $(OUTPUT_DIR)/devcfg_data_xblconfig.c
DEVCFG_XBLCONFIG_XML = $(OUTPUT_DIR)/devcfg_xblconfig.xml
STRUCTPTR_XBLCONFIG_H = $(OUTPUT_DIR)/structptrs_xblconfig.h
DEVCFG_SCL = $(DEVCFG_DIR)/devcfg.scl
DEVCFG_LD = $(OUTPUT_DIR)/devcfg.ld
DEVCFG_LD_TEMP = $(OUTPUT_DIR)/devcfg_temp.ld
DEVCFG_C_DEFINES = -DDEVCFG__STRUCT_SIZE -DDEVCFG__PROPS_MEMORY_OPTIMISE -DDEVCFG_BOOT -DDEVCFG_XBLCONFIG
DEVCFG_ELF = $(OUTPUT_DIR)/devcfg_xblconfig.elf
DEVCFG_BIN = $(OUTPUT_DIR)/../../../../../../../../../devcfg_xblconfig.bin
DEVCFG_SCRIPTS = $(WORKSPACE)/QcomPkg/Tools/devcfg/scripts
DEVCFG_XBLCONFIG_OBJECTS = $(DEVCFG_XBLCONFIG_O)

ARCHLESS_CC_FLAGS = $(CC_FLAGS)

GLOBAL_XBLCONFIG_DEPS = $(THISFILE1) $(XML_XBLCONFIG_DEPS) $(INC_DEPS) $(IMAGE_CFG_XML) $(DEVCFG_SCRIPTS)/image_config.py $(DEVCFG_SCRIPTS)/propgen.py $(DEVCFG_SCRIPTS)/trim_bin.py $(CALLING_MAKE_FILE)

# \
XML_XBLCONFIG_INPUT_LIST = -i $(XML_XBLCONFIG_DEPS:  = -i )
# \
# \
!IF 0
  XML_XBLCONFIG_INPUT_LIST = $(addprefix -i ,$(XML_XBLCONFIG_DEPS)) # \
!ENDIF

#======================================================================
# Individual Object Build Targets
$(DEVCFG_BIN) : $(DEVCFG_ELF) $(GLOBAL_XBLCONFIG_DEPS)
	python $(DEVCFG_SCRIPTS)/trim_bin.py -i $(DEVCFG_ELF) -o $(DEVCFG_BIN) -s .devcfg_meta_data -e .devcfg_structures -d $(OBJDUMP)

$(DEVCFG_LD_TEMP) : $(DEVCFG_SCL) $(GLOBAL_XBLCONFIG_DEPS)
	"$(CC)" -E -x assembler-with-cpp -I$(WORKSPACE)/QcomPkg/SocPkg/Include $(DEVCFG_SCL) > $(DEVCFG_LD_TEMP)

$(DEVCFG_LD) : $(DEVCFG_LD_TEMP) $(GLOBAL_XBLCONFIG_DEPS)
	$(TRIM) --source-code -o $(DEVCFG_LD) $(DEVCFG_LD_TEMP)

$(DEVCFG_ELF) : $(DEVCFG_XBLCONFIG_O) $(DEVCFG_LD) $(GLOBAL_XBLCONFIG_DEPS)
	"$(ARMLINK)" -o $(DEVCFG_ELF) -Ttext=0x0 --emit-relocs -nostdlib --no-gc-sections -march=aarch64-none-linux-gnu -z common-page-size=0x1000 --start-group  $(DEVCFG_XBLCONFIG_O) --end-group -whole-archive --script=$(DEVCFG_LD) --entry=0x1e000000

$(DEVCFG_XBLCONFIG_O) : $(DEVCFG_XBLCONFIG_C) $(STRUCTPTR_XBLCONFIG_H) $(MAKE_FILE) $(COMMON_DEPS) $(GLOBAL_XBLCONFIG_DEPS)
	"$(CC)" $(ARCHLESS_CC_FLAGS) $(DEVCFG_C_DEFINES) -include $(STRUCTPTR_XBLCONFIG_H) -o $(DEVCFG_XBLCONFIG_O) $(INC) $(DEVCFG_XBLCONFIG_C)

$(DEVCFG_XBLCONFIG_C) : $(DEVCFG_XBLCONFIG_XML) $(GLOBAL_XBLCONFIG_DEPS)
	( python $(DEVCFG_SCRIPTS)/propgen.py -t $(DEVCFG_CONFIG) -i $(DEVCFG_XBLCONFIG_XML) -c $(DEVCFG_XBLCONFIG_C) -e $(DEVCFG_DATA_XBLCONFIG_C) -g $(IMAGE_CFG_XML) --fixed-addr=DEVCFG_DATA_SECTION_BASE )

$(DEVCFG_XBLCONFIG_XML) : $(GLOBAL_XBLCONFIG_DEPS)
	( python $(DEVCFG_SCRIPTS)/propgen.py -j $(DEVCFG_XBLCONFIG_XML) $(XML_XBLCONFIG_INPUT_LIST))

$(STRUCTPTR_XBLCONFIG_H) : $(DEVCFG_XBLCONFIG_XML) $(GLOBAL_XBLCONFIG_DEPS)
	( python $(DEVCFG_SCRIPTS)/propgen.py -t $(DEVCFG_CONFIG) -u $(STRUCTPTR_XBLCONFIG_H) -i $(DEVCFG_XBLCONFIG_XML) -g $(IMAGE_CFG_XML) )

# List all targets as dependencies the the psuedo target to force rebuild of everything
all: $(DEVCFG_BIN) $(DEVCFG_ELF) $(DEVCFG_XBLCONFIG_O) $(DEVCFG_XBLCONFIG_C) $(DEVCFG_XBLCONFIG_XML) $(STRUCTPTR_XBLCONFIG_H)

#
# Build Flash Device Image
#
gen_fds:
	@"$(MAKE)" $(MAKE_FLAGS) -f $(BUILD_DIR)\Makefile fds
	@cd $(MODULE_BUILD_DIR)

#
# Target to update the FD
#
fds: mbuild gen_fds


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
	$(RM) $(BIN_DIR)\$(MODULE_NAME).efi

#
# clean all dependent libraries built
#
cleanlib:
	@cd $(MODULE_BUILD_DIR)
