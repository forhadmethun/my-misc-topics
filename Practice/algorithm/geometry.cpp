#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI acos(-1)

double deg_to_rad(double degree){
    return (PI * degree)/ 180.0;
}
double rad_to_deg(double radian){
    return (180.0 * radian)/PI ;
}
struct point_i{
    int x,y;
    point_i(){
        x = y = 0;
    }
    point_i(int a,int b){
        x = a;y = b;
    }
};
struct point{
    double x,y;
    point(){
        x = y = 0;
    }
    point(double a,double b){
        x = a;
        y = b;
    }
    bool operator < (point other) const{
        if(fabs(x-other.x)<EPS){
            return y<other.y;
        }
    }
    bool operator == (point other) const{
        if(fabs(x-other.x)< EPS && fabs(y-other.y)<EPS){
            return true;
        }
        return false;
    }


};
double dist(point p1,point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);
};
point rotate(point p,double theta){
    return point(p.x*cos(theta)-p.y*sin(theta) ,p.x*cos(theta)+p.y*sin(theta) );
}
struct line{
    double a,b,c;
};
struct line2{
    double m,c;
};
void pointsToLine(point p1,point p2,line &l1){
    if(fabs(p2.x - p1.x) < EPS){
        l1.a = 1.0;
        l1.b = 0;
        l1.c = -p1.x;
    }
    else{
        l1.a = p1.y -p2.y;
        l1.b = p2.x - p1.x;
        l1.c = p2.y * p1.x - p1.y * p2.x;
    }
}
void pointsToLine2(point p1,point p2,line2 &l1){
    if(abs(p2.x - p1.x) < EPS){
        l1.m = INT_MAX;
        l1.c = -p1.x;
    }
    else{
        l1.m = (p2.y - p1.y)/(p2.x - p1.x);
        l1.c = p1.y - l1.m * p1.x;
    }

}
bool areParallel(line l1,line l2){
    double m1 = -(l1.a / l1.b);
    double m2 = -(l2.a / l2.b);
    if(fabs(m1 - m2) < EPS){
        return true;
    }
    return false;
}
bool areSame(line l1,line l2){
    if(fabs(l1.a*l2.b - l2.a*l1.b) <EPS  && fabs(l1.b * l2.c - l2.b*l1.c) < EPS){
        return true;
    }
    return false;
}
//ax + by + c = 0 format equation
bool areIntersect(line l1,line l2,point &p){
    if(areParallel(l1,l2)){
        return false;
    }
    else{
        double div = l1.a * l2.b - l2.a * l1.b;
        p.x =  ((-l2.b)*l1.c + l1.b * l2.c)/div;
        p.y = (-(l1.a*l2.c) + l2.a * l1.c) / div;
        return true;
    }
}
struct vec{
    double x,y;
    vec(){
        x = 0;
        y = 0;
    }
    vec(double _x,double _y) : x(_x),y(_y){};
};
vec toVec(point a,point b){
    return vec(b.x - a.x , b.y-a.y);
}
vec scale(vec v,double s){
    return vec(v.x*s , v.y*s);
}
point translate(point p,vec v){
    return point(p.x+ v.x , p.y + v.y);
}
void pointSlopeToLine(point p,double m,line &l){
    l.a  = m;
    l.b = -1;
    l.c = -m * p.x + p.y;
}
void closestPoint(line l,point p,point &ans){
    line l2;
    l2.a = l.b;
    l2.b = -l.a;
    l2.c = l.a * p.y - l.b * p.x;

    areIntersect(l,l2,ans);
}
void reflectionPoint(line l,point p,point &ans){
    point intersect;
    closestPoint(l,p,intersect);
    vec v = toVec(p,intersect);
   ans  =  translate(translate(p,v),v);

}
double dot(vec a,vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y *v.y;
}
double distToLineSegment(point p,point a,point b){
    line l ;pointsToLine(a,b,l);
    return (p.x*l.a + p.y*l.b + l.c)/sqrt(l.a*l.a + l.b*l.b);
}
double angle(point a,point o,point b){
    vec oa = toVec(o,a);vec ob = toVec(o,b);
    return (dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a,vec b){
    return a.x * b.y - a.y *b.x;
}
bool ccw(point p,point q,point r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool collinear(point p,point q,point r){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

//circle
int insideCircle(point_i p, point_i c, int r){

}
bool circle2PtsRad(point p1, point p2, double r, point &c){

}
void circleOperation(){
    //diameter
    //area
    //circimference
    //arc length
    //area of sector
    //length of chord
}

//Triangle

double perimeter(point a,point b, point c){

}
double area(double ab,double bc,double ca){

}
double area(point a,point b,point c){

}
double rInCircle(double ab,double bc,double ca){

}
double rInCircle(point a,point b,point c){

}
int inCircle(point p1,point p2,point p3,point &ctr,double &r){

}
double rCircumCircle(point a,point b,point c){

}
int circumCircle(point p1,point p2,point p3,point &ctr,double &r){


}
int incCircumCircle(point a,point b,point c,point d){

}
bool canFormTriangle(double a,double b,double c){

}


//PolyGon
double perimeter(const vector<point> &P){

}
double area(const vector<point> &P){

}
bool isConvex(const vector<point> &P){

}
bool isPolygon(point pt, const vector<point> &P){

}
point lineIntersectSeg(point p,point q,point A,point B){

}

vector<point> cutPolygon(point a,point b,const vector<point> &P){

}

bool angleCmp(point a,point b){

}
vector<point> CH(vector<point> P){

}


void check_distToLineSegment()
{
    point p,q,r;
    p.x = 0;
    p.y = 0;

    q.x = 2;
    q.y = 2;

    r.x = -2;
    r.y = 2;

    cout << distToLineSegment(p,q,r) << endl;
}
void check_reflectionPoint(){
    point p;
    line l;point ans;
    l.a =0;
    l.b = 1;
    l.c = 0;

    p.x = 5;
    p.y  = 2;

    reflectionPoint(l,p,ans);

    cout << ans.x << "," << ans.y << endl;
}
void check_areIntersect(){
    cout << EPS << endl;
    printf("%0.15lf\n",EPS);
    line l1,l2;
    l1.a = 4;
    l1.b = 2;
    l1.c = 8;
    point p;
    l2.a =8;
    l2.b = 3;
    l2.c = 16;
    if(areIntersect(l1,l2,p)){
        //cout << "YES" << endl;
        cout << p.x << " ,  " << p.y << endl;
    }


}
int main()
{

//    check_areIntersect();

    return 0;
}