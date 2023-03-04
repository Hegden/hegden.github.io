#!/bin/bash
rm -rf inputs outputs
unzip inputs.zip
unzip outputs.zip
g++ -w tinyNew.cpp -o tiny
echo "[*] make compiler"
make compiler
if [ $? -ne 0 ]
then
	echo "Test failed. Error in building compiler. (-5)"
else
	bash runme ./inputs/test_complex.micro user_op.out
	./tiny user_op.out | head -4 > prg_output.txt
	./tiny ./outputs/test_complex.out |head -4 > exp_output.txt
	diff prg_output.txt exp_output.txt  
	if [ $? -ne 0 ]
	then  
		echo "Test failed. Incorrect output / output format for test_complex.out (-5)"
	else
		echo "Test passed."
	fi
fi
