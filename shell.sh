#! /bin/bash

#./generate_numbers 2000000 random false tests/testfiles/2000000_random_false.txt


echo "Quicksort Median"
echo ./quicksort_median tests/testfiles/65536_random_.txt median_65536_random_false_sorted.txt
./quicksort_median tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt
echo "Quicksort hoare"
echo ./quicksort_hoare tests/testfiles/65536_random_false.txt hoare_65536_random_false_sorted.txt
./quicksort_hoare tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt
echo "Quicksort lomuto"
echo ./quicksort_lomuto tests/testfiles/65536_random_false.txt lomuto_65536_random_false_sorted.txt
./quicksort_lomuto tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt
echo "Quicksort random"
echo ./quicksort_random tests/testfiles/65536_random_false.txt qsr_65536_random_false_sorted.txt
./quicksort_random tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt
echo "heapsort"
echo ./heapsort tests/testfiles/65536_random_false.txt heap_65536_random_false_sorted.txt
./heapsort tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt
echo "mergesort"
echo ./mergesort tests/testfiles/65536_random_false.txt merge_65536_random_false_sorted.txt
./mergesort tests/testfiles/65536_random_false.txt 65536_random_false_sorted.txt

