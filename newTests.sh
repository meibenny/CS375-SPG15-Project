#! /bin/bash

#./generate_numbers 2000000 random true tests/testfiles/2000000_random_true.txt


#echo "Quicksort Median"
#./quicksort_median tests/testfiles/2000000_r-random_true.txt out.txt
echo "Quicksort hoare"
./quicksort_hoare tests/testfiles/2000000_random_true.txt out.txt
#echo "Quicksort lomuto"
#./quicksort_lomuto tests/testfiles/2000000_random_true.txt out.txt
#echo "Quicksort random"
#./quicksort_random tests/testfiles/2000000_r-random_true.txt out.txt
echo "heapsort"
./heapsort tests/testfiles/2000000_random_true.txt out.txt
echo "mergesort"
./mergesort tests/testfiles/2000000_random_true.txt out.txt





