#!/bin/tcsh
clear


./quicksort_lomuto tests/testfiles/128000_sorted_false.txt tests/results/128000_sorted_false_qsort_lomuto.txt
./quicksort_hoare tests/testfiles/128000_sorted_false.txt tests/results/128000_sorted_false_qsort_hoare.txt
./quicksort_random tests/testfiles/128000_sorted_false.txt tests/results/128000_sorted_false_qsort_random.txt
./mergesort tests/testfiles/128000_sorted_false.txt tests/results/128000_sorted_false_mergesort.txt
./heapsort tests/testfiles/128000_sorted_false.txt tests/results/128000_sorted_false_heapsort.txt




exit 0
