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

$(MERGE_SORT): mergesort.cpp $(AUX_FUNCTIONS) $(TIMER) 
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
