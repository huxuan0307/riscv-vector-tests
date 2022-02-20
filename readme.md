## Overview

Instruction tests for risc-v vector extension

## Usage

```bash
make all    # build by clang
make all_O2 # with -O2 flag
make all_O2 GCC_TOOLCHAIN_DIR=${GCC_TOOLCHAIN_DIR} # specify the directories of toolchains
make all_O2 TEST_LENGTH=1023 # specify test array length(default 1024)
make all_O2 debug-flags=details,perfermance,origin # add debug flags
make all_O2 TOOLCHAIN=gnu # cannot build, need fix
```

### Build llvm correctly

To make clang work well, here is a reference step by step guide on how to compile the llvm.

```
git clone https://github.com/llvm/llvm-project.git
git reset --hard 7e679f88ac2e51b02e33f4d93208c7ccd5579ca1
mkdir llvm-project/build && cd llvm-project/build
cmake -DLLVM_TARGETS_TO_BUILD="X86;RISCV" -DLLVM_ENABLE_PROJECTS="clang" -DCMAKE_BUILD_TYPE=RELEASE -G Ninja ../llvm
ninja
ln -s ~/llvm-project/build /opt/rvv-llvm #optional
```

### Debug flags

+ details : show detail steps in tests
+ perfermance : show time of steps in tests
+ origin : print origin initialized data

