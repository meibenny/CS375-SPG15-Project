-Scan through to see if its already mostly sorted.. If maybe ~50 or less items are only out of
  place, call a bubble sort which approaches linear complexity when mostly sorted. Fixes worst 
  case for quicksorts
  
-introsort: uses quicksort while identifying if the number of splits is far too many(approaching
  worst case for quicksort). if so, switches to heapsort. Basically once the recursion depth reaches
  log(n), that is when it switches to heapsort I believe. Both of these capabilities are included
  
-Parallel sorts: we could look into utilizing multiple threads to spead up any of the recursion
  in the sorts we have. this actually looks really cool to me and i'd like to explore it further
  
