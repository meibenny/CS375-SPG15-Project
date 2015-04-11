#include <iostream>
#include <string>

/* This file is used to generate input for the sorting algorithms
 * that we propose to write.
 *
 * In order to use this program, it must be given several arguments
 *
 * Invoke this program by:
 * ./generate_inputs <size_of_input> <state> <duplicates> <output_file>
 * 
 * where size_of_input represents how large of a dataset should be generated
 * state represents whether the data is sorted, unsorted, randomized
 * duplicates is a flag determining if duplicates are allowed in the set
 * output_file is a file where the dataset should be written
 * 
*/

bool correctArgumentFormat(int argc, char* argv[]);

int main(int argc, char* argv[]){
  
  //If we don't have the correct arguments, there is no point in
  //proceeding any further. Simply exit the program and print
  //an error message.
  if(!correctArgumentFormat(argc, argv)){
    exit(1);
  }

  std::cout<<"Hello world. We're in generate_numbers.cpp"<<std::endl;
  
  return 0;
}

bool correctArgumentFormat(int argc, char* argv[]){
  int NUM_CORRECT_ARGUMENTS = 5;
  std::string USAGE_MESSAGE = "Usage: <size_of_input> <state> <duplicates> <output_file>";
  if(argc != NUM_CORRECT_ARGUMENTS){
    std::cout<<"Error. Incorrect number of arguments."<<std::endl;
    std::cout<<USAGE_MESSAGE<<std::endl;
    return false;
  }
  return true;
}
