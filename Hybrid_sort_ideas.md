-Scan through to see if its already mostly sorted.. If maybe ~50 or less items are only out of
  place, call a bubble sort which approaches linear complexity when mostly sorted. Fixes worst 
  case for quicksorts
  
-introsort: uses quicksort while identifying if the number of splits is far too many(approaching
  worst case for quicksort). if so, switches to heapsort. Basically once the recursion depth reaches
  log(n), that is when it switches to heapsort I believe. Both of these capabilities are included
  
-Parallel sorts: we could look into utilizing multiple threads to spead up any of the recursion
  in the sorts we have. this actually looks really cool to me and i'd like to explore it further
'

ANALYSIS

While analyzing the times it takes to sort different input formats, 
i.e. sorted, reversely sorted, or randomized, we first noticed that 
mergesort is unacceptably slow for even the smallest input sizes. 
Mergesort is the slowest sort for input sizes of 1 up to around sizes of
4096. Mergesort only outperforms another sort when quicksort grows to 
unacceptably large time slices due to the large input size. 

Since mergesort is unacceptably slow, any hybrid sort that includes
mergesort will also be unacceptably slow.

The race between the sorting algorithms that we use in our hybrid sort
are between quicksort and heapsort. 

Through our analysis, we noticed that heapsort has consistently performed 
well through all of our test cases. Heapsort is not always the fastest,
but is also not always the slowest. The benefits of heapsort are that it
offers moderately fast performance in almost all cases that we provided.

Theoretically, and practiacally, we noticed that quicksort performs the 
worst when the input is sorted, or reversely sorted. However, if the
numbers are randomized throughout the file, we see that quicksort blows
every other sort out of the water. Quicksort performance on randomized
input is amazingly quick.

A hybrid sort should include quicksort and heapsort and switch based on 
the type of input given. 

Since quicksort performs horribly when the input is sorted or reversely
sorted. We can leverage this fact to our benefit - quicksort will have to
perform a large number of recursive calls in order to "sort" the already
sorted array. If we can detect the recursion level, we can switch from 
quicksort to heapsort, or vice versa depending on the given input.

A quick search regarding this will yield a sorting algorithm known as 
introsort. Introsort is a hybrid sorting algorithm based on quicksort
and heapsort. It starts sorting the given input by using quicksort, but
if it detects heapsort going beyond a certain recursion level, it switches
to heapsort to sort the array.

