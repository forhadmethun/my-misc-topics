#include "D:\googleDrive\_CSE\Code\Library\1.head.cpp"
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





///===================================================================================================================================
///====================================================================================================================================
///===============================================================max of two numbers=====================================================
//--------------------
template <class T, class U> inline T max(T &a, U &b)
{
    return a > b ? a : b;
}
//input : two data ,
//output: maximum data




///================================================================min of two numbers=========================================================
//...................
template <class T, class U> inline T min(T &a, U &b)
{
    return a < b ? a : b;
}
//input : two data
//output: minimum data






///=================================================================swap two numbers===========================================================
//....................
template <class T, class U> inline T swap(T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//input : two data as reference
//output: two data with swap value ..



///=============================================================function for calculating BIGMOD===================================================
//................................
/*
template<class T>
T bigmod(T b, T p, T m)  // b^p % m type
{
    if (p == 0)return 1;
    else if (p % 2 == 0)return sq(bigmod(b, p / 2, m)) % m;
    else return ((b%m) % bigmod(b, p - 1, m)) % m;
}//....end of the code bigmod


*/

#define MOD 1000000007
long long bigmod(long long m,long long n)
{
  if(n==1)return m;
  long long v;
  v= bigmod(m,n/2)%MOD;
  if(n%2==0)
    return (v*v)%MOD;
  else return ((v*v)%MOD*m)%MOD;
}
//input : two, long long type data , m & n
//output: long long type value of  , m^n % MOD





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
//input : two value
//output: GCD value of the given two data





///========================================================     code for lcm     ==============================================================
//.....................
template<class T>
T lcm(T a, T b)
{
    return ((a*b) / gcd(a, b));
}
//input : two value
//output: LCM value of the given two data








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
//input : n  , r
//output: nCr



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
//input : a value
//output: a'th FIBONACCI NUMBER

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
///input : L , U
///output: all prime between L , U





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
///input : upper bound(long long type value)
///output: save all prime within the range to "vector prime"

bool isPrime(ll N)
{
    if(N<=_sieve_size)return bs[N];
    F(i,(int)primes.size())
    {
        if(N%primes[i] == 0)return false;
    }
    return true;
}
///input : a number
///output: return true if prime else false ..


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
///to use it first call sieve( *upperbound )
///input : long long integer value
///output: vector of integer which  contains all the prime factor of the LL N




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
///input :a long long value
///output: how many prime number is needed to make the number

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
///input : a long long integer number
///output: how many divisior it has




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
///input : a long long integer number
///output: sum of all  divisior it has



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
///input : a long long integer number
///output: return long long value which is relatively prime




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
///input : two ineteger a,b
///output: x_diophantine, y_diophantine ....


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
///input :   a value
///output:   factorial of the value


int main()
{
    //sieve(1,100);
    sieve(100000+10);
    for(int i=0;i<primes.size();i++){
        cout << primes[i] << endl;
    }
//    long long a = 49;
//    vi r = primeFactor(a);
//    //cout << r[0] << endl;
//    //cout << numDiv(9) << endl;
//    cout << EulerPhi(15) << endl;
//    cout << EulerPhi(5) << endl;

    return 0;
}
