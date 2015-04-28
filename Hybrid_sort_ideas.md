-Scan through to see if its already mostly sorted.. If maybe ~50 or less items are only out of
  place, call a bubble sort which approaches linear complexity when mostly sorted. Fixes worst 
  case for quicksorts
  
-introsort: uses quicksort while identifying if the number of splits is far too many(approaching
  worst case for quicksort). if so, switches to heapsort. Basically once the recursion depth reaches
  log(n), that is when it switches to heapsort I believe. Both of these capabilities are included
  
-Parallel sorts: we could look into utilizing multiple threads to spead up any of the recursion
  in the sorts we have. this actually looks really cool to me and i'd like to explore it further
  
  Scientific Method
-Question: How do we come up with the fastest sorting algorithm regardless of the data file?
-Hypothesis: In this project we implemented and tested many different sorting algorithms in order to come up with a hybrid solution that will take the best aspects from each of the dominant sorts. We implemented quicksort with three different partitioning methods; including lomuto, hoare, and randomized partitions. In addition, we also implemented the merge and heapsort sorting algorithms. We proceeded to analyze the different run times of all these different algorithms based on various test cases. Our test cases included several different file sizes and for each file size there was a different sorting of the numerical values; including already sorted values, reversely sorted values, and randomly sorted values. After testing each of the sorting algorithms with all of the file sizes our test results concluded that quicksort with the hoare partition and heapsort outperformed all of the other algorithms.
-Procedure: To construct our hybrid sort we begin by calling quicksort with the hoare partition which outperformed the heapsort in most cases. The cases in which heapsort outperformed the quicksort with hoare partition was when the file data was already sorted or reverse sorted. Our hybrid sort uses recursion to sort the data and if the level of recursion begins to exceed a certain point the hybrid sort switches over to heapsort indicating that the file is not randomized data. Even with the beginning recursive calls to quicksort; this will still result in a much faster runtime than all of the other sorting algorithms. This is because heapsort drastically outperforms quicksort with the hoare partition for sorted or reversely sorted data. Therefore the lost time in the recursive calls to quicksort with the hoare partition is almost negligible when dealing with large file sizes. If in fact the level of recursion is small we should proceed with the quicksort with the hoare partition as it outperforms all of the other sorting algorithms that we have tested.
Summary: All in all our hybrid sort calls quicksort with hoare partition until the recursion level becomes too high indicating that the data is either sorted or reversely sorted then we switch over to heapsort which performs better under these conditions. If the recursion level remains fairly low we know that the data is randomized and we should proceed with the quicksort algorithm.
