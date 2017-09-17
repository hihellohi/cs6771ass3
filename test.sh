#!/usr/bin/sh
for i in `seq $1`
do
	echo "=====running test $i====="
	g++ -std=c++14 -Wall -Werror -g -O2 -o test$i test$i.cpp
	./test$i | diff - result$i.txt
done
