#!/bin/bash

for (( c=0; c<=50; c++ ))
do  
	python3 random_generator.py 500 && ARG="$(cat rstack.txt)" #&& ./push_swap $ARG | wc -l
	./push_swap $ARG | ./checker_linux $ARG
done