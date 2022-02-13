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

### Debug flags

+ details : show detail steps in tests
+ perfermance : show time of steps in tests
+ origin : print origin initialized data
