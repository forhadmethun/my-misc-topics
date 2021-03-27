//built in sort
/// ==================================================  SORTING ======================================================================
///q_sort
///
///


/// ======================================================== quick sort ... =======================================================================


///qsort(<arrayname>, <size>, sizeof(<elementsize>), compare_function); ...needs cstdlib header.....

int compare_function(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

///Example of compare_function() which is a parameter of q_short() function
/*
///Example of compare_function() which is a parameter of q_short() function

int compare_function(const void *a, const void *b) {
	return (strcmp((char *)a, (char *)b));
}

int compare_function(const void *a, const void *b) {
	double *x = (double *)a;
	double *y = (double *)b;
	// return *x - *y; // this is WRONG...
	if (*x < *y) return -1;
	else if (*x > *y) return 1; return 0;
}

typedef struct {
int day,month,year;
char *name;
} birthday;
int compare_function(const void *a,const void *b) {
birthday *x = (birthday *) a;
birthday *y = (birthday *) b;
if (x->month != y->month) // months different
return x->month - y->month; // sort by month

else { // months equal..., try the 2nd field... day
if (x->day != y->day) // days different
return x->day - y->day; // sort by day
else // days equal, try the 3rd field... year
return x->year - y->year; // sort by year
}
}

*/
