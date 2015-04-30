#include "hybrid.h"
using namespace std;
void sort(vector<int> & A, int p, int r);
void introsort(vector<int> &A, int p, int r, int max_depth);

int main(int argc, char ** argv)
{
	vector<int>numbers;
	vector<int>holder;
	if(!correctArgumentFormat(argc, argv))
	{
		exit(1);
	}
	string input_file = argv[1];
	int success;
	success = readInputFile(input_file, holder);
	if(success != 0)
	{
		cout<<"error reading input file. exit."<<endl;
		exit(1);
	}
	/*
	 * Begin timing sequence of:
	 * Hybridsort
	 */
	int numRuns = 20;
	struct timeval start[numRuns];
	struct timeval end[numRuns];
	vector<float> time;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());
		start[i] = startTime(&start[i]);




		end[i] = endTime(&end[i]);
		time.push_back(calculateTime(&start[i], &end[i]));
	}
	calcAvgTime(time);
	/*
	 * End timing sequence of:
	 * Hybrid sort
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
	int max_depth = floor(log2(A.size())) * 2;
	introsort(A, p, r, max_depth);
}

void introsort(vector<int> &A, int p, int r, int max_depth)
{
	int n = A.size();
	if(n <= 1)
	{
		return; //We're in the base case
	}
	else if(max_depth == 0)
	{
		heapsort(A, n);
	}
}
