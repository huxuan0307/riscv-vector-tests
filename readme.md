## Overview

Instruction tests for risc-v vector extension

## Usage

```bash
make all    # build by gcc-toolchain
make all_O2 # with -O2 flag
make all_O2 GCC_TOOLCHAIN_DIR=${GCC_TOOLCHAIN_DIR} # specify the directories of toolchains
make all_O2 TOOLCHAIN=clang # cannot build, need fix
```

