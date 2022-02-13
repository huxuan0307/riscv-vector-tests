#makefile

GCC_TOOLCHAIN_DIR := /opt/RISCV/
GEM5_DIR ?= 

USER_DEFINES ?= 

EXE_NAME ?= riscv-vector-tests

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
	@ ${OBJDUMP} ${OBJDUMP_OPTION} -d bin/${EXE_NAME} > bin/${EXE_NAME}.dump;
	@ ${OBJDUMP} ${OBJDUMP_OPTION} -d bin/${EXE_NAME}_O2 > bin/${EXE_NAME}_O2.dump;

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
