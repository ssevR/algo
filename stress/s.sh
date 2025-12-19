#! /bin/bash

g++ sol.cpp -o sol || exit 1
g++ brute.cpp -o brute || exit 1
g++ gen.cpp -o gen || exit 1


for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > inp.txt
    # ./sol < inp.txt > out1
    # ./brute < inp.txt > out2
    # diff -w out1 out2 || break
    diff -w <(./sol < inp.txt) <(./brute < inp.txt) || break
done
