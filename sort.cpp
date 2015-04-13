#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/* Use this file to sort the automatically generated input
 *
 * NOTE: This is not the implementation of the project code
 * This file merely sorts the input so that we can be sure that
 * the code we write for our project is sorting correctly.
 *
 * To invoke this file, use:
 * ./sort <input-file> <output-file>
 *
 * input-file is the file that needs to the sorted
 * output-file is the file that contains the sorted numbers from input-file
*/

bool correctArgumentFormat(int argc, char* argv[]);

int main(int argc, char* argv[]){
  
  if(!correctArgumentFormat(argc, argv)){
    exit(1);
  }
  std::cout<<"You've given correct arguments. Congratulations."<<std::endl;

  return 0;
}

bool correctArgumentFormat(int argc, char* argv[]){
  int NUM_CORRECT_ARGUMENTS = 3;
  std::string USAGE_MESSAGE = "USAGE: <input-file> <output-file>"; 

  if(argc != NUM_CORRECT_ARGUMENTS){
    std::cout<<"Expected "<<NUM_CORRECT_ARGUMENTS<<". Received "<<argc<<" arguments."<<std::endl;
    std::cout<<USAGE_MESSAGE<<std::endl;
    return false;
  }

  std::stringstream ss;
  ss << argv[1];
  std::string inputFile;
  ss >> inputFile;
  if(ss.fail()){
    std::cout<<"Error. input-file must be a string."<<std::endl;
    return false;
  }
  std::ifstream input;
  input.open(inputFile);
  if(!input.is_open()){
    std::cout<<"Error. input-file must exist."<<std::endl;
    return false;
  }
  ss.clear();
  ss << argv[2];
  std::string outputFile;
  ss >> outputFile;
  if(ss.fail()){
    std::cout<<"Error. output-file must be a string."<<std::endl;
    return false;
  }
  return true;
}
