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

vector<point> vp; // for storing thepoints
class CompareNodePtr //for queue sort with y cordinate
{
public:
    bool operator ()(point a, point other) {
        if (fabs(a.y - other.y) < EPS) {
            return a.x > other.x;
        }
        return a.y < other.y;
    }
};

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
vector<edge> D;

//for getting the previous and next point of p
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


//tops , uj
bool visible(point a,point b){
    point prev,next;
    // prevNext(prev,next,b);


    if(ccw(prev,b,a)){
        return true;
    }
    else return false;

}

int main(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\ComputationalGeometry\\input_y_monotone.txt","r",stdin);
    int n;
    scanf("%d",&n);
    // point q;
    for(int i=0;i<n;i++){
        point p;scanf("%lf %lf",&p.x,&p.y);
        // if(i==0)q = p;
        vp.push_back(p);
      //  m[i] = p;
    }


    priority_queue<point,vector<point>, CompareNodePtr> pp;//(vp);
    for(int i=0;i<(int)vp.size();i++){
        pp.push(vp[i]);
    }
    vector<point> u;
    u.push_back(point(0,0));

    while(!pp.empty()){
       // cout << pp.top().x << "," << pp.top().y << endl;
        u.push_back( pp.top());
        pp.pop();
    }

    stack<point> s;

    s.push(u[1]);
    point top = u[1];
    //pp.pop();
    s.push(u[2]);
   // point nxt = pp.top();
    //pp.pop();

    for(int j=3;j<u.size();j++){
       // cout <<"j: " << j << endl;

        if( (s.top().x < top.x && u[j].x > top.x) ||(s.top().x > top.x && u[j].x < top.x) ){ //if different chain
           // point prev,next;
           // prevNext(prev,next,s.top());
            //cout <<"dhuke ki " << endl;
            while(!s.empty()){
                point vo = s.top();
                s.pop();
                D.push_back(edge(u[j],vo));

            }
            if(!s.empty())s.pop();
            //s.push(nxt);
            s.push(u[j-1]);
            s.push(u[j]);
           // nxt = pp.top();
            //pp.pop();
        }

        else{
          point last=s.top();//,uj = pp.top();
            if(!s.empty())s.pop();
           // cout << s.size() << endl;
            while(visible(s.top(),u[j])){
                point vo = s.top();
                D.push_back(edge(u[j],vo));
                last = s.top();
                if(!s.empty())s.pop();
            }
            s.push(last );
            s.push(u[j]);
        }

    }
    printf("Size: %d\n",D.size());
    for(int i=0;i<(int)D.size();i++){
        cout  << " - (" << D[i].p.x << "," << D[i].p.y << ") - ("<<D[i].q.x << ","<<D[i].q.y <<")" << endl;
    }

   // printf("Size: %d\n",D.size());



    return 0;
}