# Multi-Level IR Framework

## Team Members:

1. 200010005 - Bhavesh Borse
2. 200010011 - Deepu Kumar
3. 200010016 - Eshita Pagare
4. 200010018 - Harrithha B
5. 200010020 - Ishika Sharma
6. 200010025 - Lokesh
7. 200010044 - Rahul Raj
8. 200010051 - Tarun Saini
9. 200010054 - Sahithy Tumma
10. 200010056 - Vidyasagar 

*The following has been tried on WSL-Ubuntu 20.04*

## Installation Steps
1. Copy paste the below code in a `runme.sh` file.
```
git clone --depth 1 https://github.com/llvm/llvm-project.git

mkdir llvm-project/build
cd llvm-project/build
cmake -G Ninja ../llvm \
   -DLLVM_ENABLE_PROJECTS=mlir \
   -DLLVM_BUILD_EXAMPLES=ON \
   -DLLVM_TARGETS_TO_BUILD="X86;NVPTX;AMDGPU" \
   -DCMAKE_BUILD_TYPE=Release \
   -DLLVM_ENABLE_ASSERTIONS=ON

cmake --build . --target check-mlir
```

2. Open a terminal in the directory which contains the above `runme.sh` and run the following:

```
chmod +x runme.sh
```

```
./runme.sh
```

## Tutorial Steps
1. The following commands were run for each chapter tutorial where we changed the already existing programs to test different scenarios
```
path_to_build/bin/toyc-ch1 test/Examples/Toy/Ch1/ast.toy -emit=ast
path_to_build/bin/toyc-ch2 test/Examples/Toy/Ch2/codegen.toy -emit=mlir
path_to_build/bin/toyc-ch3 test/Examples/Toy/Ch3/trivial_reshape.toy -emit=mlir -opt
path_to_build/bin/toyc-ch4 test/Examples/Toy/Ch4/codegen.toy -emit=mlir -opt
path_to_build/bin/toyc-ch5 test/Examples/Toy/Ch5/affine-lowering.mlir -emit=mlir-affine
path_to_build/bin/toyc-ch5 test/Examples/Toy/Ch5/affine-lowering.mlir -emit=mlir-affine -opt
echo 'def main() { print([[1, 2], [3, 4]]); }' | path_to_build/bin/toyc-ch6 -emit=jit
path_to_build/bin/toyc-ch7 test/Examples/Toy/Ch7/struct-codegen.toy -emit=mlir
```
