#makefile

GCC_TOOLCHAIN_DIR := /opt/RISCV/
GEM5_DIR ?= 

empty := 
comma := ,
space := $(empty) $(empty)

debug-flags ?= 
debugFlags := $(subst ${comma},${space}, ${debug-flags})
$(info ${debugFlags})

TEST_LENGTH ?= 1024

TESTS_SOURCES := $(wildcard src/tests/*.cpp)
TESTS_EXECUTABLE := $(addprefix exe/, $(notdir $(TESTS_SOURCES:.cpp=)))
TESTS_EXECUTABLE_O2 := $(addprefix exeO2/, $(notdir $(TESTS_SOURCES:.cpp=)))
TESTS_DUMP := $(addprefix dump/, $(notdir $(TESTS_SOURCES:.cpp=)))
TESTS_DUMP_O2 := $(addprefix dumpO2/, $(notdir $(TESTS_SOURCES:.cpp=)))

EXE_NAME ?= riscv-vector-tests

USER_DEFINES =
USER_DEFINES += -DTEST_LENGTH=${TEST_LENGTH}
USER_DEFINES += $(foreach var, ${debugFlags}, -Dshow_${var})

GCC := ${GCC_TOOLCHAIN_DIR}/bin/riscv64-unknown-linux-gnu-gcc
GXX := ${GCC_TOOLCHAIN_DIR}/bin/riscv64-unknown-linux-gnu-g++
GNU_OBJDUMP := ${GCC_TOOLCHAIN_DIR}/bin/riscv64-unknown-linux-gnu-objdump
GXX_FLAGS := -march=rv64gcv_zfh -flax-vector-conversions -static -g
gnu_dump_options ?= -d 

CLANG_DIR := /usr/local/
CLANG := ${CLANG_DIR}/bin/clang
CLANGXX := ${CLANG_DIR}/bin/clang++
CLANG_OBJDUMP := ${CLANG_DIR}/bin/llvm-objdump
CLANGXX_FLAGS := \
		--target=riscv64-unknown-linux-gnu -march=rv64gcv0p10 \
		-menable-experimental-extensions --gcc-toolchain=${GCC_TOOLCHAIN_DIR} \
		--sysroot=${GCC_TOOLCHAIN_DIR}/sysroot -flax-vector-conversions \
		-DUSE_RISCV_VECTOR -static -g
llvm_dump_options ?= --mattr=experimental-v
TOOLCHAIN ?= clang

ifeq (${TOOLCHAIN}, gnu)
	CC := ${GCC}
	CXX := ${GXX}
	CXX_FLAGS := ${GXX_FLAGS}
	OBJDUMP := ${GNU_OBJDUMP}
	OBJDUMP_OPTION := ${gnu_dump_options}
else ifeq ($(TOOLCHAIN), clang)
	CC := ${CLANG}
	CXX := ${CLANGXX}
	CXX_FLAGS := ${CLANGXX_FLAGS}
	OBJDUMP := ${CLANG_OBJDUMP}
	OBJDUMP_OPTION := ${llvm_dump_options}
endif

CXX_FLAGS += -std=c++17

start:
	if [ ! -d bin ]; then \
		mkdir bin; \
	else \
		echo bin dir exist; \
	fi

libutils.o : src/utils.cpp
	${CXX} -c ${USER_DEFINES} ${CXX_FLAGS} -o bin/$(notdir $@) $<

exe/% : src/tests/%.cpp libutils.o
	${CXX} -c ${USER_DEFINES} ${CXX_FLAGS} -o bin/$(notdir $@).o $<
	${CXX} ${CXX_FLAGS} -o bin/$(notdir $@) bin/$(notdir $@).o bin/libutils.o -lm

exeO2/% : CXX_FLAGS += -O2
exeO2/% : src/tests/%.cpp libutils.o
	${CXX} -c ${USER_DEFINES} ${CXX_FLAGS} -o bin/$(notdir $@)_O2.o $< 
	${CXX} ${CXX_FLAGS} -o bin/$(notdir $@)_O2 bin/$(notdir $@)_O2.o bin/libutils.o -lm

dump/% : exe/%
	${OBJDUMP} ${OBJDUMP_OPTION} -d bin/$(notdir $<).o > bin/$(notdir $@).dump

dumpO2/% : exeO2/%
	${OBJDUMP} ${OBJDUMP_OPTION} -d bin/$(notdir $<)_O2.o > bin/$(notdir $@)_O2.dump

# Just for bash auto complete
${TESTS_EXECUTABLE_O2} : 
${TESTS_EXECUTABLE} :
$(TESTS_DUMP_O2) :
$(TESTS_DUMP) :

all:
	@echo ${CXX}
	make start
	for entry in src/*.cpp ; do \
		${CXX} ${USER_DEFINES} ${CXX_FLAGS} -c -o $$entry.o $$entry; \
	done
	${CXX} ${CXX_FLAGS} -o bin/${EXE_NAME} src/*.cpp.o -lm;
	${OBJDUMP} ${OBJDUMP_OPTION} -d bin/${EXE_NAME} > bin/${EXE_NAME}.dump;
	rm src/*.o;

all_O2: CXX_FLAGS += -O2
all_O2: 
	@echo "CXX_FLAGS = " ${CXX_FLAGS}
	make start
	for entry in src/*.cpp ; do \
		${CXX} ${USER_DEFINES} ${CXX_FLAGS} -c -o $$entry.o $$entry; \
	done
	${CXX} ${CXX_FLAGS} -o bin/${EXE_NAME}_O2 src/*.cpp.o -lm;
	rm src/*.o

dump:
	-${OBJDUMP} ${OBJDUMP_OPTION} -d bin/${EXE_NAME} > bin/${EXE_NAME}.dump || \
	
dump_O2:
	-${OBJDUMP} ${OBJDUMP_OPTION} -d bin/${EXE_NAME}_O2 > bin/${EXE_NAME}_O2.dump;

clean:
	rm -rf bin/

# runqemu :
# 	${GCC_TOOLCHAIN_DIR}bin/qemu-riscv64 -cpu rv64,x-v=true bin/my_tests_vector 256

# runqemu_O2 :
# 	${GCC_TOOLCHAIN_DIR}bin/qemu-riscv64 -cpu rv64,x-v=true bin/my_tests_vector_O2 256

rungem5 :
	${GEM5_DIR}build/RISCV/gem5.opt ${GEM5_DIR}/configs/example/se.py --cmd="bin/${EXE_NAME}"

rungem5_O2 :
	${GEM5_DIR}build/RISCV/gem5.opt ${GEM5_DIR}/configs/example/se.py --cmd="bin/${EXE_NAME}_O2"
