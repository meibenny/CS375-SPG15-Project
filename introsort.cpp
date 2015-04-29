#include "auxiliary_functions.cpp"
#include "timer.cpp"
#include <iostream>
#include <vector>

using namespace std;

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
