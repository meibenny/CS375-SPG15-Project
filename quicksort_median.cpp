#include "timer.cpp"
#include "auxiliary_functions.cpp"
#include <vector>
#include <climits>
using namespace std;

void quicksort(vector<int> &A, int p, int r);
int medianOfThreePartition(vector<int> &A, int p, int r);
int partition(vector<int> & A, int p, int r);


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
   *  Quicksort (median of 3)
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
   *  Quicksort(median of 3)
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


void quicksort(std::vector<int> &A, int p, int r){
  int q;
  if(p < r)
  {
    q = medianOfThreePartition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

//Choose three value from the vector randomly, and pick the median
int medianOfThreePartition(std::vector<int> &A, int p, int r){
/*  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  //We use a uniform distribution in order to pseudo-guarantee that all
  //values in [p,r] have an equal opportunity to appear
  std::uniform_int_distribution<int> distribution(p,r);
  int i = distribution(generator);
  swap(A[r], A[i]);
*/  




	return partition(A, p, r);
}

int partition(std::vector<int> &A, int p, int r){
  bool debug = !true;
  int x = A[r];
  int i = p-1;
  if(debug){cout<<"x: "<<x<<" i: "<<i<<endl;}
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






