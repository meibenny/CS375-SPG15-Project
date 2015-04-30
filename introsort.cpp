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
	int numRuns = 1;
	struct timeval start[numRuns];
	struct timeval end[numRuns];
	vector<float> time;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());
		int p = 0, r = (int)numbers.size() - 1;		
		start[i] = startTime(&start[i]);

		sort(numbers, p, r);


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
	//This depth will be fine tuned after running tests
	int max_depth = 2* floor(log2(A.size()));
	cout << "Max recursion depth we will go to: " << max_depth << endl;
	introsort(A, p, r, max_depth);
}

void introsort(vector<int> &A, int p, int r, int max_depth)
{
	int n = r-p;
	if(n <= 1)
	{
		return; //We're in the base case
	}
	else if(max_depth == 0)
	{
		heapsort(A, n);
		return;
	}
	else
	{
		int q;
		q = partitionHoare(A, p, r);
		introsort(A, p, q, --max_depth);
		introsort(A, q+1, r, --max_depth);
	}


}
