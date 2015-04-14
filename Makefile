COMPILER = g++
CXXFLAGS = -g -Wall -std=c++0x

#we use GENERATE_NUMBERS to generate input for the experiment
GENERATE_NUMBERS = generate_numbers
#we use SORT to sort the input to ensure correctness of our program
SORT = sort

all: $(GENERATE_NUMBERS) $(SORT)

$(SORT): sort.cpp auxiliary_functions.cpp
	$(COMPILER) $(CXXFLAGS) -o $(SORT) sort.cpp

$(GENERATE_NUMBERS): generate_numbers.cpp
	$(COMPILER) $(CXXFLAGS) -o $(GENERATE_NUMBERS) generate_numbers.cpp 

clean:
	rm -f *.o $(GENERATE_NUMBERS) $(SORT)
