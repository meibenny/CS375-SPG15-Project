COMPILER = g++
CXXFLAGS = -g -Wall -std=c++0x

#we use GENERATE_NUMBERS to generate input for the experiment
GENERATE_NUMBERS = generate_numbers
#we use SORT to sort the input to ensure correctness of our program
SORT = sort
QSORT_LOMUTO = quicksort_lomuto
QSORT_HOARE = quicksort_hoare
QSORT_RANDOM = quicksort_random
AUX_FUNCTIONS = auxiliary_functions.cpp
MERGE_SORT = mergesort
HEAP_SORT = heapsort

TIMER = timer.cpp

all: $(GENERATE_NUMBERS) $(SORT) $(QSORT_LOMUTO) $(QSORT_HOARE) $(QSORT_RANDOM) $(MERGE_SORT) $(HEAP_SORT) $(TIMER)

$(HEAP_SORT): heapsort.cpp $(AUX_FUNCTIONS)
	$(COMPILER) $(CXXFLAGS) -o $(HEAP_SORT) heapsort.cpp

$(MERGE_SORT): mergesort.cpp $(AUX_FUNCTIONS) 
	$(COMPILER) $(CXXFLAGS) -o $(MERGE_SORT) mergesort.cpp

$(QSORT_RANDOM): quicksort_random.cpp $(AUX_FUNCTIONS)
	$(COMPILER) $(CXXFLAGS) -o $(QSORT_RANDOM) quicksort_random.cpp

$(QSORT_HOARE): quicksort_hoare.cpp $(AUX_FUNCTIONS)
	$(COMPILER) $(CXXFLAGS) -o $(QSORT_HOARE) quicksort_hoare.cpp

$(QSORT_LOMUTO): quicksort_lomuto.cpp $(AUX_FUNCTIONS)
	$(COMPILER) $(CXXFLAGS) -o $(QSORT_LOMUTO) quicksort_lomuto.cpp

$(SORT): sort.cpp $(AUX_FUNCTIONS)
	$(COMPILER) $(CXXFLAGS) -o $(SORT) sort.cpp

$(GENERATE_NUMBERS): generate_numbers.cpp
	$(COMPILER) $(CXXFLAGS) -o $(GENERATE_NUMBERS) generate_numbers.cpp 


clean:
	rm -f *.o $(GENERATE_NUMBERS) $(SORT) $(QSORT_LOMUTO) $(QSORT_HOARE) $(QSORT_RANDOM) $(MERGE_SORT) $(HEAP_SORT)

generate-no-dup:
	./generate_numbers 1 sorted false tests/testfiles/1_sorted_false.txt
	./generate_numbers 2 sorted false tests/testfiles/2_sorted_false.txt
	./generate_numbers 16 sorted false tests/testfiles/16_sorted_false.txt
	./generate_numbers 32 sorted false tests/testfiles/32_sorted_false.txt
	./generate_numbers 128 sorted false tests/testfiles/128_sorted_false.txt
	./generate_numbers 512 sorted false tests/testfiles/512_sorted_false.txt
	./generate_numbers 1024 sorted false tests/testfiles/1024_sorted_false.txt
	./generate_numbers 4096 sorted false tests/testfiles/4096_sorted_false.txt
	./generate_numbers 16348 sorted false tests/testfiles/16348_sorted_false.txt
	./generate_numbers 65536 sorted false tests/testfiles/65536_sorted_false.txt
	./generate_numbers 524288 sorted false tests/testfiles/524288_sorted_false.txt
	./generate_numbers 1000000 sorted false tests/testfiles/100000_sorted_false.txt
	./generate_numbers 1 r_sorted false tests/testfiles/1_r-sorted_false.txt
	./generate_numbers 2 r_sorted false tests/testfiles/2_r-sorted_false.txt
	./generate_numbers 16 r_sorted false tests/testfiles/16_r-sorted_false.txt
	./generate_numbers 32 r_sorted false tests/testfiles/32_r-sorted_false.txt
	./generate_numbers 128 r_sorted false tests/testfiles/128_r-sorted_false.txt
	./generate_numbers 512 r_sorted false tests/testfiles/512_r-sorted_false.txt
	./generate_numbers 1024 r_sorted false tests/testfiles/1024_r-sorted_false.txt
	./generate_numbers 4096 r_sorted false tests/testfiles/4096_r-sorted_false.txt
	./generate_numbers 16348 r_sorted false tests/testfiles/16348_r-sorted_false.txt
	./generate_numbers 65536 r_sorted false tests/testfiles/65536_r-sorted_false.txt
	./generate_numbers 524288 r_sorted false tests/testfiles/524288_r-sorted_false.txt
	./generate_numbers 1000000 r_sorted false tests/testfiles/100000_r-sorted_false.txt
	./generate_numbers 1 random false tests/testfiles/1_random_false.txt
	./generate_numbers 2 random false tests/testfiles/2_random_false.txt
	./generate_numbers 16 random false tests/testfiles/16_random_false.txt
	./generate_numbers 32 random false tests/testfiles/32_random_false.txt
	./generate_numbers 128 random false tests/testfiles/128_random_false.txt
	./generate_numbers 512 random false tests/testfiles/512_random_false.txt
	./generate_numbers 1024 random false tests/testfiles/1024_random_false.txt
	./generate_numbers 4096 random false tests/testfiles/4096_random_false.txt
	./generate_numbers 16348 random false tests/testfiles/16348_random_false.txt
	./generate_numbers 65536 random false tests/testfiles/65536_random_false.txt
	./generate_numbers 524288 random false tests/testfiles/524288_random_false.txt
	./generate_numbers 1000000 random false tests/testfiles/100000_random_false.txt

generate-dup:
	./generate_numbers 1 sorted true tests/testfiles/1_sorted_true.txt
	./generate_numbers 2 sorted true tests/testfiles/2_sorted_true.txt
	./generate_numbers 16 sorted true tests/testfiles/16_sorted_true.txt
	./generate_numbers 32 sorted true tests/testfiles/32_sorted_true.txt
	./generate_numbers 128 sorted true tests/testfiles/128_sorted_true.txt
	./generate_numbers 512 sorted true tests/testfiles/512_sorted_true.txt
	./generate_numbers 1024 sorted true tests/testfiles/1024_sorted_true.txt
	./generate_numbers 4096 sorted true tests/testfiles/4096_sorted_true.txt
	./generate_numbers 16348 sorted true tests/testfiles/16348_sorted_true.txt
	./generate_numbers 65536 sorted true tests/testfiles/65536_sorted_true.txt
	./generate_numbers 524288 sorted true tests/testfiles/524288_sorted_true.txt
	./generate_numbers 1000000 sorted true tests/testfiles/100000_sorted_true.txt
	./generate_numbers 1 r_sorted true tests/testfiles/1_r-sorted_true.txt
	./generate_numbers 2 r_sorted true tests/testfiles/2_r-sorted_true.txt
	./generate_numbers 16 r_sorted true tests/testfiles/16_r-sorted_true.txt
	./generate_numbers 32 r_sorted true tests/testfiles/32_r-sorted_true.txt
	./generate_numbers 128 r_sorted true tests/testfiles/128_r-sorted_true.txt
	./generate_numbers 512 r_sorted true tests/testfiles/512_r-sorted_true.txt
	./generate_numbers 1024 r_sorted true tests/testfiles/1024_r-sorted_true.txt
	./generate_numbers 4096 r_sorted true tests/testfiles/4096_r-sorted_true.txt
	./generate_numbers 16348 r_sorted true tests/testfiles/16348_r-sorted_true.txt
	./generate_numbers 65536 r_sorted true tests/testfiles/65536_r-sorted_true.txt
	./generate_numbers 524288 r_sorted true tests/testfiles/524288_r-sorted_true.txt
	./generate_numbers 1000000 r_sorted true tests/testfiles/100000_r-sorted_true.txt
	./generate_numbers 1 random true tests/testfiles/1_random_true.txt
	./generate_numbers 2 random true tests/testfiles/2_random_true.txt
	./generate_numbers 16 random true tests/testfiles/16_random_true.txt
	./generate_numbers 32 random true tests/testfiles/32_random_true.txt
	./generate_numbers 128 random true tests/testfiles/128_random_true.txt
	./generate_numbers 512 random true tests/testfiles/512_random_true.txt
	./generate_numbers 1024 random true tests/testfiles/1024_random_true.txt
	./generate_numbers 4096 random true tests/testfiles/4096_random_true.txt
	./generate_numbers 16348 random true tests/testfiles/16348_random_true.txt
	./generate_numbers 65536 random true tests/testfiles/65536_random_true.txt
	./generate_numbers 524288 random true tests/testfiles/524288_random_true.txt
	./generate_numbers 1000000 random true tests/testfiles/100000_random_true.txt

test-no-dup-sorted:
	./quicksort_lomuto tests/testfiles/1_sorted_false.txt tests/results/1_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1_sorted_false.txt tests/results/1_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1_sorted_false.txt tests/results/1_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1_sorted_false.txt tests/results/1_sorted_false_mergesort.txt
	./heapsort tests/testfiles/1_sorted_false.txt tests/results/1_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/2_sorted_false.txt tests/results/2_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/2_sorted_false.txt tests/results/2_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/2_sorted_false.txt tests/results/2_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/2_sorted_false.txt tests/results/2_sorted_false_mergesort.txt
	./heapsort tests/testfiles/2_sorted_false.txt tests/results/2_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16_sorted_false.txt tests/results/16_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16_sorted_false.txt tests/results/16_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16_sorted_false.txt tests/results/16_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/16_sorted_false.txt tests/results/16_sorted_false_mergesort.txt
	./heapsort tests/testfiles/16_sorted_false.txt tests/results/16_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/32_sorted_false.txt tests/results/32_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/32_sorted_false.txt tests/results/32_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/32_sorted_false.txt tests/results/32_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/32_sorted_false.txt tests/results/32_sorted_false_mergesort.txt
	./heapsort tests/testfiles/32_sorted_false.txt tests/results/32_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/128_sorted_false.txt tests/results/128_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/128_sorted_false.txt tests/results/128_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/128_sorted_false.txt tests/results/128_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/128_sorted_false.txt tests/results/128_sorted_false_mergesort.txt
	./heapsort tests/testfiles/128_sorted_false.txt tests/results/128_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/512_sorted_false.txt tests/results/512_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/512_sorted_false.txt tests/results/512_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/512_sorted_false.txt tests/results/512_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/512_sorted_false.txt tests/results/512_sorted_false_mergesort.txt
	./heapsort tests/testfiles/512_sorted_false.txt tests/results/512_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1024_sorted_false.txt tests/results/1024_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1024_sorted_false.txt tests/results/1024_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1024_sorted_false.txt tests/results/1024_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1024_sorted_false.txt tests/results/1024_sorted_false_mergesort.txt
	./heapsort tests/testfiles/1024_sorted_false.txt tests/results/1024_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/4096_sorted_false.txt tests/results/4096_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/4096_sorted_false.txt tests/results/4096_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/4096_sorted_false.txt tests/results/4096_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/4096_sorted_false.txt tests/results/4096_sorted_false_mergesort.txt
	./heapsort tests/testfiles/4096_sorted_false.txt tests/results/4096_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16348_sorted_false.txt tests/results/16348_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16348_sorted_false.txt tests/results/16348_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16348_sorted_false.txt tests/results/16348_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/16348_sorted_false.txt tests/results/16348_sorted_false_mergesort.txt
	./heapsort tests/testfiles/16348_sorted_false.txt tests/results/16348_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/65536_sorted_false.txt tests/results/65536_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/65536_sorted_false.txt tests/results/65536_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/65536_sorted_false.txt tests/results/65536_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/65536_sorted_false.txt tests/results/65536_sorted_false_mergesort.txt
	./heapsort tests/testfiles/65536_sorted_false.txt tests/results/65536_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/524288_sorted_false.txt tests/results/524288_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/524288_sorted_false.txt tests/results/524288_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/524288_sorted_false.txt tests/results/524288_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/524288_sorted_false.txt tests/results/524288_sorted_false_mergesort.txt
	./heapsort tests/testfiles/524288_sorted_false.txt tests/results/524288_sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1000000_sorted_false.txt tests/results/1000000_sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1000000_sorted_false.txt tests/results/1000000_sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1000000_sorted_false.txt tests/results/1000000_sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1000000_sorted_false.txt tests/results/1000000_sorted_false_mergesort.txt
	./heapsort tests/testfiles/1000000_sorted_false.txt tests/results/1000000_sorted_false_heapsort.txt

test-no-dup-r-sorted:
	./quicksort_lomuto tests/testfiles/1_r-sorted_false.txt tests/results/1_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1_r-sorted_false.txt tests/results/1_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1_r-sorted_false.txt tests/results/1_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1_r-sorted_false.txt tests/results/1_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/1_r-sorted_false.txt tests/results/1_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/2_r-sorted_false.txt tests/results/2_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/2_r-sorted_false.txt tests/results/2_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/2_r-sorted_false.txt tests/results/2_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/2_r-sorted_false.txt tests/results/2_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/2_r-sorted_false.txt tests/results/2_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16_r-sorted_false.txt tests/results/16_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16_r-sorted_false.txt tests/results/16_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16_r-sorted_false.txt tests/results/16_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/16_r-sorted_false.txt tests/results/16_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/16_r-sorted_false.txt tests/results/16_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/32_r-sorted_false.txt tests/results/32_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/32_r-sorted_false.txt tests/results/32_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/32_r-sorted_false.txt tests/results/32_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/32_r-sorted_false.txt tests/results/32_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/32_r-sorted_false.txt tests/results/32_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/128_r-sorted_false.txt tests/results/128_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/128_r-sorted_false.txt tests/results/128_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/128_r-sorted_false.txt tests/results/128_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/128_r-sorted_false.txt tests/results/128_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/128_r-sorted_false.txt tests/results/128_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/512_r-sorted_false.txt tests/results/512_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/512_r-sorted_false.txt tests/results/512_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/512_r-sorted_false.txt tests/results/512_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/512_r-sorted_false.txt tests/results/512_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/512_r-sorted_false.txt tests/results/512_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1024_r-sorted_false.txt tests/results/1024_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1024_r-sorted_false.txt tests/results/1024_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1024_r-sorted_false.txt tests/results/1024_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1024_r-sorted_false.txt tests/results/1024_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/1024_r-sorted_false.txt tests/results/1024_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/4096_r-sorted_false.txt tests/results/4096_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/4096_r-sorted_false.txt tests/results/4096_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/4096_r-sorted_false.txt tests/results/4096_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/4096_r-sorted_false.txt tests/results/4096_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/4096_r-sorted_false.txt tests/results/4096_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16348_r-sorted_false.txt tests/results/16348_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16348_r-sorted_false.txt tests/results/16348_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16348_r-sorted_false.txt tests/results/16348_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/16348_r-sorted_false.txt tests/results/16348_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/16348_r-sorted_false.txt tests/results/16348_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/65536_r-sorted_false.txt tests/results/65536_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/65536_r-sorted_false.txt tests/results/65536_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/65536_r-sorted_false.txt tests/results/65536_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/65536_r-sorted_false.txt tests/results/65536_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/65536_r-sorted_false.txt tests/results/65536_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/524288_r-sorted_false.txt tests/results/524288_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/524288_r-sorted_false.txt tests/results/524288_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/524288_r-sorted_false.txt tests/results/524288_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/524288_r-sorted_false.txt tests/results/524288_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/524288_r-sorted_false.txt tests/results/524288_r-sorted_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1000000_r-sorted_false.txt tests/results/1000000_r-sorted_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1000000_r-sorted_false.txt tests/results/1000000_r-sorted_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1000000_r-sorted_false.txt tests/results/1000000_r-sorted_false_qsort_random.txt
	./mergesort tests/testfiles/1000000_r-sorted_false.txt tests/results/1000000_r-sorted_false_mergesort.txt
	./heapsort tests/testfiles/1000000_r-sorted_false.txt tests/results/1000000_r-sorted_false_heapsort.txt

test-no-dup-random:
	./quicksort_lomuto tests/testfiles/1_random_false.txt tests/results/1_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1_random_false.txt tests/results/1_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1_random_false.txt tests/results/1_random_false_qsort_random.txt
	./mergesort tests/testfiles/1_random_false.txt tests/results/1_random_false_mergesort.txt
	./heapsort tests/testfiles/1_random_false.txt tests/results/1_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/2_random_false.txt tests/results/2_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/2_random_false.txt tests/results/2_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/2_random_false.txt tests/results/2_random_false_qsort_random.txt
	./mergesort tests/testfiles/2_random_false.txt tests/results/2_random_false_mergesort.txt
	./heapsort tests/testfiles/2_random_false.txt tests/results/2_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16_random_false.txt tests/results/16_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16_random_false.txt tests/results/16_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16_random_false.txt tests/results/16_random_false_qsort_random.txt
	./mergesort tests/testfiles/16_random_false.txt tests/results/16_random_false_mergesort.txt
	./heapsort tests/testfiles/16_random_false.txt tests/results/16_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/32_random_false.txt tests/results/32_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/32_random_false.txt tests/results/32_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/32_random_false.txt tests/results/32_random_false_qsort_random.txt
	./mergesort tests/testfiles/32_random_false.txt tests/results/32_random_false_mergesort.txt
	./heapsort tests/testfiles/32_random_false.txt tests/results/32_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/128_random_false.txt tests/results/128_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/128_random_false.txt tests/results/128_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/128_random_false.txt tests/results/128_random_false_qsort_random.txt
	./mergesort tests/testfiles/128_random_false.txt tests/results/128_random_false_mergesort.txt
	./heapsort tests/testfiles/128_random_false.txt tests/results/128_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/512_random_false.txt tests/results/512_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/512_random_false.txt tests/results/512_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/512_random_false.txt tests/results/512_random_false_qsort_random.txt
	./mergesort tests/testfiles/512_random_false.txt tests/results/512_random_false_mergesort.txt
	./heapsort tests/testfiles/512_random_false.txt tests/results/512_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1024_random_false.txt tests/results/1024_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1024_random_false.txt tests/results/1024_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1024_random_false.txt tests/results/1024_random_false_qsort_random.txt
	./mergesort tests/testfiles/1024_random_false.txt tests/results/1024_random_false_mergesort.txt
	./heapsort tests/testfiles/1024_random_false.txt tests/results/1024_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/4096_random_false.txt tests/results/4096_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/4096_random_false.txt tests/results/4096_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/4096_random_false.txt tests/results/4096_random_false_qsort_random.txt
	./mergesort tests/testfiles/4096_random_false.txt tests/results/4096_random_false_mergesort.txt
	./heapsort tests/testfiles/4096_random_false.txt tests/results/4096_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/16348_random_false.txt tests/results/16348_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/16348_random_false.txt tests/results/16348_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/16348_random_false.txt tests/results/16348_random_false_qsort_random.txt
	./mergesort tests/testfiles/16348_random_false.txt tests/results/16348_random_false_mergesort.txt
	./heapsort tests/testfiles/16348_random_false.txt tests/results/16348_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/65536_random_false.txt tests/results/65536_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/65536_random_false.txt tests/results/65536_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/65536_random_false.txt tests/results/65536_random_false_qsort_random.txt
	./mergesort tests/testfiles/65536_random_false.txt tests/results/65536_random_false_mergesort.txt
	./heapsort tests/testfiles/65536_random_false.txt tests/results/65536_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/524288_random_false.txt tests/results/524288_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/524288_random_false.txt tests/results/524288_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/524288_random_false.txt tests/results/524288_random_false_qsort_random.txt
	./mergesort tests/testfiles/524288_random_false.txt tests/results/524288_random_false_mergesort.txt
	./heapsort tests/testfiles/524288_random_false.txt tests/results/524288_random_false_heapsort.txt
	./quicksort_lomuto tests/testfiles/1000000_random_false.txt tests/results/1000000_random_false_qsort_lomuto.txt
	./quicksort_hoare tests/testfiles/1000000_random_false.txt tests/results/1000000_random_false_qsort_hoare.txt
	./quicksort_random tests/testfiles/1000000_random_false.txt tests/results/1000000_random_false_qsort_random.txt
	./mergesort tests/testfiles/1000000_random_false.txt tests/results/1000000_random_false_mergesort.txt
	./heapsort tests/testfiles/1000000_random_false.txt tests/results/1000000_random_false_heapsort.txt
