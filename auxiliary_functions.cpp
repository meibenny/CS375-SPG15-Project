/* This file contains functions that can be used by
 * the sorts that we will implement.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* Returns true if the arguments given to program are correct.
 * Returns false is arguments are incorrect.
 * Arguments should be <input_file> <output_file>
 * Where <input_file> is a file containing numbers to be sorted.
 * Where <output_file> is a file where the sorted output should be placed.
*/
bool correctArgumentFormat(int argc, char* argv[]);

/* Can be called by sort functions to read the input file.
 * Stores input in int vector, buffer.
 * returns 0 if operation completes successfully.
 * returns 1 if operation fails for any reason
 * Argument should be <input_file> <buffer>
 * Where <input_file> contains the numbers to be sorted.
 * Where <buffer> is an empty int vector
 * readInputFile modifies <buffer> and stores the input inside <buffer>
 *
*/
int readInputFile(string file_name, std::vector<int>&buffer);

int readInputFile(string file_name, std::vector<int>& buffer){
  string input_file = file_name;
  ifstream input;
  input.open(input_file); 
  
  //input_file failed to open for any reason
  if(!input.is_open()){return 1;}

  int eachNumber;
  while(input >> eachNumber)
  {
    buffer.push_back(eachNumber);
  }
  input.close();
  return 0;
}

bool correctArgumentFormat(int argc, char* argv[]){
  int NUM_CORRECT_ARGUMENTS = 3;
  string USAGE_MESSAGE = "USAGE: <input-file> <output-file>"; 

  if(argc != NUM_CORRECT_ARGUMENTS)
  {
    cout<<"Expected "<<NUM_CORRECT_ARGUMENTS<<". Received "<<argc<<" arguments."<< endl;
    cout << USAGE_MESSAGE << endl;
    return false;
  }

  stringstream ss;
  ss << argv[1];
  string inputFile;
  ss >> inputFile;
  if(ss.fail())
  {
    cout << "Error. input-file must be a string." << endl;
    return false;
  }
  ifstream input;
  input.open(inputFile);
  if(!input.is_open())
  {
    cout << "Error. input-file must exist." << endl;
    return false;
  }
  ss.clear();
  ss << argv[2];
  string outputFile;
  ss >> outputFile;
  if(ss.fail())
  {
    cout << "Error. output-file must be a string." << endl;
    return false;
  }
  return true;
}