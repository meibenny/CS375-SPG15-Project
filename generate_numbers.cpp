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
 * state may be one of: sorted, reversely_sorted, randomized.
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
    if(output.is_open()){
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

  if(duplicates == "false"){
    if(state == "sorted"){
      for(int i = 0; i < input_size; i++){
        output << i + 1 << endl;
      }
    }
    else if(state == "reversely_sorted"){
      for(int i = input_size; i > 0; i--){
        output << i << endl;
      }
    }
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
  
    //TODO: Add code to generate sorted input
    //Option one
    //Generates values in a range [1, input_size -1]
    if(state == "sorted")
    {
    	srand(time(NULL));
    	for(int i = 0; i < input_size; i+= randomNumber)	
      	{	

  		randomNumber = rand() % 5;
		for(int j = 0; j < randomNumber; j++)
		output << i + 1 << endl;
      	}
    }
    //Option two
    //Generates values in a range [0, input_size /2]
    if(state == "sorted"){
      int modulus = input_size / 2; //We use a modulus to guarantee that we will have duplicate values
      int* frequencyTable = new int[modulus];
      for(int i = 0; i < modulus; i++){
        frequencyTable[i] = 0;
      }
      for(int i = 0; i < input_size; i++){
        frequencyTable[i%modulus] += 1;
      }
      for(int i = 0; i < modulus; i++){
        while(frequencyTable[i] > 0){
          output << i << endl;
          frequencyTable[i] -= 1;
        }
      }
      delete[] frequencyTable;

    }
    //TODO: Add code to generate reversely sorted input
    else if(state == "reversely_sorted"){

    }
    //TODO: Add code to generate randomized input
    else if(state == "randomized"){

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
     stateString == "reversely_sorted" || 
     stateString == "randomized")){
    std::cout<<"Error. state must be either \"sorted\", \"reversely_sorted\", or \"randomized\"."<<std::endl;
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
