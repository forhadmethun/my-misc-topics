#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI acos(-1.0)

struct point{
    double x,y;
    point(){
        x = 0;
        y = 0;
    }
    point(double _x,double _y){
        x = _x;
        y = _y;
    }
    point operator=(point p){
        x = p.x;
        y = p.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
    bool operator > (point other){
        if(fabs(x-other.x) > EPS){
            return x > other.x;
        }
        return y < other.y;
    }
    bool operator < (point other){
        if(fabs(x- other.x) >  EPS){
            return x < other.x;
        }
        return y > other.y;
    }
};
class edge{
public:
    point p;
    point q;
    edge(point x,point y){
         p = x;
        q = y;
    }
    friend bool operator< (const edge &left, const edge &right);


};
double global_y;
map<edge, point> helper;
vector<edge> D;
bool operator< (const edge &left, const edge &right)
{
    //need to be edited
    double x1,x2;
    x1 = ((global_y - left.p.y)/(left.p.y - left.q.y))*(left.p.x - left.q.x) + left.p.x;
    x2 = ((global_y - right.p.y)/(right.p.y - right.q.y))*(right.p.x-right.q.x) + right.p.x;


    return x1  < x2 ;
}

set<edge> T;
map<int, point> m;
vector<point> vp;

class CompareNodePtr
{
public:
    bool operator ()(point a, point other) {
        if (fabs(a.y - other.y) < EPS) {
            return a.x > other.x;
        }
        return a.y < other.y;
    }
};

//struct line{ double a,b,c; };
//void pointsToLine(point p1,point p2,line &l1){
//    if(fabs(p2.x - p1.x) < EPS){
//        l1.a = 1.0;
//        l1.b = 0;
//        l1.c = -p1.x;
//    }
//    else{
//        l1.a = p1.y -p2.y;
//        l1.b = p2.x - p1.x;
//        l1.c = p2.y * p1.x - p1.y * p2.x;
//    }
//}
//double distToLineSegment(point p,point a,point b){
//    line l ;pointsToLine(a,b,l);
//    return fabs((p.x*l.a + p.y*l.b + l.c)/sqrt(l.a*l.a + l.b*l.b));
//}
struct vec { double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    if(ccw(a,o,b))
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
    else
        return 2.0*PI - acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));

}
enum {
    START, // 0
    SPLIT, // 1
    END, // 2
    MERGE, // 3
    REGULAR // 4
};
void prevNext(point &prev,point &next,point p){
    int size =(int) vp.size() ;
    // cout << "size: " << size << endl;
    for(int i=0;i<size;i++){
        if(vp[i] == p){
            // if(p == point(10,-1)) cout <<"-----------------> " << i << endl;
            if(i == 0){
                prev = vp[size - 1];
                next = vp[i+1];
            }
            else if( i== size -1){
                prev = vp[i-1];
                next = vp[0];
            }
            else{
                prev = vp[(i-1)];
                next = vp[(i+1)];
            }
            break;
        }
    }
}
int vertexType(point p){
    point prev, next;
    //map<int,point> ::iterator it = m.find(2);
    prevNext(prev,next,p);

//    cout << endl;
//    cout << "prev -> " << prev.x << "," << prev.y << endl;
//    cout << "cur -> " << p.x << "," << p.y << endl;
//    cout << "next -> " << next.x << "," << next.y << endl;
//    cout << endl;

    double interior_angle = angle(prev,p,next);
    // cout << "angle: -> " << interior_angle << endl;
    if((interior_angle < PI) && (p.y > prev.y && p.y > next.y)){
        //cout << "start " << endl;
        return START;
    }
    else if((interior_angle > PI) && (p.y > prev.y && p.y > next.y)){
        return SPLIT;
    }
    else if((interior_angle > PI) && (p.y < prev.y && p.y < next.y)){
        return MERGE;
    }
    else if((interior_angle < PI) && (p.y < prev.y && p.y < next.y)){
        return END;
    }
    else{
        return REGULAR;
    }



    /*
    if(it!=m.end()){
        cout << it->first << endl;
    }
    */
    //int id =
}
void HandleStartVertex(point p){
    point prev,next;
    prevNext(prev,next,p);
//
//    cout << endl;
//    cout << "prev -> " << prev.x << "," << prev.y << endl;
//    cout << "cur -> " << p.x << "," << p.y << endl;
//    cout << "next -> " << next.x << "," << next.y << endl;
//    cout << endl;
    edge e(p,next);
    global_y = p.y;
    T.insert(e);
    helper[e] = p;

}
void HandleEndVertex(point p){
    point prev,next;
    prevNext(prev,next,p);

    edge ei = edge(prev,p);
    if(vertexType(helper[ei]) == MERGE){
        D.push_back(edge(p,helper[ei]));
    }
    global_y = p.y;
    T.erase(ei);
}
void HandleSplitVertex(point p){
    point prev,next;
    prevNext(prev,next,p);

    edge ei = edge(p,next);


    set<edge> ::iterator it = T.upper_bound(ei);
    D.push_back(edge(p,helper[*it]));

    helper[*it] = p;
    global_y = p.y;
    T.insert(ei);
    helper[ei] = p;
}
void HandleMergeVertex(point p){
    point prev,next;
    prevNext(prev,next,p);

    edge ei = edge(prev,p);
    if(vertexType(helper[ei]) == MERGE){
        D.push_back(edge(p,helper[ei]));
    }
    global_y = p.y;
    T.erase(ei);

    set<edge> ::iterator ej = T.upper_bound(ei);

    if(vertexType(helper[*ej]) == MERGE){
        D.push_back(edge(p,helper[*ej]));
    }
    helper[*ej] =p;





}
void HandleRegularVertex(point p){
    point prev,next;
    prevNext(prev,next,p);

    edge ei = edge(prev,p);
    if(p.y > next.y){
        if(vertexType(helper[ei]) == MERGE){
            D.push_back(edge(p,helper[ei]));
        }
        global_y = p.y;
        T.erase(ei);

        T.insert(edge(p,next));
        helper[edge(p,next)] = p;

    }
    else{
        set<edge> ::iterator ej = T.upper_bound(ei);
        if(vertexType(helper[*ej]) == MERGE){
            D.push_back(edge(p,helper[*ej]));
        }
        helper[*ej] =p;
    }

}
void makeMonotone(vector<point> vp){
    priority_queue<point,vector<point>, CompareNodePtr> pp;//(vp);
    for(int i=0;i<(int)vp.size();i++){
        pp.push(vp[i]);
    }
    while(!pp.empty()){
        point p = pp.top();
        if(vertexType(p) == START){
            HandleStartVertex(p);
        }
        else if(vertexType(p) == END){
            HandleEndVertex(p);
        }
        else if(vertexType(p) == SPLIT){
            HandleSplitVertex(p);
        }
        else if(vertexType(p) == MERGE){
            HandleMergeVertex(p);
        }
        else if(vertexType(p) == REGULAR){
            HandleRegularVertex(p);
        }
        //cout << p.x << ", " << p.y << endl;
        pp.pop();
    }
}
void print(){
    for(auto it=m.begin();it!=m.end();it++){
        point p = it->second;
        cout << it->first << "--> " << it->second.x  << "," << it->second.y << " -> Type: " << vertexType(p) << endl;
    }
}
int main(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\ComputationalGeometry\\monotone.txt","r",stdin);
    int n;

    scanf("%d",&n);
   // point q;
    for(int i=0;i<n;i++){
        point p;scanf("%lf %lf",&p.x,&p.y);
       // if(i==0)q = p;
        vp.push_back(p);
        m[i] = p;
    }
    //vp.push_back(q);
    /*
    for(int i=0;i<vp.size();i++){
        cout << vp[i].x << "," << vp[i].y << endl;
    }
    */
     makeMonotone(vp);
    printf("Size: %d\n",D.size());
    for(int i=0;i<(int)D.size();i++){
        cout << vertexType(point( D[i].p.x, D[i].p.y )) <<  " - (" << D[i].p.x << "," << D[i].p.y << ") - ("<<D[i].q.x << ","<<D[i].q.y <<")" << endl;
    }

   // print();

    //vertexType(point(-2,2));

   /// printf("%lf\n",angle(point(-1,6),point(-2,2),point(-5,5)));



   // printf("p(%lf,%lf) , q(%lf,%lf)\ndistance (5,5) to x axis: %lf\n", p.x, p.y, q.x, q.y,distToLineSegment(point(5,5),point(0,0),point(5,0)));
    return 0;
}