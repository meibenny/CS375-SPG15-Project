/* Implementation of quicksort with Hoare partition
 *
*/
#include "auxiliary_functions.cpp"
#include "timer.cpp"
#include <iostream>
#include <vector>
using namespace std;

void quicksort(std::vector<int> &A, int p, int r);
int partition(std::vector<int> &A, int p, int r);

int main(int argc, char* argv[]){
  bool debug = !true;
  if(!correctArgumentFormat(argc, argv))
  {
    exit(1);
  }
  std::vector<int> numbers;
  string input_file = argv[1];
  int success;
  
  struct timeval start, end;
  start = startTime(&start);

  for(int i = 0; i < 20; i++)
  {
    success = readInputFile(input_file, numbers);
    if(success != 0)
    {
      cout<<"error reading input file. exit."<<endl; 
      exit(1);
    }
    //implement quicksort
    int array_first = 0;
    int array_last  = (int) numbers.size()-1;
    if(debug){for(auto e: numbers){cout<<e<<endl;}}
    
    quicksort(numbers, array_first, array_last);
    numbers.clear();
  }
  end = endTime(&end);
	calculateTime(&start, &end);

  if(debug){for(auto e: numbers){cout<<e<<endl;}}
  string output_file = argv[2];
  success = outputToFile(output_file, numbers);
  if(success != 0)
  {
    cout<<"error outputtting to file. exit."<<endl;
    exit(1);
  }
  return 0;
}

void quicksort(std::vector<int> &A, int p, int r){
  bool debug = !true;
  if(debug){cout<<"p: "<<p<<" r: "<<r<<endl;}
  int q;
  if(p < r)
  {
    q = partition(A, p, r);
    quicksort(A, p, q);
    quicksort(A, q+1, r);
  }
}

int partition(std::vector<int> &A, int p, int r){
  bool debug = !true;
  if(debug){cout<<"in partition"<<endl;}
  if(debug)
  {
    cout<<"segfault when assigning x. p: "<<p<<endl;
  }
  int x = A[p];
  int i = p - 1;
  int j = r + 1;
  while (true)
  {
    do
    {
      j = j - 1;
    }
    while(A[j] > x);
    
    do
    {
      i = i + 1;
    }
    while(A[i] < x);
    
    if(i < j)
    {
      if(debug){cout<<"segfault when swapping."<<endl;}
      if(debug){cout<<"i: "<<i<<endl;}
      if(debug){cout<<"j: "<<j<<endl;}
      swap(A[i], A[j]);
    }
    else
    {
      return j;
    }
  }
}
