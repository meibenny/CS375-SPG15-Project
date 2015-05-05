In order to compile all files used for this project, simply use the command
make. 

The arguments for the sorting programs are of the form
./<executable> <input_file> <output_file>
where <executable> is a program such as quicksort_lomuto, 
<input_file> is a file of integers to be sorted, which is usually of the
form <integer>_<state>_<duplicates>.txt for example, 1024_random_false.txt.

The arguments for the input generation program are as follow:
./generate_inputs <size_of_input> <state> <duplicates> <output_file>

where <size_of_input> is the number of elements, <state> is one of:
'sorted' 'r-sorted' 'random', <duplicates> is a true/false value representing
whether or not duplicates are present, and <output_file> is the name of the
file to be output to.
