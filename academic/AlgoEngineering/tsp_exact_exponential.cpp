#include<bits/stdc++.h>
#include <time.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define  EPS 1e-9

#define  V 8 // initially let only 15 vertices...you can change in future...
#define s 0 //starting town, used for finding route
#define DFS_BLACK 1
#define DFS_WHITE -1
struct point{
    int x,y;
    point(int _x,int _y){
        x = _x;
        y = _y;
    }
    point(){
        x = 0;
        y = 0;
    }
    bool operator < (point other){
        if(fabs(x- other.x) >  EPS){
            return x < other.x;
        }
        return y < other.y;
    }
};

vector<vii> AdjList; //for storing the graph
//priority_queue< pair<int, ii> > pq; //for mst
priority_queue<ii> pq;
vector<point> inputPoints,pointCloud; // for taking points from file

vi taken,dfs_num; // for keep track of taken nodes

vector<int> p,q; // keep track of parents


//void printPath(int u) {    // simple function to extract information from `vi p'
//    if (u == s) { printf("%d", u); return; }
//    printPath(p[u]);   // recursive call: to make the output format: s -> ... -> t
//    printf(" %d-", u);
//}


//distance between two points
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

//processing all of the adjcent vertex connected to vtx
void process(int vtx) {// so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
    }
}  // sort by (inc) weight then by (inc) id

//simply take input from the input file of points and store point vector
void input(){
    freopen("D:\\googleDrive\\_CSE\\Code\\out.txt","r",stdin);
    for(int i=0;i<V;i++)
    {
        // srand (i*time(NULL));
        //  int randX = (rand()%100);
        // int randY = (rand()%100);
        int randX,randY;
        cin >> randX >> randY;
        cout << "--> " << randX << endl;
        pointCloud.push_back(point(randX,randY));
        // inputPoints.push_back(point(randX,randY));
        //  printf("%d %d\n",randX,randY);
    }
}


//minimum spanning tree
void mst(){
    input();


    string str= "";
    AdjList.assign(V, vii());
    for(int i=0;i<V;i++){
        for(int j=0; j<V;j++){
            if(j==i)continue;
            int id = j;
            int weight = (int) dist(pointCloud[i],pointCloud[j]);
            AdjList[i].push_back(ii(j,weight));
        }
    }

    int u,v,w,mst_cost,temp;
     q.push_back(0);

    p.assign(V,-1);

    taken.assign(V, 0);   // no vertex is taken at the beginning
    process(0);// take vertex 0 and process all edges incident to vertex 0
    //cout << "-----------------> " << (int)pq.size() << endl;
    mst_cost = 0;
    u = 0;
    temp = 0;

    while (!pq.empty()){// repeat until V vertices (E=V-1 edges) are taken
        ii front = pq.top(); pq.pop();
        temp = u;
        u = -front.second, w = -front.first;  // negate the id and weight again
       // q.push(u);
        if (!taken[u]) {                // we have not connected this vertex yet
            q.push_back(u);
            p[u] = temp;
            //cout << " --> " << u << endl;
            mst_cost += w, process(u); // take u, process all edges incident to u
           // q.push(u);
        }
    }                                        // each edge is in pq only once!
    printf("MST cost = %d (Prim's)\n", mst_cost);
    //cout << q.size() << endl;



  //  freopen("D:\\googleDrive\\_CSE\\Code\\graph.txt","w",stdout);
    for(auto it = q.begin();it!=q.end();it++){
        cout << pointCloud[*it].x << " " << pointCloud[*it].y  << endl;
    }
    cout << endl;



}


void dfs(int u) {
    printf(" %d", u);
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs(v.first);
    }
}
//generate random points on 2D plane -- initially 15 points...
//So, V = 15;

void generatePointCloud(int limit)
{
    //cout << "dhuksi " << endl;
//    pointCloud.clear();
//    inputPoints.clear();
    freopen("D:\\googleDrive\\_CSE\\Code\\out.txt","w",stdout);
    for(int i=0;i<limit;i++)
    {
     //   cout << "i " << endl;
        srand (i*time(NULL));
        int randX = (rand()%100);
        int randY = (rand()%100);

       // pointCloud.push_back(point(randX,randY));
       // inputPoints.push_back(point(randX,randY));
        printf("%d %d\n",randX,randY);
    }

}





//cost of traversing all points in a vector
double cost(vector<point> v){
    double sum = 0;
    for(int i=0;i<(int)v.size()-1;i++){
        sum+=dist(v[i],v[i+1]);
    }
    return sum;
}

//exact_exponential_model for TSP problem
void exact_expoinential_method(){
    //freopen("D:\\googleDrive\\_CSE\\Code\\in.txt","r",stdin);
    input();
    vector<point> vp(pointCloud);
   // cout << vp.size() << endl;
    ///*
    /*
    int n;scanf("%d",&n);
    for(int i=0;i < n;i++){
        point temp;
        scanf("%d%d",&temp.x,&temp.y);
        vp.push_back(temp);
    }

    cout << n << endl;
    */
    int count = 0;
    double cst = (double)INT_MAX;
    do
    {
        vector<point> p(vp);
        p.push_back(p[0]);
        for(int i=0;i<(int)p.size();i++){
            cout << "(" <<  p[i].x << "," << p[i].y << ") ";
        }

        double c = cost(p);
        if(c < cst){
            cst = c;
        }
        cout << "  Cost: " << c << endl;
        count ++ ;
    }while(next_permutation(vp.begin(),vp.end()));
    cout << cst << endl;


}
int main(){

    //


    //
    //


    /*
    //printing data of input file
    for(int i=0;i<V;i++){
        cout << pointCloud[i].x << "-" << pointCloud[i].y << endl;
    }
     */

    //
    //

//    generatePointCloud(V);

    clock_t tStart = clock();
    exact_expoinential_method();

    //mst();
    printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);





    //cout << endl;
   // printPath(12);

    /*
     //Printing data of Graph....
    for(int i=0;i<AdjList[0].size();i++){
        cout << "(" <<  pointCloud[0].x << "-" <<pointCloud[0].y << ")"  << "- ("<<pointCloud [AdjList[0][i].first].x << ","<<  pointCloud [AdjList[0][i].first].y << ") ->" << AdjList[0][i].second << endl;
    }
    */


    return 0;
}