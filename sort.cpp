#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
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
  cout<<"You've given correct arguments. Congratulations."<<std::endl;

  string inputFile = argv[1];
  vector<int> numbers;
  ifstream input;
  input.open(inputFile);if(!input.is_open())
  {
    cout << "Error opening input file. Exit." << endl; 
    exit(1);
  }
  int eachNumber;
  while(input >> eachNumber)
  {
    numbers.push_back(eachNumber);
  }
  input.close();
  
  sort(numbers.begin(), numbers.end());

  ofstream output;
  string outputFile = argv[2];
  output.open(outputFile);if(!output.is_open()){cout<<"Error opening output file. Exit."<<endl; exit(1);}

  for(int i = 0; i < (int) numbers.size(); i++){
    output << numbers[i] << endl;
  }
  output.close();

  return 0;
}

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
