using namespace std;
#include<bits/stdc++.h>
inline void make(int &a) { if(scanf("%d", &a)); }inline void make(float &a) { if(scanf("%f", &a)); }inline void make(double &a) { if(scanf("%lf", &a)); }inline void make(char *a) { if(scanf("%s", a)); }inline void make(char &a) { if(scanf(" %c", &a)); }inline void makec(char &a) { if(scanf("%c", &a)); }template<typename A, typename B> inline void make(pair<A, B> & p) { make(p.first); make(p.second); }template<typename A> inline void maketab(A *tab, int size) { for(int i = 0; i < size; i++) make(tab[i]); }template<typename A> inline void maketab(vector<A> &v, int size) { typedef typename vector<A>::iterator iter; v.resize(size); for(iter i = v.begin(); i != v.end(); i++) make(*i); }template<typename A, typename B> inline void make(A &a, B &b) { make(a); make(b); }template<typename A, typename B, typename C> inline void make(A &a, B &b, C &c) { make(a); make(b); make(c); }template<typename A, typename B, typename C, typename D> inline void make(A &a, B &b, C &c, D &d) { make(a); make(b); make(c); make(d); }template<typename A, typename B, typename C, typename D, typename E> inline void make(A &a, B &b, C &c, D &d, E &e) { make(a); make(b); make(c); make(d); make(e); }
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
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

///for loop short form
#define FA(i,a,b) for(int i=(a);i<=(b);++i)
#define F(i,n) for(int i=0;i<(n);++i)
#define FR(i,a,b) for(int i=(a);i>=(b);--i)


int main()
{
    freopen("D:\\googleDrive\\_CSE\\_dayWise_work\\2016\\july_august_september_oct_nov_dec\\Oct\\URI_BEGINNER\\in.txt","r",stdin);
    int V,E,total_neighbrs, id, weight, a,b;
    int AdjMat[100][100];
    vector<vii> AdjList;
    priority_queue< pair<int, ii> > EdgeList;
    //number of vertices
    cin >> V;

    //adjacency matrix representation....
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> AdjMat[i][j];
        }
    }


    for(int j=0;j<V;j++){
        if(AdjMat[0][j]){
            //print all the vertices connected to vertices 0

            printf("Edge 0-%d(Weight = %d)\n",j,AdjMat[0][j]);
        }
    }
    cin >> V;


    //Adjacency List Representation ...
    AdjList.assign(V,vii());
    for(int i=0;i<V;i++){
        scanf("%d",&total_neighbrs);
        for(int j=0;j<total_neighbrs;j++){
            scanf("%d %d",&id,&weight);
            AdjList[i].push_back(make_pair(id-1,weight));

        }
    }
    cout << "neighbors of vertex 0:\n" ;
    for(auto j=AdjList[0].begin();j!=AdjList[0].end();j++){
        cout << "Edge 0 - " << j->first << "  weight -" << j->second << endl;
    }

    //Edge List
    cin >> E;
    for(int i=0;i<E;i++){
        cin >> a>> b >> weight ;
        //EdgeList.push(make_pair(-weight,ii(a,b)));
        EdgeList.push(make_pair(-weight, ii(a, b)));
    }
    for(int i=0;i<E;i++){
        auto edge = EdgeList.top();EdgeList.pop();

        printf("%d (%d-%d)\n",-edge.first,edge.second.first,edge.second.second);

    }


    return 0;
}


