/* This is our implementation of quicksort with lomuto partition..
 *
*/
#include "auxiliary_functions.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
  if(!correctArgumentFormat(argc, argv))
  {
    exit(1);
  }
  std::vector<int> numbers;
  string input_file = argv[1];
  int success = readInputFile(input_file, numbers);
  if(success != 0)
  {
    cout<<"error reading input file. exit."<<endl; 
    exit(1);
  }
  //implement quicksort
  string output_file = argv[2];
  success = outputToFile(output_file, numbers);
  if(success != 0)
  {
    cout<<"error outputtting to file. exit."<<endl;
    exit(1);
  }
  return 0;
}
