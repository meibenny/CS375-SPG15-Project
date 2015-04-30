-Scan through to see if its already mostly sorted.. If maybe ~50 or less items are only out of
  place, call a bubble sort which approaches linear complexity when mostly sorted. Fixes worst 
  case for quicksorts
  
-introsort: uses quicksort while identifying if the number of splits is far too many(approaching
  worst case for quicksort). if so, switches to heapsort. Basically once the recursion depth reaches
  log(n), that is when it switches to heapsort I believe. Both of these capabilities are included
  
-Parallel sorts: we could look into utilizing multiple threads to spead up any of the recursion
  in the sorts we have. this actually looks really cool to me and i'd like to explore it further'

  Scientific Method
-Question: How do we come up with the fastest sorting algorithm regardless 
of the data file?

-Hypothesis: In this project we implemented and tested many different 
sorting algorithms in order to come up with a hybrid solution that will 
take the best aspects from each of the dominant sorts. We implemented 
quicksort with three different partitioning methods; including lomuto, 
hoare, and randomized partitions. In addition, we also implemented the 
merge and heapsort sorting algorithms. We proceeded to analyze the 
different run times of all these different algorithms based on various 
test cases. Our test cases included several different file sizes and for 
each file size there was a different sorting of the numerical values; 
including already sorted values, reversely sorted values, and randomly 
sorted values. After testing each of the sorting algorithms with all of 
the file sizes our test results concluded that quicksort with the hoare 
partition and heapsort outperformed all of the other algorithms.

-Procedure: To construct our hybrid sort we begin by calling quicksort with
the hoare partition which outperformed the heapsort in most cases. The cases
in which heapsort outperformed the quicksort with hoare partition was when 
the file data was already sorted or reverse sorted. Our hybrid sort uses 
recursion to sort the data and if the level of recursion begins to exceed 
a certain point the hybrid sort switches over to heapsort indicating that 
the file is not randomized data. Even with the beginning recursive calls to
quicksort; this will still result in a much faster runtime than all of the 
other sorting algorithms. This is because heapsort drastically outperforms 
quicksort with the hoare partition for sorted or reversely sorted data. 
Therefore the lost time in the recursive calls to quicksort with the hoare 
partition is almost negligible when dealing with large file sizes. If in 
fact the level of recursion is small we should proceed with the quicksort 
with the hoare partition as it outperforms all of the other sorting 
algorithms that we have tested.

Summary: All in all our hybrid sort calls quicksort with hoare partition 
until the recursion level becomes too high indicating that the data is 
either sorted or reversely sorted then we switch over to heapsort which 
performs better under these conditions. If the recursion level remains 
fairly low we know that the data is randomized and we should proceed with 
the quicksort algorithm.

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
----

Hybrid sort analysis

Analysis of qsorts: After analysing more tests from these various algorithms,
two quicksorts come to play. We will look at quicksort with Hoare/Median of 3
Partitiong schemes

Hoare 
Pros: Maintains high performance on input with many duplicates

Slightly faster on randomized input

Cons: Unable to perform acceptably on sorted/rsorted inputs

Median of 3
Pros: Maintains high performance on sorted/rsorted inputs

cons: Unable to perform acceptably on input with many duplicates

Proposition
Since the hybrid sort we propose switches to heapsort at around 2*floor(lgn)
recursion depth, why not attempt to sort as much of it as possible before 
that depth is reached? We will go forward with the hybrid sort as proposed,
and then if we can devise a way to check for the presence of many duplicates 
in linear time, we would be able to pick the quicksort that has a higher
performance for that input. If the number of duplicates is arbitrarily low,
we will perform quicksort with hoare partition before switching to heapsort.
Otherwise, we will perform quicksort with median of 3 partitioning before
switching. I believe this modification will outperform the base hybrid sort
described above in testing.
