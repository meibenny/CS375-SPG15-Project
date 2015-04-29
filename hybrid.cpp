/* Implementation of our hybrid sort.
 *
 *
 *
 *
 */
#include "auxiliary_functions.cpp"
#include "timer.cpp"
#include <vector>
#include <climits>
#include <set>
using namespace std;


//Function to analyze whether or not input
//contains a high number of duplicates
//Returns 1 if high number, 0 if low
int analyzeInput(vector<int>& a);

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


		//would hybrid sort here.. IF I HAD ONE
		end[i] = endTime(&end[i]);
		time.push_back(calculateTime(&start[i], &end[i]));
	}
	calcAvgTime(time);
	/*
	 *  End timing sequence of:
	 *  Hybrid sort
	 */
	if(dup)
	{
		cout << "High number of duplicates detected." << endl;
	}
	else
	{
		cout << "Low number of duplicated detected." << endl;
	}
	string output_file = argv[2];
	success = outputToFile(output_file, numbers);
	if(success != 0)
	{
		cout<<"error outputtting to file. exit."<<endl;
		exit(1);
	}
	return 0;
}


int analyzeInput(vector<int>& a)
{

	int dupVal = 0;
	int duplicates = 0;
	int lastVal = 0;
	lastVal = a[0];
	set<int> values;
	values.insert(lastVal);	
	for(int i = 0 ; i <(int) a.size(); i += 20)
	{
		if(values.find(a[i]) == values.end())
		{
			values.insert(a[i]);
			if(values.size() > 15)
				break;
		}	
		
	}

	if(values.size() < 15)
		dupVal = 1;


	return dupVal;

}

