///=================================================== STRING ALGORITHM ===========================================================
///KMPSearch
///RobinKarpsearch
///Edit Distance
///LCS
///longest common Prefix
/// longest repeated substring
//



// ======================================================== STRING ALGO =============================================================
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

