#include "auxiliary_functions.cpp"
#include "timer.cpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void sort(std::vector<int> &A, int p, int r);
void introsort(std::vector<int> &A, int p, int r, int max_depth);
int partition(std::vector<int> &A, int p, int r);
void heapsort(vector<int> &arr, int numEle);
void maxHeapify(vector<int>& arr, int index, int numEle);
void buildMaxHeap(vector<int> &arr, int numEle);

int main(int argc, char*[] argv)
{
  if(!correctArgumentFormat(argc, argv))
  {
    exit(1);
  }
  std::vector<int> numbers;
	vector<int> holder;
	string input_file = argv[1];
	int success;
	success = readInputFile(input_file, holder);
	if(success != 0)
	{
		cout<<"error reading input file. exit."<<endl;
		exit(1);
	}
	/*
	 *  Begin timing sequence of:
	 *  Introsort
	 */
	int numRuns = 5;
	struct timeval start[numRuns];
	struct timeval end[numRuns];

	vector<float> time;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());	
		int array_first = 0;
		int array_last  = (int) numbers.size()-1;

		start[i] = startTime(&start[i]);
    //add call to introsort

		end[i] = endTime(&end[i]);
		time.push_back(calculateTime(&start[i], &end[i]));
	}
	calcAvgTime(time);
	/*
	 *  End timing sequence of:
	 *  Introsort
	 */

	string output_file = argv[2];
	success = outputToFile(output_file, numbers);
	if(success != 0)
	{
		cout<<"error outputtting to file. exit."<<endl;
		exit(1);
	}



  return 0;
}

void sort(std::vector<int> &A, int p, int r)
{
  //We use log10 because the algorithm doens't specify which log to use.
  int max_depth = floor(log10(A.length())) * 2;
  introsort(A, p, r, max_depth);
}

void introsort(std::vector<int> &A, int p, int r, int max_depth)
{
  int n = A.length();
  if(n <= 1)
  {
    return; //We're in the base case
  }
  else if(max_depth = 0)
  {
    heapsort(A);
  }
}
int partition(std::vector<int> &A, int p, int r){
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
			swap(A[i], A[j]);
		}
		else
		{
			return j;
		}
	}
}


void maxHeapify(vector<int>& arr, int index, int numEle){
	int left = 2*index;
	int right = (2*index)+1;
	int largest = index;
	if(left <= numEle && arr[left] > arr[index]){
		largest = left;
	}
	else{
		largest = index;
	}
	if(right <= numEle && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != index){
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		maxHeapify(arr, largest, numEle);
	}
}

void buildMaxHeap(vector<int> &arr, int numEle){
	for(int i = floor(numEle/2); i>=1; i--){
		maxHeapify(arr,i,numEle);
	}
}

void heapsort(vector<int> &arr, int numEle){
	buildMaxHeap(arr , numEle);
	for(int i = numEle; i >=2; i--){
		long temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, 1, i-1);
	}
}
