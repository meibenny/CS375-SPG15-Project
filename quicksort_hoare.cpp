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

	/*
	 *  Begin timing sequence of:
	 *  Quicksort (hoare)
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
	 *  Quicksort (hoare)
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
