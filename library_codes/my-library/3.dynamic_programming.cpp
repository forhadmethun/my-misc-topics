#include "1.head.cpp"

/// ------------------------------------------------ DYNAMIC PROGRAMMING -------------------------------------------------------------
///LIS
///MIN COST PATH
///COIN CHANGE
///MATRIX CHAIN MULTIPICATION
///BIONOMIAL CO EFFICIENT
///0 1 KNAPSACK
///CUTTING ROD
///LONGEST PALINDROMIC SUBSEQUENCE
///LONGEST SUBSEQUECE ARRAY SUM
///
/// ----------------------------------------------------Dynamic Programming --------------------------------------

int _lis( int arr[], int n, int *max_ref)
{
    /* Base case */
    if(n == 1)
        return 1;

    int res, max_ending_here = 1; // length of LIS ending with arr[n-1]

    /* Recursively get all LIS ending with arr[0], arr[1] ... ar[n-2]. If
       arr[i-1] is smaller than arr[n-1], and max ending with arr[n-1] needs
       to be updated, then update it */
    for(int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    // Compare max_ending_here with the overall max. And update the
    // overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;

    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;

    // The function _lis() stores its result in max
    _lis( arr, n, &max );

    // returns max
    return max;
}

///input : array & size of the array
///output: a value which has maximum value ...






///MIN COST PATH
#define RR 3
#define CC 3
int minCostPath(int cost[RR][CC], int m, int n)
{
     int i, j;

     // Instead of following line, we can use int tc[m+1][n+1] or
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
     int tc[RR][CC];

     tc[0][0] = cost[0][0];

     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];

     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];

     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j-1],min(tc[i-1][j], tc[i][j-1])) + cost[i][j];

     return tc[m][n];
}
///input : 2D mat ,cost[][] , position (m,n)
///output: minimum cost path to reach (m ,n ) to (0,0)





///COIN CHANGE
int coinChange( int S[], int m, int n ) // which cent has to change: n , sizeof(arr): m
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[n+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}
///input (3 value ) : array of coin  supply S , size of the array m , change to make n
///output : coin  change to make the value n





///MATRIX CHAIN MULTIPICATION -> it is not dynamic version -_- ,,, do correction ....

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    // place parenthesis at different places between first and last matrix,
    // recursively calculate count of multiplcations for each parenthesis
    // placement and return the minimum count
    for (k = i; k <j; k++)
    {
        count = MatrixChainOrder(p, i, k) +
                MatrixChainOrder(p, k+1, j) +
                p[i-1]*p[k]*p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return min;
}


/// BIONOMIAL CO EFFICIENT
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}
///input :n , r
///output: nCr



///0-1 KNAPSACK
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}


///CUTTING ROD
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;

   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }

   return val[n];
}
///input :array price[] for different price , how many length of the rod to be cut
///output:  integer of the length ...




///MAXIMUM SUM INCREASING SUBSEQUENCE
/* maxSumIS() returns the maximum sum of increasing subsequence in arr[] of
   size n */
int maxSumIS( int arr[], int n )
{
   int *msis, i, j, max = 0;
   msis = (int*) malloc ( sizeof( int ) * n );

   /* Initialize msis values for all indexes */
   for ( i = 0; i < n; i++ )
      msis[i] = arr[i];

   /* Compute maximum sum values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
            msis[i] = msis[j] + arr[i];

   /* Pick maximum of all msis values */
   for ( i = 0; i < n; i++ )
      if ( max < msis[i] )
         max = msis[i];

   /* Free memory to avoid memory leak */
   free( msis );

   return max;
}
///input : an array  ,size of the array
///output: max increasing sum






///Longest Palindromic Subsequence ( DP + STRING)
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
    int n=strlen(str);
    int i,j,cl;

    int L[n][n];

    for(i=0;i<n;i++)
    {
        L[i][i] = 1;
    }
    for(cl=2;cl<=n;cl++)
    {
        for(i=0;i<n-cl+1;i++)
        {
            j = i+cl-1;
            if(str[i] ==str[j] && cl ==2)
            {
                L[i][j] = 2;

            }
            else if(str[i] == str[j]){
                L[i][j] = L[i+1][j-1] + 2;
            }
            else{
                L[i][j] =  max(L[i][j-1],L[i+1][j]);
            }
        }
    }
    return L[0][n-1];
}

///input : char* array(string)
///output: int of the length ...


int n = 0;
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

     // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}


//maximum sum subarray in 2D grid .... 
// The main function that finds maximum sum rectangle
int M[105][105];
void findMaxSum()
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < n; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < n; ++right)
        {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[]. The kadane() function
            // also sets values of start and finish.  So 'sum' is sum of
            // rectangle between (start, left) and (finish, right) which is the
            //  maximum sum with boundary columns strictly as left and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far. If sum is more, then update
            // maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    /*
    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);
    */
    cout << maxSum << endl;
}



int main()
{
    /*
    ///LIS TEST
    int arr[] = {10, 22, 9 ,33, 21 ,50, 41,60 };
    int n = 8;

    cout << lis(arr,n) << endl;
    */
    /*
    ///MINCOST TEST
    int cost[RR][CC] = {
                {
                    1,2,3
                },
                {
                    4,8,2
                },
                {
                    1,5,4
                }
    };
    cout << minCostPath(cost,2,2) << endl;
    */

    /*

    ///COIN CHANGE
    int arr[] = {1,2,3};
    cout << coinChange(arr,3,4) << endl;
    */

    /*
    ///BIONOMIAL CO-EFF
    cout << binomialCoeff(5,3) << endl;
    */

    /*
    ///LPS
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    cout << lps(seq) << endl;
    */





    return 0;
}
