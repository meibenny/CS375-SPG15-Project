/* Implementation of merge sort.
 *
 */

#include "auxiliary_functions.cpp"
#include <vector>
#include <climits>
using namespace std;

//Function prototypes
void mergeSort(vector<int> &a, int p, int r);
void merge(vector<int> &a, int p, int q, int r);
vector<int> numbers;

int main(int argc, char* argv[]){
	if(!correctArgumentFormat(argc, argv))
	{
		exit(1);
	}
	string input_file = argv[1];
	int success = readInputFileForMerge(input_file, numbers);
	if(success != 0)
	{
		cout<<"error reading input file. exit."<<endl; 
		exit(1);
	}
	//Merge sort setting up initial parameters
	int low = 1;
	int high = numbers.size();
	mergeSort(numbers, low, high);		




	string output_file = argv[2];
	success = outputToFile(output_file, numbers);
	if(success != 0)
	{
		cout<<"error outputtting to file. exit."<<endl;
		exit(1);
	}



	return 0;
}
//Sorts a vector [p, r] recursively
void mergeSort(vector<int> &a, int p, int r)
{
	if(p < r)
	{
		int q = floor((p + r) /2);
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);			
		merge(a, p, q, r);	
	
	}


}


void merge(vector<int> &a, int p, int q, int r)
{
	cerr << "in merge" << endl;
	int n = q - p + 1;
	int m = r - q;

	vector<int> left, right;
	left.resize(n+2);
	right.resize(m+2);
	for(int i = 1 : n)
	{
		left.at(i) = a[p + i -1];
	}
	for(int j = 1: m)
	{
		right.at(j) = a[q + j];
	}
		
	left.at(n + 1) = (INT_MAX);
	right.at(m + 1) = (INT_MAX);

	int i = 1, j = 1;

	for(int k = p : r)
	{
		if(left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}


}








