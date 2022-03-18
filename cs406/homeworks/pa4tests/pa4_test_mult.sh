#!/bin/bash
rm -rf inputs outputs
unzip inputs.zip
unzip outputs.zip
g++ -w tinyNew.C -o tiny
echo "[*] make compiler"
make compiler
if [ $? -ne 0 ]
then
	echo "Test failed. Error in building compiler. (-5)"
else
	bash runme ./inputs/test_mult.micro user_op.out
	./tiny user_op.out < test_mult.input | head -3 > prg_output.txt
	./tiny ./outputs/test_mult.out < test_mult.input |head -3 > exp_output.txt
	diff prg_output.txt exp_output.txt  
	if [ $? -ne 0 ]
	then  
		echo "Test failed. Incorrect output / output format for test_mult.out (-5)"
	else
		echo "Test passed."
	fi
fi
