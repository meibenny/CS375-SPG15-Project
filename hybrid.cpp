#include "hybrid.h"
using namespace std;
void sort(vector<int> & A, int p, int r);
void hoareSort(vector<int> &A, int p, int r, int max_depth);

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
	 *  Begin timing sequence of:
	 *  Hybridsort
	 */
	int numRuns = 20;
	struct timeval start[numRuns];
	struct timeval end[numRuns];

	vector<float> time;
	int dup = 0;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());
		start[i] = startTime(&start[i]);

		dup = analyzeInput(numbers);
		if(dup)
		{
			sort(numbers, 0, (int)numbers.size()-1);
			
			cout << "High number of duplicates detected." << endl;
		}
		else
		{
			cout << "Low number of duplicated detected." << endl;
		}

		end[i] = endTime(&end[i]);
		time.push_back(calculateTime(&start[i], &end[i]));
	}
	calcAvgTime(time);
	/*
	 *  End timing sequence of:
	 *  Hybrid sort
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
	hoareSort(A, p, r, max_depth);
}

void hoareSort(vector<int> &A, int p, int r, int max_depth)
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
		hoareSort(A, p, q, --max_depth);
		hoareSort(A, q+1, r, --max_depth);
	}


}




