# SPDX-License-Identifier: Apache-2.0
# Copyright 2020 Western Digital Corporation or its affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

RESET_VECTOR ?= 0
FLASH_ADDR ?= 0x0

TEST_CFLAGS = -g -O3 -funroll-all-loops
ABI = -mabi=ilp32 -march=rv32imac

# Allow tool override
GCC_PREFIX = riscv64-unknown-elf
TBDIR = ./tests
BUILD_DIR = .

# Define test name
TEST = hello_world

# Define test name
ifneq (,$(wildcard $(TBDIR)/$(TEST)))
	TEST_DIR = $(TBDIR)/$(TEST)
endif

BSP_DIR = ${BUILD_DIR}/bsp
BSP_FILES = $(BSP_DIR)/src/swervolf_print.o
OFILES = $(TEST).o 
HFILES = $(BSP_DIR)/inc/

# provide specific link file
ifeq (,$(wildcard $(TEST_DIR)/$(TEST).ld))
	LINK = $(BUILD_DIR)/link.ld
else
	LINK = $(TEST_DIR)/$(TEST).ld
endif

VPATH = $(TEST_DIR) $(BUILD_DIR) $(TBDIR)

-include $(TEST_DIR)/$(TEST).mki

IMAGE = $(TEST).ub

# Targets
all: clean test

clean:
	rm -rf *.o *.dump *.elf *.cpp.s $(BSP_FILES) *.bin *.ub *.ubvh

program:
	openocd -c "set BINFILE $(IMAGE)" -f ./swervolf_nexys_write_flash.cfg

test: $(TEST).elf $(TEST).bin $(TEST).ub $(TEST).ubvh
############ TEST build ###############################

$(TEST).bin: $(TEST).elf
	$(GCC_PREFIX)-objcopy -O binary $(TEST).elf $(TEST).bin
	@echo Generating binary file
    
$(TEST).elf: $(BSP_FILES) $(OFILES) $(LINK)
	@echo Building $(TEST)
	$(GCC_PREFIX)-gcc -Wl,-m,elf32lriscv -Wl,--discard-none -T$(LINK) -o $(TEST).elf $(OFILES) $(BSP_FILES) -nostartfiles -nostdlib $(TEST_LIBS)
	$(GCC_PREFIX)-objdump -d  $(TEST).elf > $(TEST).dump
	@echo Completed building $(TEST)

%.ub: %.bin
	mkimage \
	-A riscv \
	-C none \
	-T standalone \
	-a 0x0 \
	-e $(RESET_VECTOR) \
	-n '$@' \
	-d $< \
	$@

%.ubvh: %.ub
	objcopy --change-addresses $(FLASH_ADDR) -I binary -O verilog $< $@

%.o : %.s 
	$(GCC_PREFIX)-cpp -I${HFILES}  $<  > $*.cpp.s
	$(GCC_PREFIX)-as ${ABI} $*.cpp.s -o $@


%.o : %.c 
	$(GCC_PREFIX)-gcc ${TEST_CFLAGS} -DCOMPILER_FLAGS="\"${TEST_CFLAGS}\"" ${ABI} -nostdlib -I${HFILES} -c $< -o $@


help:
	@echo Possible targets: test clean

.PHONY: help clean test

