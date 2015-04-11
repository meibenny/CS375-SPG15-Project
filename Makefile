COMPILER = g++
CXXFLAGS = -g -Wall -std=c++0x

#we use GENERATE_NUMBERS to generate input for the experiment
GENERATE_NUMBERS = generate_numbers

all: $(GENERATE_NUMBERS)

$(GENERATE_NUMBERS): generate_numbers.cpp
	$(COMPILER) $(CXXFLAGS) -o $(GENERATE_NUMBERS) generate_numbers.cpp 

clean:
	rm -f *.o $(GENERATE_NUMBERS)
