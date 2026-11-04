# Copyright 2026 OXlatorty
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CC := clang
ARCH_FLAGS := -m32
FREESTANDING_FLAGS := -ffreestanding -fno-builtin -fno-stack-protector -fno-pic -fno-pie -fno-unwind-tables -fno-asynchronous-unwind-tables
DFLAGS := -DOX_CRT_POSIX_X86
CFLAGS := $(ARCH_FLAGS) $(FREESTANDING_FLAGS) $(DFLAGS) -Os -Wall -Werror -MMD -MP

SRC_SUFFIX := posix.x86
OBJ_DIR = obj

# Format: name : type : dep(s) (|) : flag(s) (|)
#
#   name   module path relative to the project root
#
#   type   o      - object file built from <name>/src/<basename>.<SRC_SUFFIX>.c
#                   into obj/<basename>.o
#          header - header-only module: no sources, no target; every module that
#                   lists it in deps only gets -I<name>/include
#
#   deps   names of other MODULES entries, separated by '|'
#
#   flags  extra compiler flags, separated by '|'
#
# Empty fields are allowed, e.g. "name:header::".
# Dependencies are NOT transitive: list every module whose headers you include.
MODULES := \
	ox-crt-defines:header:: \
	ox-crt-syscall:o:ox-crt-defines: \
	ox-crt-start:o:ox-crt-defines|ox-crt-syscall:

mod_field = $(patsubst @%,%,$(word $(2),$(subst :, @,@$(1))))

O_MODULES :=
HEADER_MODULES :=

$(foreach mod,$(MODULES), \
	$(eval name := $(strip $(call mod_field,$(mod),1))) \
	$(eval type := $(strip $(call mod_field,$(mod),2))) \
	$(if $(filter o header,$(type)),,$(error Invalid module type "$(type)" for $(name) - expected: o or header)) \
	$(if $(filter o,$(type)),$(eval O_MODULES += $(name))) \
	$(if $(filter header,$(type)),$(eval HEADER_MODULES += $(name))) \
)

ALL_TARGETS :=

define GENERATE_RULES

INC_DIR_$(1) := $(1)/include

DEPS_$(1) := $$(subst |, ,$(3))
O_DEPS_$(1) := $$(filter $$(O_MODULES),$$(DEPS_$(1)))
HDR_DEPS_$(1) := $$(filter $$(HEADER_MODULES),$$(DEPS_$(1)))
FLAGS_CLEAN_$(1) := $$(subst |, ,$(4))

C_FLAGS_$(1) := $(CFLAGS) -I$$(INC_DIR_$(1)) \
	$$(foreach dep,$$(O_DEPS_$(1)) $$(HDR_DEPS_$(1)),-I$$(dep)/include) \
	$$(FLAGS_CLEAN_$(1))

SRC_$(1) := $$(wildcard $(1)/src/$$(notdir $(1)).$(SRC_SUFFIX).c)
TARGET_$(1) := $(OBJ_DIR)/$$(notdir $(1)).o

ALL_TARGETS += $$(TARGET_$(1))
$$(TARGET_$(1)): $$(SRC_$(1)) | $(OBJ_DIR)
	@if [ -z "$$(SRC_$(1))" ]; then echo "Source $(1)/src/$$(notdir $(1)).$(SRC_SUFFIX).c not found for $(1)"; exit 1; fi
	@echo "[CC] $$< -> $$@"
	$(CC) $$(C_FLAGS_$(1)) -c $$< -o $$@

endef

$(foreach mod,$(MODULES), \
	$(eval name := $(strip $(call mod_field,$(mod),1))) \
	$(eval type := $(strip $(call mod_field,$(mod),2))) \
	$(eval deps := $(strip $(call mod_field,$(mod),3))) \
	$(eval flags := $(strip $(call mod_field,$(mod),4))) \
	$(eval unknown := $(filter-out $(O_MODULES) $(HEADER_MODULES),$(subst |, ,$(deps)))) \
	$(if $(unknown),$(error Module $(name) depends on unregistered module(s): $(unknown))) \
	$(if $(filter o,$(type)),$(eval $(call GENERATE_RULES,$(name),$(type),$(deps),$(flags)))) \
)

.DEFAULT_GOAL := all
.PHONY: all clean debug

all: $(ALL_TARGETS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

debug:
	@echo "Found targets: $(ALL_TARGETS)"
	@echo "Modules: $(MODULES)"
	@echo "Object modules: $(O_MODULES)"
	@echo "Header-only modules: $(HEADER_MODULES)"

-include $(ALL_TARGETS:.o=.d)
