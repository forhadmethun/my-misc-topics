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



#define DFS_WHITE -1
#define DFS_BLACK 1

void printThis(char* message){
    printf("===========================\n");
    printf("%s\n",message);
    printf("===========================\n");
}

vector<vii> AdjList;
int V,E,u,v,w;

vi dfs_num;
int numCC;

//dfs of a grpah
void dfs(int u){
    //first visit a node
    printf(" %d",u);
    dfs_num[u] = DFS_BLACK;
    //collect all the adjacent node to that visited node
    for(int i=0;i<(int)AdjList[u].size();i++){
        ii v= AdjList[u][i];
        //if any adjacent node is not visited yet visit that node
        if(dfs_num[v.first] == DFS_WHITE){
            //recursively call dfs of the visited node...
            dfs(v.first);
        }

    }

}


//floodfill of implicit graph
void floodfill(int u,int color)
{
    dfs_num[u] = color;
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v= AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE){
            floodfill(v.first,color);
        }
    }

}

//topological sort
vi topoSort;
void dfs2(int u)
{
    dfs_num[u] = DFS_BLACK;
    for(int i=0;i<(int)AdjList[u].size();i++){
        ii v= AdjList[u][i];
        if(dfs_num[v.first] == DFS_WHITE){
            dfs2(v.first);
        }
    }
    topoSort.push_back(u);
}

#define DFS_GRAY 2
vi dfs_parent;
void graphCheck(int u){
    dfs_num[u] = DFS_GRAY;
    for(int i=0;i<(int)AdjList[u].size();i++){
        ii v= AdjList[u][i];
        if(dfs_num[v.first] == DFS_WHITE){
            dfs_parent[v.first] = u;
            graphCheck(v.first);
        }
        else if(dfs_num[v.first] == DFS_GRAY){
            if(v.first == dfs_parent[u]){
                printf(" Bidirectional (%d,%d)-(%d,%d)\n",u,v.first,v.first,u);
            }
            else{
                printf(" Back edge (%d,%d)(cycle)\n",u,v.first);
            }
        }
        else if(dfs_num[v.first] == DFS_BLACK){
            printf(" Forward /Cross edge (%d,%d)\n",u,v.first);
        }
    }
    dfs_num[u] = DFS_BLACK;
}

vi s,visited,dfs_low;
int dfsNumberCounter, dfsRoot, rootChildren;
int numSCC;

//review about the codes...
void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    s.push_back(u);
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE){
            tarjanSCC(v.first);
        }
        if(visited[v.first]){
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        }
    }
}
//study about ariticular point
//study about tarjanSSC


int main(){
    freopen("D:\\googleDrive\\_CSE\\_dayWise_work\\2016\\july_august_september_oct_nov_dec\\Oct\\URI_BEGINNER\\in.txt","r",stdin);

    //GRAPH INPUT
    int V,total_neighbors,id,weight;
    cin >> V;
    AdjList.assign(V,vii());
    for(int loop1=0;loop1<V;loop1++){
        scanf("%d",&total_neighbors);
        for(int loop2=0;loop2<total_neighbors;loop2++){
            cin >> id >> weight;
            AdjList[loop1].push_back(ii(id,weight));
        }
    }


    //DFS DEMO
    cout << "DFS DEMO: " << endl;

    numCC = 0;
    dfs_num.assign(V,DFS_WHITE);
    //for every vertices run DFS
    // it will mark all connected nodes of a node and increment count
    //as connected component
    for(int i=0;i<V;i++){
        if(dfs_num[i] == DFS_WHITE){
            printf("Component %d:",++numCC),dfs(i),printf("\n");
        }
    }


    //FLOODFILL
    cout <<"FLOODFILL DEMO: " << endl;
    numCC = 0;

    //assign all the nodes initially white
    dfs_num.assign(V,DFS_WHITE);


    for(int i=0;i<V;i++){
        if(dfs_num[i] == DFS_WHITE)floodfill(i,++numCC);
    }
    for(int i=0;i<V;i++){
        printf("vertex %d has color %d\n",i,dfs_num[i]);
    }
    printThis("Topological Sort:");
    topoSort.clear();
    dfs_num.assign(V,DFS_WHITE);
    for(int i=0;i<V;i++){
        if(dfs_num[i] == DFS_WHITE){
            dfs2(i);
        }
    }
    reverse(topoSort.begin(),topoSort.end());
    for(int i=0;i<(int)topoSort.size();i++){
        printf(" %d",topoSort[i]);
    }
    cout << endl;
    printThis("Graph Edges property check: ");
    numCC = 0;
    dfs_num.assign(V,DFS_WHITE);
    dfs_parent.assign(V,-1);
    for(int i=0;i<V;i++){
        if(dfs_num[i] == DFS_WHITE){
            printf("Component %d:\n",++numCC),graphCheck(i);
        }
    }


    return 0;
}

