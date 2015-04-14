#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "auxiliary_functions.cpp"
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

