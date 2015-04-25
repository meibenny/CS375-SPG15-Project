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
	string input_file = argv[1];
  
  struct timeval start;
  struct timeval end; 
  start = startTime(&start);
  int success;
  for(int i = 0; i < 20; i++)
  {
    
    numbers.clear();
    
    //here i am inserting an initial 0 to make the vector work properly with the heapsort implementation
	  //i use the literal index 
	  numbers.insert(numbers.begin(), 0);

	  success = readInputFile(input_file, numbers);
	  if(success != 0)
    {
		  cout<<"error reading input file. exit."<<endl;
		  exit(1);
	  }
	
 	  heapsort(numbers, numbers.size()-1);
	}
  end = endTime(&end);
  calculateTime(&start, &end);
	
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
