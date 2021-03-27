#include <bits/stdc++.h>
using  namespace std;
#define EPS 1e-9
#define PI acos(-1)
#define M_PI acos(-1)

double DEG_to_RAD(double d){ return (d*M_PI )/ 180.0; }
double RAD_to_DEG(double r){ return  (180.0*r)/ M_PI ;}

struct point{double x,y;point(){x=y=0.0;}point(double _x,double _y){x=_x;y=_y;} bool operator ==(point other){return fabs(x-other.x) <EPS && (fabs(y-other.y)<EPS);} bool operator <(point other){if (fabs(x-other.x) > EPS)return x<other.x; else y<other.y;}};

double dist(point p1,point p2){return hypot(p1.x- p2.x,p1.y -p2.y);}


//formula
/*      |  cost(theta)      -sin(theta)  |  | x  |
 *      |                                |  |    |
 *      |   sin(theta)       cos(theta)  |  | y  |
 */
point rotate(point p, double theta){
    return  point(p.x*cos(theta) - p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta));
}

struct vec{
    double x,y;
    vec(double _x, double _y){
        x = _x;
        y = _y;
    }
};
vec toVec(point a,point b){
    return vec(b.x-a.x,b.y-a.y);
}

double perimeterr(const vector<point> &P){ //P[0] = P[n-1]
    double result = 0.0;
    for(int i=0;i<(int)P.size()-1;i++){
        result +=dist(P[i],P[i+1]);
    }
}

double area(const vector<point> &P){
    double result=0.0,x1,y1,x2,y2;
    for(int i=0;i<(int)P.size()-1;i++){
        x1 = P[i].x;
        y1 = P[i].y;
        x2 = P[i+1].x;
        y2 = P[i+1].y;
        result+= (x1*y2 - x2*y1);
    }
    return fabs(result) / 2.0;
}

double dot(vec a, vec b){
    return (a.x*b.x + a.y*b.y);
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}

double angle(point a, point o, point b){
    vec oa = toVec(o,a);
    vec ob = toVec(o, b);
    return acos(dot(oa,ob)/sqrt((norm_sq(oa) *norm_sq(ob))));
}

double cross(vec a,vec b){
    return a.x*b.x - a.y*b.y;
}
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

bool collinear(point p,point q,point r){
    return fabs(cross(toVec(p,q),toVec(p,r))) < EPS;
}

bool isConvex(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
    bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
    for (int i = 1; i < sz-1; i++)            // then compare with the others
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;            // different sign -> this polygon is concave
    return true; }                                  // this polygon is convex

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;    // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
    return fabs(fabs(sum) - 2*PI) < EPS; }


int main(){
    point p1(0,0),p2(0,0),p3(0,1);
    printf("%d\n",p1 == p2);
    //printf("%d\n",p1 < p3);


    vector<point> P;
    P.push_back(point(1, 1));
    P.push_back(point(3, 3));
    P.push_back(point(9, 1));
    P.push_back(point(12, 4));
    P.push_back(point(9, 7));
    P.push_back(point(1, 7));
    P.push_back(P[0]); // loop back

    point P6(3,2);
    point P7(3,4);

    printf("Area: %.2lf\n",area(P));
    printf("IsConvex ---> %d\n",isConvex(P));


    printf("Point P6 is inside this polygon = %d\n", inPolygon(P6, P)); // true
    printf("Point P6 is inside this polygon = %d\n", inPolygon(P7, P)); // true


    return 0;
}