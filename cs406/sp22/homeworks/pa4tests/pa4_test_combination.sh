#!/bin/bash
unzip inputs.zip
g++ -w tinyNew.C -o tiny
echo "[*] make compiler"
make compiler
if [ $? -ne 0 ]
then
	echo "Test failed. Error in building compiler. (-5)"
else
	#echo "[*] ./runme test_combination.micro user_op.out"
	bash runme inputs/test_combination.micro user_op.out
	#echo "[*] ./tiny user_op.out"
	str=`./tiny user_op.out`
	echo $str | grep -q "692920920"  
	if [ $? -ne 0 ]
	then  
		echo "Test failed. Incorrect output / output format for test_combination.out (-5)"
	else
		echo "Test passed."
	fi
fi
