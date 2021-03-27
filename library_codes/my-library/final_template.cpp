///======================================================= ALL METHOD / FUNTION/ VARIABLE/ TYPEDEF's =================================
///1.abs
///2.sq
///3.max
///min
///swap

/// ----------------------------------------------------- NUMBER   THEORY -----------------------------------------------------------------------------------------
///bigmod
///gcd
///lcm
///nCr
///fib
///catalan formula
///derangement formula
///arithmetic progression
///geometric progression
///bionomial
///sieve                      prime
///isPime()
///primeFactor()
///numPF()
///numDiv()
///sumDiv()
///EulerPhi()
///euclid  // linear diophantine equation
///fact

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

///=================================================== STRING ALGORITHM ===========================================================
///KMPSearch
///RobinKarpsearch
///Edit Distance
///LCS
///longest common Prefix
/// longest repeated substring
//

/// ==================================================  SORTING ======================================================================
///q_sort
///
///


///==================================================JAVA BIGINTEGER ==================================================================
///Java BigInteger .... after the main() function ,,



///======================================================= FOR USING STANDARD LIBRARY==============================================================

using namespace std;
#include<bits/stdc++.h>
///=========================================FOR TAKING INPUT OF ANY TYPE , till 4 parameter====================================================

///inline void make(string &a) { string s ; if(scanf("%s",s)); a = s; }
inline void make(int &a)
{
    if(scanf("%d", &a));
}
inline void make(float &a)
{
    if(scanf("%f", &a));
}
inline void make(double &a)
{
    if(scanf("%lf", &a));
}
inline void make(char *a)
{
    if(scanf("%s", a));
}
inline void make(char &a)
{
    if(scanf(" %c", &a));
}
inline void makec(char &a)
{
    if(scanf("%c", &a));
}

template<typename A, typename B> inline void make(pair<A, B> & p)
{
    make(p.first);
    make(p.second);
}
template<typename A>
inline void maketab(A *tab, int size)
{
    for(int i = 0; i < size; i++) make(tab[i]);
}
template<typename A>
inline void maketab(vector<A> &v, int size)
{
    typedef typename vector<A>::iterator iter;
    v.resize(size);
    for(iter i = v.begin(); i != v.end(); i++) make(*i);
}

template<typename A, typename B>
inline void make(A &a, B &b)
{
    make(a);
    make(b);
}
template<typename A, typename B, typename C>
inline void make(A &a, B &b, C &c)
{
    make(a);
    make(b);
    make(c);
}
template<typename A, typename B, typename C, typename D>
inline void make(A &a, B &b, C &c, D &d)
{
    make(a);
    make(b);
    make(c);
    make(d);
}
template<typename A, typename B, typename C, typename D, typename E>
inline void make(A &a, B &b, C &c, D &d, E &e)
{
    make(a);
    make(b);
    make(c);
    make(d);
    make(e);
}





/// ==========================================================  FOR LESS WRITING OF ll, vector,pair, map , push,size,traverse objects===================
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

///size, push
#define sz(a) int((a).size())
#define pb push_back

///traverse all container
#define all(c) c.begin(),c.end()

///loop through all container
#define tr(c,it)\
            for(typeof(c.begin()) it=(c).begin();it!=(c).end();it++)

///=============================================================== FOR USING FOR LOOP, (FORALL,FOR) ============================================
#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)


//abs of any numbers
#define abs(x) (((x) < 0) ? - (x) : (x))
#define sq(x) x*x
//value of pi
#define PI 2*acos (0.0)
//}
//typedef long long ll;
typedef unsigned long long llu;
#define mem(a,v) memset(a,v,sizeof(a)) //need to see in the internet
//#define all(a) a.begin(),a.end() //it is also unclear
/*
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
*/

#define OC printf("Case %d:",i)


///===================================================================================================================================
///====================================================================================================================================
///===============================================================max of two numbers=====================================================
//--------------------
template <class T, class U> inline T max(T &a, U &b)
{
    return a > b ? a : b;
}





///================================================================min of two numbers=========================================================
//...................
template <class T, class U> inline T min(T &a, U &b)
{
    return a < b ? a : b;
}






///=================================================================swap two numbers===========================================================
//....................
template <class T, class U> inline T swap(T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}




///=============================================================function for calculating BIGMOD===================================================
//................................
template<class T>
T bigmod(T b, T p, T m)  // b^p % m type
{
    if (p == 0)return 1;
    else if (p % 2 == 0)return sq(bigmod(b, p / 2, m)) % m;
    else return ((b%m) % bigmod(b, p - 1, m)) % m;
}//....end of the code bigmod






///================================================================code for GCD==================================================================
//..................
template <class T>
T gcd(T a, T b)
{
    /*
    if (a%b)return b;
    else return (b, a%b);
    */
    while (b > 0)
    {
        a = a%b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;

}//...end of the code gcd






///========================================================     code for lcm     ==============================================================
//.....................
template<class T>
T lcm(T a, T b)
{
    return ((a*b) / gcd(a, b));
}







///=====================================================        code for nCr   ==================================================================
//....................
template <class T>
void Divbygcd(T& a, T& b)
{
    if (a > 0 && b > 0)
    {
        T g = gcd(a, b);
        if (g > 0)
        {
            a /= g;
            b /= g;
        }
    }
}
template<class T>
T nCr(T n, T k)
{
    T numerator = 1;
    T denominator = 1;
    T toMul;
    T toDiv;
    T i;
    if (k > n/2)k = n - k;
    for (i = k; i; i--)
    {
        toMul = n - k + i;
        toDiv = i;
        Divbygcd(toMul, toDiv);
        Divbygcd(numerator, toDiv);
        Divbygcd(toMul, denominator);
        numerator *= toMul;
        denominator *= toDiv;
    }
    return numerator / denominator;

} //... end of the code of nCr






///==================================================     n'th fibonacci number     ==========================================================
//....................
template<class T>
T fib(T n)
{
    T i, h, j, k , t;
    i = h = 1;
    j = k = 0;
    while (n > 0)
    {
        if (n % 2 == 1)   // if n is odd
        {
            t = j*h;
            j = i*h + j*k + t;
            i = i*k + t;
        }
        t = h*h;
        h = 2 * k*h + t;
        k = k*k + t;
        n = (int)n / 2;
    }
    return j;

} // ......... endl of fibonacci function ..


/// ====================================================== DERENGEMENT =========================================================================

///der(n) = (n-1) * (der(n-1) + der(n-2)) ;  der(0) = 1 ; der(1) = 0;




/// ===================================================   CATALAN  ============================================================================================
///Application: number of distinc binary trees , conting number of parenthesis, parenthesizing factors, polygon to triangled , monotonic path of n*n grid(206 s&h)

/// cat(n) = (2n C n)/(n+1) ;  or ,
/// cat(n) = ( (2*m*(2*m-1)) / ((m+1)*m) )  * cat(n-1) ;


/// ========================================================= Arithmetic Progression ===============================================================

/// S = (n/2) *(2*a + (n-1) *d) ;


/// ========================================================   Geometric Progression ==================================================================

/// S = a * ( (1-pow(r,n)) / (1-r) ) ;



/// ====================================================== BIONOMIAL CO-EFFCIENT ====================================================================

///C(n,0) = C(n,n) = 1;
/// C(n,k) = C(n-1,k-1) + C(n-1,k) ;




///======================================================   sieve PRIME GENERATORE   =============================================================
//...........................

void sieve(int L, int U)   //give prime between L & U
{
    int i, j, d;
    d = U - L + 1; /* from range L to U, we have d=U-L+1 numbers. */
    /* use flag[i] to mark whether (L+i) is a prime number or not. */
    bool *flag = new bool[d];
    for (i = 0; i<d; i++) flag[i] = true; /* default: mark all to be true */
    for (i = (L % 2 != 0); i<d; i += 2) flag[i] = false;
    /* sieve by prime factors staring from 3 till sqrt(U) */
    for (i = 3; i <= sqrt(U); i += 2)
    {
        if (i>L && !flag[i - L]) continue;
        /* choose the first number to be sieved -- >=L,
        divisible by i, and not i itself! */
        j = L / i*i;
        if (j<L) j += i;
        if (j == i) j += i; /* if j is a prime number, have to start form next
							one */
        j -= L; /* change j to the index representing j */
        for (; j<d; j += i) flag[j] = false;
    }
    if (L <= 1) flag[1 - L] = false;
    if (L <= 2) flag[2 - L] = true;
    for (i = 0; i<d; i++) if (flag[i]) cout << (L + i) << " ";
    cout << endl;
}//..........end of sieve prime generator ........

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i =2; i<=_sieve_size; i++)if(bs[i])
        {
            for(ll j=i*i; j <=_sieve_size; j+=i)bs[j] = 0;
            primes.push_back((int)i);
        }

}

bool isPrime(ll N)
{
    if(N<=_sieve_size)return bs[N];
    FOR(i,(int)primes.size())
    {
        if(N%primes[i] == 0)return false;
    }
    return true;
}
vi primeFactor(ll N)
{
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF*PF<=N)
    {
        while(N%PF == 0)
        {
            N/=PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if(N!=1)factors.push_back(N);
    return factors;
}
/// vi r = primeFactor(142391208960LL);

ll numPF(ll N)
{
    ll PF_idx = 0,PF = primes[PF_idx],ans = 0;
    while(PF*PF <=N)
    {
        while(N%PF == 0)
        {
            N/=PF;
            ans++;
        }
        PF = primes[++PF_idx];
    }
    if(N !=1)ans++;
    return ans;
}

//numDiffPF(N)
//sumPF(N)

///number of divisors of N
ll numDiv(ll N)
{
    ll PF_idx = 0,PF = primes[PF_idx],ans = 1;
    while(PF*PF <=N)
    {
        ll power = 0;
        while(N%PF == 0)
        {
            N/=PF;
            power++;
        }
        ans *= (power+1);
        PF = primes[++PF_idx];
    }
    if(N!=1)ans == 2;
    return ans ;
}
///sum of the divisors of N
ll sumDiv(ll N)
{
    ll PF_idx = 0,PF = primes[PF_idx],ans = 1;
    while(PF*PF <=N)
    {
        ll power = 0;
        while(N%PF == 0)
        {
            N/=PF;
            power++;
        }
        ans *=((ll)pow((double)PF,power+1.0)-1)/(PF-1)  ;
        PF = primes[++PF_idx];
    }
    if(N!=1)ans *=((ll)pow((double)N,2.0)-1)/(N-1)  ;
    return ans ;

}


///EulerPhi(N) returns relatively prime < N
ll EulerPhi(ll N)
{
    ll PF_idx = 0,PF = primes[PF_idx],ans = N;
    while(PF*PF<=N)
    {
        if(N%PF == 0)ans -=ans/PF;
        while(N%PF ==0)N/=PF;
        PF = primes[++PF_idx];
    }
    if(N!=1)ans -= ans/N;
    return ans;
}



/// ============================================================lINEAR DIOPHanTINE EQUATION ==========================================

//Store x, y, d is a global variable

int x_diophantine = 0,y_diophantine = 0;

int d_diophantine;// = gcd(a,b);

void euclid(int a,int b)
{
    if (b == 0)
    {
        x_diophantine =1;
        y_diophantine=0;
        d_diophantine=a;
        return;
    }
    euclid(b,a%b);
    int x1 = y_diophantine;
    int y1 = x_diophantine-(a/b)*y_diophantine;
    x_diophantine = x1;
    y_diophantine = y1;
}


/// ==================================================  code for factorial =====================================================================
//.......................
template <class T>
T fact(T n)
{
    T sum = 1 , i;
    for (i = 1; i <= n; i++)
    {
        sum = sum*i;
    }
    return sum;
}
 ///...............................end of NUMber Theory



int isvowel(char ch) { // make sure ch is in lowercase
  char vowel[12] = "aeiouAEIOU";
  for (int j = 0; vowel[j]; j++)
    if (vowel[j] == ch)
      return 1;
  return 0;
}




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

///MATRIX CHAIN MULTIPICATION
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



///Longest Palindromic Subsequence ( DP + STRING)
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;

   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;

   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;

   // If the first and last characters do not match
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}


/// ======================================================= G R A P H ===============================================================



///DFS

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;

void printThis(char* message) {
  printf("==================================\n");
  printf("%s\n", message);
  printf("==================================\n");
}

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;

void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
  printf(" %d", u);                                    // this vertex is visited
  dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
      dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
} }


///Flood Fill
// note: this is not the version on implicit graph
void floodfill(int u, int color) {
  dfs_num[u] = color;                            // not just a generic DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      floodfill(v.first, color);
} }

vi topoSort;             // global vector to store the toposort in reverse order

void dfs2(int u) {    // change function name to differentiate with original dfs
  dfs_num[u] = DFS_BLACK;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      dfs2(v.first);
  }
  topoSort.push_back(u); }                   // that is, this is the only change

#define DFS_GRAY 2              // one more color for graph edges property check
vi dfs_parent;      // to differentiate real back edge versus bidirectional edge


///Graph Edge Checking

void graphCheck(int u) {               // DFS for checking graph edge properties
  dfs_num[u] = DFS_GRAY;   // color this as DFS_GRAY (temp) instead of DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE) {     // Tree Edge, DFS_GRAY to DFS_WHITE
      dfs_parent[v.first] = u;                  // parent of this children is me
      graphCheck(v.first);
    }
    else if (dfs_num[v.first] == DFS_GRAY) {             // DFS_GRAY to DFS_GRAY
      if (v.first == dfs_parent[u])          // to differentiate these two cases
        printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
      else  // the most frequent application: check if the given graph is cyclic
        printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
    }
    else if (dfs_num[v.first] == DFS_BLACK)             // DFS_GRAY to DFS_BLACK
      printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
  }
  dfs_num[u] = DFS_BLACK;     // after recursion, color this as DFS_BLACK (DONE)
}

vi dfs_low;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;



void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
      dfs_parent[v.first] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v.first);

      if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v.first] > dfs_num[u])                           // for bridge
        printf(" Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
    }
    else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
} }

vi S, visited;                                    // additional global variables
int numSCC;


///
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
    printf("SCC %d:", ++numSCC);            // this part is done after recursion
    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
      printf(" %d", v);
      if (u == v) break;
    }
    printf("\n");
} }


///BFS
/*
Graph is considered to be stored as adjacent vertices list.
Also we considered graph undirected.

vvi is vector< vector<int> >
W[v] is the list of vertices adjacent to v
*/

 int NB; // number of vertices
 vvi WB; // lists of adjacent vertices


 bool check_graph_connected_bfs() {
      int start_vertex = 0;
      vi V(NB, false);
      queue<int> Q;
      Q.push(start_vertex);
      V[start_vertex] = true;
      while(!Q.empty()) {
           int i = Q.front();
           // get the tail element from queue
           Q.pop();
           tr(WB[i], it) {
                if(!V[*it]) {
                     V[*it] = true;
                     Q.push(*it);
                }
           }
      }
      return (find(all(V), 0) == V.end());
 }



///DJKSTRA  Sortest Path Algorithm


const int MAX = 1001;
const int MAXINT = 1000000000;

vvii GG(MAX);
vi DD(MAX, MAXINT);

void Dijkstra(int s)
{
    set<ii> Q;
    DD[s] = 0;
    Q.insert(ii(0,s));

    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;

        //for (vii::const_iterator it = GG[v].begin(); it != GG[v].end(); it++)
        tr(GG[v],it)
        {
            int v2 = it->first;
            int cost = it->second;
            if (DD[v2] > DD[v] + cost)
            {
                if (DD[v2] != 1000000000)
                {
                    Q.erase(Q.find(ii(DD[v2], v2)));
                }
                DD[v2] = DD[v] + cost;
                Q.insert(ii(DD[v2], v2));
            }
        }
    }
}

/*

int m, s, t = 0;
    scanf("%d %d %d %d", &n, &m, &s, &t);

    for (int i = 0; i < m; i++)
    {
        int a, b, w = 0;
        scanf("%d %d %d", &a, &b, &w);
        G[a - 1].push_back(ii(b - 1, w));
        G[b - 1].push_back(ii(a - 1, w));
    }

    Dijkstra(s - 1);

    printf("%d\n", D[t - 1]);

*/


///prims kruskal MINIMUM SPANNING TREE

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<vii> AdjListPK;
vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges

void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjListPK[vtx].size(); j++) {
    ii v = AdjListPK[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }                                // sort by (inc) weight then by (inc) id
void prims_kruskal() {
  int V, E, u, v, w;

  /*
  // Graph in Figure 4.10 left, format: list of weighted edges
  // This example shows another form of reading graph input
  5 7
  0 1 4
  0 2 4
  0 3 6
  0 4 6
  1 2 2
  2 3 8
  3 4 9
  */

  //freopen("in_03.txt", "r", stdin);

  scanf("%d %d", &V, &E);
  // Kruskal's algorithm merged with Prim's algorithm
  AdjList.assign(V, vii());
  vector< pair<int, ii> > EdgeList;   // (weight, two vertices) of the edge
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);            // read the triple: (u, v, w)
    EdgeList.push_back(make_pair(w, ii(u, v)));                // (w, u, v)
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
  }
  sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                      // note: pair object has built-in comparison function

  int mst_cost = 0;
  UnionFind UF(V);                     // all V are disjoint sets initially
  for (int i = 0; i < E; i++) {                      // for each edge, O(E)
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
      mst_cost += front.first;                // add the weight of e to MST
      UF.unionSet(front.second.first, front.second.second);    // link them
  } }                       // note: the runtime cost of UFDS is very light

  // note: the number of disjoint sets must eventually be 1 for a valid MST
  printf("MST cost = %d (Kruskal's)\n", mst_cost);



// inside int main() --- assume the graph is stored in AdjList, pq is empty
  taken.assign(V, 0);                // no vertex is taken at the beginning
  process(0);   // take vertex 0 and process all edges incident to vertex 0
  mst_cost = 0;
  while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
    ii front = pq.top(); pq.pop();
    u = -front.second, w = -front.first;  // negate the id and weight again
    if (!taken[u])                 // we have not connected this vertex yet
      mst_cost += w, process(u); // take u, process all edges incident to u
  }                                        // each edge is in pq only once!
  printf("MST cost = %d (Prim's)\n", mst_cost);

  //return 0;
}


///BELMAN FORD
#define INF 1000000000

void belman_ford() {
  int V, E, s, a, b, w;
  vector<vii> AdjList;

  /*
  // Graph in Figure 4.18, has negative weight, but no negative cycle
  5 5 0
  0 1 1
  0 2 10
  1 3 2
  2 3 -10
  3 4 3

  // Graph in Figure 4.19, negative cycle exists
  3 3 0
  0 1 1000
  1 2 15
  2 1 -42
  */

  //freopen("in_06.txt", "r", stdin);

  scanf("%d %d %d", &V, &E, &s);

  AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &a, &b, &w);
    AdjList[a].push_back(ii(b, w));
  }

  // Bellman Ford routine
  vi dist(V, INF); dist[s] = 0;
  for (int i = 0; i < V - 1; i++)  // relax all E edges V-1 times, overall O(VE)
    for (int u = 0; u < V; u++)                        // these two loops = O(E)
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];        // we can record SP spanning here if needed
        dist[v.first] = min(dist[v.first], dist[u] + v.second);         // relax
      }

  bool hasNegativeCycle = false;
  for (int u = 0; u < V; u++)                          // one more pass to check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[v.first] > dist[u] + v.second)                 // should be false
        hasNegativeCycle = true;     // but if true, then negative cycle exists!
    }
  printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

  if (!hasNegativeCycle)
    for (int i = 0; i < V; i++)
      printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);


}


///FLYOD WARSHALL

void flyod_warshall(){
  int V, E, u, v, w, AdjMatrix[200][200];

  /*
  // Graph in Figure 4.30
  5 9
  0 1 2
  0 2 1
  0 4 3
  1 3 4
  2 1 1
  2 4 1
  3 0 1
  3 2 3
  3 4 5
  */

  //freopen("in_07.txt", "r", stdin);

  scanf("%d %d", &V, &E);
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      AdjMatrix[i][j] = INF;
    AdjMatrix[i][i] = 0;
  }

  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    AdjMatrix[u][v] = w; // directed graph
  }

  for (int k = 0; k < V; k++) // common error: remember that loop order is k->i->j
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      printf("APSP(%d, %d) = %d\n", i, j, AdjMatrix[i][j]);

}





/// ======================================================== STRING ALGO =============================================================
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

/*
char *txt = "ABABDABACDABABCABAB";
    char *pat = "AB";
    KMPSearch(pat, txt);
*/


///----------------------------------------------------------------------------
#define rd 256
void RobinKarpsearch(char *pat, char *txt, int q) //q prime number
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*rd)%q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (rd*p + pat[i])%q;
        t = (rd*t + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text and pattern
        // If the hash values match then only check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            {
                printf("Pattern found at index %d \n", i);
            }
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if ( i < N-M )
        {
            t = (rd*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it to positive
            if(t < 0)
              t = (t + q);
        }
    }
}
/*
char *txt = "GEEKS FOR GEEKS";
    char *pat = "GEEK";
    int q = 101;  // A prime number
    RobinKarpsearch(pat, txt, q);
*/



///EDIT DISTANCE
//minimum number of edits (operations (replace,insert,delete)) required to convert one string into another.

#define SENTINEL (-1)
#define EDIT_COST (1)
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}

// Strings of size m and n are passed.
// Construct the Table for X[0...m, m+1], Y[0...n, n+1]
int EditDistanceDP(char X[], char Y[])
{
    // Cost of alignment
    int cost = 0;
    int leftCell, topCell, cornerCell;

    int m = strlen(X)+1;
    int n = strlen(Y)+1;

    // T[m][n]
    int *T = (int *)malloc(m * n * sizeof(int));

    // Initialize table
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            *(T + i * n + j) = SENTINEL;

    // Set up base cases
    // T[i][0] = i
    for(int i = 0; i < m; i++)
        *(T + i * n) = i;

    // T[0][j] = j
    for(int j = 0; j < n; j++)
        *(T + j) = j;

    // Build the T in top-down fashion
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // T[i][j-1]
            leftCell = *(T + i*n + j-1);
            leftCell += EDIT_COST; // deletion

            // T[i-1][j]
            topCell = *(T + (i-1)*n + j);
            topCell += EDIT_COST; // insertion

            // Top-left (corner) cell
            // T[i-1][j-1]
            cornerCell = *(T + (i-1)*n + (j-1) );

            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            cornerCell += (X[i-1] != Y[j-1]); // may be replace

            // Minimum cost of current cell
            // Fill in the next cell T[i][j]
            *(T + (i)*n + (j)) = Minimum(leftCell, topCell, cornerCell);
        }
    }

    // Cost is in the cell T[m][n]
    cost = *(T + m*n - 1);
    free(T);
    return cost;
}

// Recursive implementation
int EditDistanceRecursion( char *X, char *Y, int m, int n )
{
    // Base cases
    if( m == 0 && n == 0 )
        return 0;

    if( m == 0 )
        return n;

    if( n == 0 )
        return m;

    // Recurse
    int left = EditDistanceRecursion(X, Y, m-1, n) + 1;
    int right = EditDistanceRecursion(X, Y, m, n-1) + 1;
    int corner = EditDistanceRecursion(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);

    return Minimum(left, right, corner);
}


///LCS
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

///longest repeated substring
string repeated_substring(string &str) {
    int len = str.length();

    int **c = new int*[len + 1];
    for (int i = 0; i <= len; ++i)
        c[i] = new int[len + 1];
    for (int i = 0; i <= len; ++i) {
        c[i][0] = 0;
        c[0][i] = 0;
    }

    int max_len = 0, index = len + 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str[i-1] == str[j-1] && abs(i-j) > c[i-1][j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                if (c[i][j] > max_len) {
                    max_len = c[i][j];
                    index = min(i, j);
                }
            } else {
                c[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= len; ++i)
        delete[] c[i];
    delete[] c;

    if (max_len > 0) {
        string ret = str.substr(index - max_len, max_len);
        for (int i = 0; i < max_len; ++i)
            if(ret[i] != ' ')
                return ret;
    }

    return "NONE";
}

///longest common prefix
string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prefix = "";

        if(strs.size() == 0) {
            return prefix;
        }

        //get the next char from first line
        char cur;
        int index = 0;
        while(index < strs[0].length()) {
            cur = strs[0][index];
            for(int i = 0; i < strs.size(); ++i) {
                if(cur != strs[i][index]) {
                    return prefix;
                }
            }
            ++index;
            prefix += cur;
        }


        return prefix;
    }




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






/// ============================================================ MAIN FUNCTION=================================================================
///============================================================================================================================================

int main(int argc, char const *argv[])
{

    /*
    FOR(i,5){
        cout << i << endl;
    }
    FORALL(i,0,4){
        cout << i << endl;
    }
    FORB(i,4,0)
    {
        cout << i << endl;
    }
    int i = 5;
    OC;
    */





    //sieve(10000000);
    return 0;

}











/// ============================================= STRING PROCESSING ===================================================================

///int isvowel(char ch)
///BUILT IN : strcpy(),strcat(),strlen(),strstr(),strtok(),strcmp(),isdigit(),isalpha(),tolower(),toupper(),

///void *memchr(const void *str, int c, size_t n) // return void pointer of the found char else NULL
///char *strchr(const char *str, int c)  //like memchr() ...
///char *strrchr(const char *str, int c) // return last occurnce pointer

///void *memcpy(void *dest, const void *src, size_t n)  // copy to dest till n bytes
///void *memmove(void *str1, const void *str2, size_t n)  // almost memcopy() but better for overlapping memory

///int memcmp(const void *str1, const void *str2, size_t n) // compare lexographically till n bytes
///int strcmp(const char *str1, const char *str2) // like memcmp()
///int strncmp(const char *str1, const char *str2, size_t n)

///void *memset(void *str, int c, size_t n) // set  value c till n'th byte

///char *strcat(char *dest, const char *src)
///char *strncat(char *dest, const char *src, size_t n)

///char *strcpy(char *dest, const char *src)
///char *strncpy(char *dest, const char *src, size_t n)

///size_t strcspn(const char *str1, const char *str2) // look for first occurence of str2 in str1

///char *strpbrk(const char *str1, const char *str2) // return first matching character

///char *strstr(const char *haystack, const char *needle)

///char *strtok(char *str, const char *delim)
/*
char str[] = "this, is the string - I want to parse";
char delim[] = " ,-";
char* token;

for (token = strtok(str, delim); token; token = strtok(NULL, delim))
{
    printf("token=%s\n", token);
}
*/
///size_t strxfrm(char *dest, const char *src, size_t n) //return length of formed string

/// String to Other Type Casting
/*
char sentence []="Rudolph is 12 years old";
  char str [20];
  int i;
  sscanf (sentence,"%s %*s %d",str,&i);
*/













///====================================================================================================================================
///========================================================================== JAVA BIGINTEGER ============================================================
///isProbablePrime(int certainty)  //certainty = 10 ( almost give correct anser -_- , try to avoid)
///gcd(BI)
///modPow(BI exponent , BI m)
///toString()

///for BaSE Convertion:      BigInteger p = new BigInteger(sc.next(),b) ; //convert the number to b base
