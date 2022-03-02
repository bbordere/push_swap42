#!/bin/bash

for (( c=0; c<=500; c++ ))
do  
	python3 random_generator.py 500 && ARG="$(cat rstack.txt)" && ./push_swap $ARG | wc -l
	./push_swap $ARG | ./checker_linux $ARG
	./push_swap $ARG | ./checker $ARG
	
done