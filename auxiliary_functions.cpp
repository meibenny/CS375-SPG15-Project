/* This file contains functions that can be used by
 * the sorts that we will implement.
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool correctArgumentFormat(int argc, char* argv[]);


bool correctArgumentFormat(int argc, char* argv[]){
  int NUM_CORRECT_ARGUMENTS = 3;
  string USAGE_MESSAGE = "USAGE: <input-file> <output-file>"; 

  if(argc != NUM_CORRECT_ARGUMENTS){
    cout<<"Expected "<<NUM_CORRECT_ARGUMENTS<<". Received "<<argc<<" arguments."<< endl;
    cout << USAGE_MESSAGE << endl;
    return false;
  }

  stringstream ss;
  ss << argv[1];
  string inputFile;
  ss >> inputFile;
  if(ss.fail()){
    cout << "Error. input-file must be a string." << endl;
    return false;
  }
  ifstream input;
  input.open(inputFile);
  if(!input.is_open()){
    cout << "Error. input-file must exist." << endl;
    return false;
  }
  ss.clear();
  ss << argv[2];
  string outputFile;
  ss >> outputFile;
  if(ss.fail()){
    cout << "Error. output-file must be a string." << endl;
    return false;
  }
  return true;
}
