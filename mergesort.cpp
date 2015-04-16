/* Implementation of merge sort.
 *
 */

#include "auxiliary_functions.cpp"
#include <vector>
#include <climits>
using namespace std;

//Function prototypes
vector<int> mergeSort(vector<int> & a);
vector<int> merge(vector<int> & vec, vector<int> & left, vector<int> & right);


int main(int argc, char* argv[]){

	vector<int> numbers;
	
	if(!correctArgumentFormat(argc, argv))
	{
		exit(1);
	}
	string input_file = argv[1];
	int success = readInputFile(input_file, numbers);
	if(success != 0)
	{
		cout<<"error reading input file. exit."<<endl; 
		exit(1);
	}
	


	//Perform a mergesort
	numbers = mergeSort(numbers);		




	string output_file = argv[2];
	success = outputToFile(output_file, numbers);
	if(success != 0)
	{
		cout<<"error outputtting to file. exit."<<endl;
		exit(1);
	}



	return 0;
}
vector<int> mergeSort(vector<int> & a)
{
	//Return vector if only one element
	if(a.size() == 1)
	{
		return a;
	}
	//Split the vector in half
	auto iter = a.begin() + (a.size() / 2);
	vector<int> left(a.begin(), iter);
	vector<int> right(iter, a.end());

	//Recursively call merge sort 
	left = mergeSort(left);
	right = mergeSort(right);
	
	return (merge(a, left, right));


}
vector<int> merge(vector<int> & vec, vector<int> & left, vector<int> & right)
{

	vector<int> mergeVec;
	u_int l_rover = 0, r_rover = 0;

	while(l_rover < left.size() && r_rover < right.size())
	{
		//Take the smaller of the two available values
		if(left[l_rover] < right[r_rover])
		{
			mergeVec.push_back(left[l_rover]);
			l_rover++;
		}
		else
		{
			mergeVec.push_back(right[r_rover]);
			r_rover++;
		}	
	}	
	
	//Place the numbers left over into the return vector
	while(l_rover < left.size())
	{
		mergeVec.push_back(left[l_rover]);
		l_rover++;

	}
	while(r_rover < right.size())
	{
		mergeVec.push_back(right[r_rover]);
		r_rover++;

	}

		return mergeVec;
}
/*//Sorts a vector [p, r] recursively
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
*/







