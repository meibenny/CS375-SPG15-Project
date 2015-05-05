#! /bin/bash

echo Introsort
echo ./introsort tests/testfiles/2000000_random_false.txt out.txt
./introsort tests/testfiles/2000000_random_false.txt out.txt

echo ./introsort tests/testfiles/2000000_sorted_false.txt out.txt
./introsort tests/testfiles/2000000_sorted_false.txt out.txt

echo ./introsort tests/testfiles/2000000_r-sorted_false.txt out.txt
./introsort tests/testfiles/2000000_r-sorted_false.txt out.txt

echo ./introsort tests/testfiles/2000000_random_true.txt out.txt
./introsort tests/testfiles/2000000_random_true.txt out.txt

echo ./introsort tests/testfiles/2000000_sorted_true.txt out.txt
./introsort tests/testfiles/2000000_sorted_true.txt out.txt

echo ./introsort tests/testfiles/2000000_r-sorted_true.txt out.txt
./introsort tests/testfiles/2000000_r-sorted_true.txt out.txt




