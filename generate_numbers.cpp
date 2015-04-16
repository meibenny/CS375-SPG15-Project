#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;
/* This file is used to generate input for the sorting algorithms
 * that we propose to write.
 *
 * In order to use this program, it must be given several arguments
 *
 * Invoke this program by:
 * ./generate_inputs <size_of_input> <state> <duplicates> <output_file>
 * 
 * where size_of_input represents how large of a dataset should be generated
 * state represents whether the data is sorted, reversely sorted, randomized
 * duplicates is a flag determining if duplicates are allowed in the set
 * output_file is a file where the dataset should be written
 * 
 * size_of_input may be any integer.
 * state may be one of: sorted, r_sorted, randomized.
 * duplicates may be one of: true, false.
 * output_file may be any string.
 *
 */


bool correctArgumentFormat(int argc, char *argv[]);

int main(int argc, char* argv[]){

	//If we don't have the correct arguments, there is no point in
	//proceeding any further. Simply exit the program and print
	//an error message.
	if(!correctArgumentFormat(argc, argv)){
		exit(1);
	}

	stringstream ss;
	ss << argv[1];
	int input_size = 0, randomNumber = 0;
	ss >> input_size;
	if(ss.fail()){cout<<"Error in state == sorted, duplicates == false"<< endl; exit(1);}
	string state = argv[2];
	string duplicates = argv[3];
	string outputFile = argv[4];

	//Open and error check stringstream to 
	//output file before entering number
	//generation code
	ofstream output;
	output.open(outputFile);
	if(output.is_open())
	{
		//clear file contents
		output.close();
	}
	output.open(outputFile);
	if(!output.is_open()){
		//exit program if we can't open the output file
		cout<<"Could not open "<< outputFile << endl;
		//cout<<"Could not open "<<outputFile<<" in state == sorted, duplicates == false"<< endl;
		exit(1);
	}
	/*
	//	File output stream has been initialized and error checked:
	//	Clear to begin generation code
	//    First 3 cases are for no duplicate numbers allowed, 
	//	Last 3 cases are for duplicates permitted.
	 */  

	if(duplicates == "false"){
		//Code to generate sorted, no duplicate input
		if(state == "sorted"){
			for(int i = 0; i < input_size; i++){
				output << i + 1 << endl;
			}
		}
		//Code to generate reverse sorted, no duplicate input
		else if(state == "r_sorted"){
			for(int i = input_size; i > 0; i--){
				output << i << endl;
			}
		}
		//Code to generate randomized, no duplicate input
		else if(state == "randomized")
		{
			bool debug = false;
			srand(time(NULL));
			set<int> numberList;
			for(int i = 0; i < input_size; i++)
			{
				randomNumber = rand();
				if(numberList.find(randomNumber) == numberList.end())
				{   
					output << randomNumber << endl;
					numberList.insert(randomNumber);
				}
				else
				{
					if(debug){cout <<"duplicate number found at index i = "<< i << endl;}
					i--;
				}
			}
		}
	}
	else if(duplicates == "true")
	{
		//Code to generate sorted, duplicated permitted input
		//Option one
		//Generates values in a range [1, input_size -1]
		int k = 0;
		if(state == "sorted")
		{
			srand(time(NULL));
			for(int i = 0; i < input_size && k < input_size; i+= randomNumber)	
			{	
				//This line needs to be fine tuned:
				//Depending on how many duplicates we would like to 
				//have in a row we can alter it
				randomNumber = rand() % input_size;

				for(int j = 0; j < randomNumber && k < input_size; j++)
				{
					output << i + 1 << endl;
					k++;
				}
			}
		}
		//Code to generate reversely sorted, duplicates permitted input
		else if(state == "r_sorted")
		{
			srand(time(NULL));
			for(int i = input_size; i > 0&& k < input_size; i-= randomNumber)	
			{	
				//This line needs to be fine tuned:
				//Depending on how many duplicates we would like to 
				//have in a row we can alter it
				//randomNumber = rand() % (input_size / 10);
				randomNumber = rand() % input_size;

				for(int j = 0; j < randomNumber && k < input_size; j++)
				{
					output << i  << endl;
					k++;
				}
			}
		}
		//Code to generate randomized, duplicates permitted input
		else if(state == "randomized"){
			int leftToGo = input_size;
			int numToPrint = 0;
			srand(time(NULL));
			while(leftToGo > 0)
			{
				randomNumber = (rand() % input_size);
				//Limit # of occurences of any single
				//number to 5: can be fine tuned
				numToPrint = rand();
				for(int j = 0; j < randomNumber && leftToGo > 0; j++)
				{
					output << numToPrint << endl;
					leftToGo--;
				}
			}
		}
	}
	output.close();
	return 0;
}

bool correctArgumentFormat(int argc, char *argv[]){
	int NUM_CORRECT_ARGUMENTS = 5;
	std::string USAGE_MESSAGE = "Usage: <size_of_input> <state> <duplicates> <output_file>";
	if(argc != NUM_CORRECT_ARGUMENTS){
		std::cout<<"Error. Incorrect number of arguments."<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	std::stringstream ss;
	//Check whether the first argument is an integer
	ss << argv[1];
	int inputSize; 
	ss >> inputSize;
	if(ss.fail()){
		std::cout<<"Error. size_of_input must be an integer."<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	if(inputSize <= 0){
		std::cout<<"Error. size_of_input must be greater than 0."<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	//Test whether the "state" arguement is correct
	ss.clear();
	std::string stateString;
	ss << argv[2];
	ss >> stateString;
	if(ss.fail()){
		std::cout<<"Error. state must be a string."<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	if(!(stateString == "sorted" || 
				stateString == "r_sorted" || 
				stateString == "randomized")){
		std::cout<<"Error. state must be either \"sorted\", \"r_sorted\", or \"randomized\"."<<std::endl;
		return false;
	}
	//Test whether the "duplicates" arguement is correct
	ss.clear();
	std::string duplicatesString;
	ss << argv[3];
	ss >> duplicatesString;
	if(ss.fail()){
		std::cout<<"Error. duplicates must be a string."<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	if(!(duplicatesString == "true" || duplicatesString == "false")){
		std::cout<<"Error. duplicates must be either \"true\" or \"false\"."<<std::endl;
		return false;
	}
	//Test whether the output argument is correct
	ss.clear();
	std::string outputFile;
	ss << argv[4];
	ss >> outputFile;
	if(ss.fail()){
		std::cout<<"Error. output_file must be a string"<<std::endl;
		std::cout<<USAGE_MESSAGE<<std::endl;
		return false;
	}
	ss.clear();
	return true;
}
