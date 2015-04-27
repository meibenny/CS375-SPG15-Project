/* This is our implementation of quicksort with lomuto partition..
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
	/*
	 *  Begin timing sequence of:
	 *  Quicksort (lomuto)
	 */
	int numRuns = 20;
	struct timeval start[numRuns];
	struct timeval end[numRuns];

	vector<float> time;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		success = readInputFile(input_file, numbers);
		if(success != 0)
		{
			cout<<"error reading input file. exit."<<endl;
			exit(1);
		}
		int array_first = 0;
		int array_last  = (int) numbers.size()-1;

		start[i] = startTime(&start[i]);
		quicksort(numbers, array_first, array_last);

		end[i] = endTime(&end[i]);
		time.push_back(calculateTime(&start[i], &end[i]));
	}
	calcAvgTime(time);
	/*
	 *  End timing sequence of:
	 *  Quicksort (lomuto)
	 */

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
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int partition(std::vector<int> &A, int p, int r){
	bool debug = !true;
	int x = A[r];
	int i = p-1;
	if(debug){cout<<"x: "<<x<<" i: "<<i<<endl;}
	for(int j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i = i+1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
