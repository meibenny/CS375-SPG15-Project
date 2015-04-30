#include "auxiliary_functions.cpp"
#include "timer.cpp"
#include <vector>
#include <climits>
#include <set>
using namespace std;
//Function prototypes needed for
//Different flavors of hybrid sort
void quicksortMedian(vector<int> &A, int p, int r);
int medianOfThreePartition(vector<int> &A, int p, int r);
int partition(vector<int> & A, int p, int r);
void quicksortHoare(vector<int> &A, int p, int r);
int partitionHoare(vector<int> &A, int p, int r);
void maxHeapify(vector<int>& arr, int index, int numEle);
void buildMaxHeap(vector<int> & arr, int numEle);
void heapsort(vector<int> & arr, int numEle);



int analyzeInput(vector<int>& a)
{
	int dupVal = 0;
	int lastVal = 0;
	lastVal = a[0];
	set<int> values;
	values.insert(lastVal);
	bool firstCheck = false, secondCheck = false, thirdCheck = false;
	for(int i = 0 ; i <(int) a.size(); i += 20)
	{
		if(values.find(a[i]) == values.end())
		{//checking each fourth of the input to make sure none of it
			///contains mostly duplicates
			values.insert(a[i]);
			if(values.size() > 5 && !firstCheck)
			{
				firstCheck = true;
				i += a.size()/4;
			}
			else if(values.size() > 10 && !secondCheck)
			{
				secondCheck = true;
				i += a.size()/4;
			}
			else if(values.size() > 15 && !thirdCheck)
			{
				thirdCheck = true;
				i += a.size()/4;
			}
			else if(values.size() > 20)
				break;
		}
		else
		{
			//If value is found, check to see if same value lies ahead
			if(a[i] == a[i + a.size()/10] && a[i] == a[i + a.size()/20])
				i+= a.size()/10;
		}
	}
	if(values.size() < 20)
		dupVal = 1;
	return dupVal;
}


void quicksortHoare(std::vector<int> &A, int p, int r){
	int q;
	if(p < r)
	{
		q = partitionHoare(A, p, r);
		quicksortHoare(A, p, q);
		quicksortHoare(A, q+1, r);
	}
}

int partitionHoare(std::vector<int> &A, int p, int r){
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (true)
	{
		do
		{
			j = j - 1;
		}
		while(A[j] > x);
		do
		{
			i = i + 1;
		}
		while(A[i] < x);
		if(i < j)
		{
			swap(A[i], A[j]);
		}
		else
		{
			return j;
		}
	}
}

void quicksortMedian(std::vector<int> &A, int p, int r){
	int q;
	if(p < r)
	{
		q = medianOfThreePartition(A, p, r);
		quicksortMedian(A, p, q-1);
		quicksortMedian(A, q+1, r);
	}
}

int medianOfThreePartition(std::vector<int> &A, int p, int r){
	int pivot = A[(r+p)/2];
	if(A[p] <= pivot && A[r] <= A[p])
	{
		pivot = A[p];
		swap(A[r], A[p]);
	}
	else if(A[r] <= pivot && A[p] <= A[r])
	{
		pivot = A[r];
		//No need to swap
	}
	else
	{//Middle element remains the pivot
		swap(A[r], A[(r+p)/2]);
	}
	return partition(A, p, r);
}

int partition(std::vector<int> &A, int p, int r){
	int x = A[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i = i+1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}


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
