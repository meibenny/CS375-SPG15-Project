/* Implementation of our hybrid sort.
 *
 *
 *
 *
 */
#include "timer.cpp"
#include "auxiliary_functions.cpp"
#include <vector>
#include <climits>
using namespace std;




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
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());
		start[i] = startTime(&start[i]);
		//would hybrid sort here.. IF I HAD ONE
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
