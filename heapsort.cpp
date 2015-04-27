#include "auxiliary_functions.cpp"
#include <vector>
#include "timer.cpp"
using namespace std;

void maxHeapify(vector<int>& arr, int index, int numEle){
	int left = 2*index;
	int right = (2*index)+1;
	int largest = index;
	if(left <= numEle && arr[left] > arr[index]){
		largest = left;
	}
	else{
		largest = index;
	}
	if(right <= numEle && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != index){
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		maxHeapify(arr, largest, numEle);
	}
}

void buildMaxHeap(vector<int> &arr, int numEle){
	for(int i = floor(numEle/2); i>=1; i--){
		maxHeapify(arr,i,numEle);
	}
}

void heapsort(vector<int> &arr, int numEle){
	buildMaxHeap(arr , numEle);
	for(int i = numEle; i >=2; i--){
		long temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, 1, i-1);
	}
}

int main(int argc, char * argv[]){
	if(!correctArgumentFormat(argc, argv)){
		exit(1);
	}
	std::vector<int>numbers;
	vector<int> holder;
	string input_file = argv[1];
	int success = 0;
	success = readInputFile(input_file, holder);
	if(success != 0)
	{
		cout<<"error reading input file. exit."<<endl; 
		exit(1);
	}

	/*
	 *  Begin timing sequence of:
	 *  Heapsort
	 */
	int numRuns = 20;
	struct timeval start[numRuns];
	struct timeval end[numRuns];

	vector<float> time;
	for(int i = 0; i < numRuns; i++)
	{
		numbers.clear();
		numbers.assign(holder.begin(), holder.end());		
				numbers.insert(numbers.begin(), 0); 
				start[i] = startTime(&start[i]);

				//Perform a heapsort
				heapsort(numbers, numbers.size()-1);
				end[i] = endTime(&end[i]);
				time.push_back(calculateTime(&start[i], &end[i]));
				}
				calcAvgTime(time);
				/*
				 *  End timing sequence of:
				 *  Heapsort
				 */


				//get rid of the initial 0 so that its not printed out
				numbers.erase(numbers.begin());
				string output_file = argv[2];
				success = outputToFile(output_file, numbers);
				if(success != 0){
					cout<<"error outputting to file. exit."<< endl;
					exit(1);
				}

				return 0;
}
