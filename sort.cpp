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
  string input_file = argv[1];
  vector<int> numbers;
  int success = readInputFile(input_file, numbers);
  //failed reading input file for whatever reason
  if(success != 0){cout<<"Error reading input file. Exiting."<<endl; exit(1);}
  sort(numbers.begin(), numbers.end());
  string output_file = argv[2];
  success = outputToFile(output_file, numbers);
  if(success != 0){cout<<"Error outputting to file. Exiting."<<endl; exit(1);}
  return 0;
}

