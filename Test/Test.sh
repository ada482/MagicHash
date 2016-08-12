#!/bin/bash



	temp=0;
	awk -f "../MagicHashAwk.awk" "TestInput.txt" > "TestOutput.txt" || temp=1;
	cmp -s "MagicHashAwk.h" "TestHeaderComparison.txt" || temp=2;
	cmp -s "TestOutput.txt" "TestOutputComparison.txt" || temp=3;
	

exit $temp