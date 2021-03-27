using namespace std;
#include<bits/stdc++.h>

///=========================================FOR TAKING INPUT OF ANY TYPE , till 4 parameter====================================================
///inline void make(string &a) { string s ; if(scanf("%s",s)); a = s; }
inline void make(int &a) { if (scanf("%d", &a)) {}}

inline void make(float &a) { if (scanf("%f", &a)) {}}

inline void make(double &a) { if (scanf("%lf", &a)) {}}

inline void make(char *a) { if (scanf("%s", a)) {}}

inline void make(char &a) { if (scanf(" %c", &a)) {}}

inline void makec(char &a) { if (scanf("%c", &a)) {}}

template<typename A, typename B>
inline void make(pair<A, B> &p) {
    make(p.first);
    make(p.second);
}

template<typename A>
inline void maketab(A *tab, int size) { for (int i = 0; i < size; i++) make(tab[i]); }

template<typename A>
inline void maketab(vector<A> &v, int size) {
    typedef typename vector<A>::iterator iter;
    v.resize(size);
    for (iter i = v.begin(); i != v.end(); i++) make(*i);
}

template<typename A, typename B>
inline void make(A &a, B &b) {
    make(a);
    make(b);
}

template<typename A, typename B, typename C>
inline void make(A &a, B &b, C &c) {
    make(a);
    make(b);
    make(c);
}

template<typename A, typename B, typename C, typename D>
inline void make(A &a, B &b, C &c, D &d) {
    make(a);
    make(b);
    make(c);
    make(d);
}

template<typename A, typename B, typename C, typename D, typename E>
inline void make(A &a, B &b, C &c, D &d, E &e) {
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
typedef vector<vii> vvii; //think about 2D matrix of pair
//typedef set<int> si;
//typedef map<string, int> msi;
typedef unsigned long long llu;
//typedef map<int,string> mis;

///size, push
#define sz(a) int((a).size())
#define pb push_back




///traverse all container
#define all(c) c.begin(),c.end()

///=============================================================== FOR USING FOR LOOP, (FORALL,FOR) ============================================


#define FA(i, a, b) for(int i=(a);i<=(b);++i)
#define F(i, n) for(int i=0;i<(n);++i)
#define FB(i, a, b) for(int i=(a);i>=(b);--i)


//abs of any numbers
#define abs(x) (((x) < 0) ? - (x) : (x))
#define sq(x) x*x
//value of pi
#define PI 2*acos (0.0)
//}
//typedef long long ll;

#define mem(a, v) memset(a,v,sizeof(a)) //need to see in the internet

#define C printf("Case %d:",tc)
#define debug printf("\nDEBUG\n");

#define fi freopen("D:\\googleDrive\\_CSE\\URI\\in.txt","r",stdin);
#define fo freopen("D:\\googleDrive\\_CSE\\URI\\out.txt","w",stdout);

long long int read_int(){
    char r;
    bool start=false,neg=false;
    long long int ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg)
        return ret;
    else
        return -ret;
}


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    fi
    //fo
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a , b;
        //cin >> a >> b;
        scanf("%d%d",&a,&b);
        //cout << ( a* b) /2 << " cm2" <<  endl;
        printf("%d cm2\n",(a*b)/2);
    }




    return 0;
}

///Writer  : Md ForHad Hossain Methun
///Problem : URI 1585
///Time    :4, Dec,2016( 007.25AM - 07.28AM )




