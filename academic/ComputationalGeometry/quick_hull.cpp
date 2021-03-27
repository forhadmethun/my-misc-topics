#include <bits/stdc++.h>
using namespace std;

#define  EPS 1e-9

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

//bottom right point of an axis
point getMaxXPoint(vector<point> inputPoints){
    point max = inputPoints[0];
    //for(int i=1;i<inputPoints)
    for(point p : inputPoints){
        //cout << p.x << " -> " << p.y << endl;
        if(p> max){
            max = p;
        }
    }
    cout << max.x << "-> " << max.y << endl;
}

//bottom left point of an axis
point getMinXPoint(vector<point> inputPoints){
    point min = inputPoints[0];
    //for(int i=1;i<inputPoints)
    for(point p : inputPoints){
        //cout << p.x << " -> " << p.y << endl;
        if(p < min){
            min = p;
        }
    }
    cout << min.x << "-> " << min.y << endl;
}
struct line{
    double a,b,c;
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
double distToLineSegment(point p,point a,point b){
    line l ;pointsToLine(a,b,l);
    return fabs((p.x*l.a + p.y*l.b + l.c)/sqrt(l.a*l.a + l.b*l.b));
}

 int pointLocation(point A, point B, point P)
{
    int cp1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    if (cp1 > 0)
        return 1;
    else if (cp1 == 0)
        return 0;
    else
        return -1;
}

 int distance(point A, point B, point  C)
{
    int ABx = B.x - A.x;
    int ABy = B.y - A.y;
    int num = ABx * (A.y - C.y) - ABy * (A.x - C.x);
    if (num < 0)
        num = -num;
    return num;
}

void hullSet(point A, point B, vector<point> set,
                    vector<point> &hull)
{
  //  cout << "--------------------------------" << endl;
//
//    for(int i=0;i<hull.size();i++){
//        cout << hull[i].x << "***" << hull[i].y << endl;
//    }

    //cout << "----------" << set.size() << "--------" << endl;
    //int insertPosition = hull.indexOf(B);
    int insertPosition = find(hull.begin(),hull.end(),A)-hull.begin();

    if (set.size() == 0)
        return;
    if (set.size() == 1)
    {
        point p = set[0];
        set.erase(remove(set.begin(),set.end(),p),set.end());
       // set.remove(p);
        //hull.add(insertPosition, p);
        //hull[insertPosition] = p;
        hull.insert(hull.begin()+insertPosition, p );
        return;
    }
    int dist = INT_MIN;
    int furthestPoint = -1;
    for (int i = 0; i < set.size(); i++)
    {
        point p = set[i];
        int distanc= distToLineSegment(A, B, p);
        if (distanc > dist)
        {
            dist = distanc;
            furthestPoint = i;
        }
    }
    point P = set[furthestPoint];

    set.erase(remove(set.begin(),set.end(),P),set.end());
    //set.remove(furthestPoint);

    hull.insert(hull.begin()+insertPosition, P);
   // hull[insertPosition] = P;

    // Determine who's to the left of AP
    vector<point> leftSetAP ;//= new ArrayList<Point>();
    for (int i = 0; i < set.size(); i++)
    {
        point M = set[i];
        if (pointLocation(A, P, M) == 1)
        {
            leftSetAP.push_back(M);
        }
    }

    // Determine who's to the left of PB
    vector<point> leftSetPB;// = new ArrayList<Point>();
    for (int i = 0; i < set.size(); i++)
    {
        point M = set[i];
        if (pointLocation(P, B, M) == 1)
        {
            leftSetPB.push_back(M);
        }
    }
   // cout << "dukinio " << endl;
    hullSet(A, P, leftSetAP, hull);
    hullSet(P, B, leftSetPB, hull);

}
 vector<point> quickHull(vector<point> points)
{
    vector<point> convexHull;//= new ArrayList<Point>();
    if (points.size() < 3) return points;
       // return (ArrayList) points.clone();

    int minPoint = -1, maxPoint = -1;
    int minX = INT_MAX;//.MAX_VALUE;
    int maxX = INT_MIN;//.MIN_VALUE;
    for (int i = 0; i <(int) points.size(); i++)
    {
        if (points[i].x < minX)
        {
            minX = points[i].x;
            minPoint = i;
        }
        if (points[i].x > maxX)
        {
            maxX = points[i].x;
            maxPoint = i;
        }
    }
   // cout << "Dhuksilam" << endl;
    point A = points[minPoint];
    point B = points[maxPoint];

   // cout << A.x << "%%" << A.y << endl;
   // cout << B.x << "%%" << B.y << endl;

    convexHull.push_back(A);
    convexHull.push_back(B);

    //vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
    points.erase(remove(points.begin(),points.end(),A),points.end());
    points.erase(remove(points.begin(),points.end(),B),points.end());
  //  cout <<"sz: " <<  points.size() << endl;

//    points.remove(A);
//    points.remove(B);

    vector<point> leftSet;// = new ArrayList<Point>();
    vector<point> rightSet;// = new ArrayList<Point>();

    for (int i = 0; i < points.size(); i++)
    {
        point p = points[i];
        if (pointLocation(A, B, p) == -1)
            leftSet.push_back(p);
        else if (pointLocation(A, B, p) == 1)
            rightSet.push_back(p);
    }

    // cout <<"lSize: " <<  leftSet.size() << endl;
    // cout <<"rSize: " <<  rightSet.size() << endl;
    hullSet(A, B, rightSet, convexHull);
    hullSet(B, A, leftSet, convexHull);

    return convexHull;
}


int main(){
    freopen("D:\\googleDrive\\_CSE\\Code\\in.txt","r",stdin);
    vector<point> inputPoints; //set of points as input
    vector<point> hullPoints;  // points which create convex hull

    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        point input;
        cin >> input.x >> input.y;
        inputPoints.push_back(input);
    }
    hullPoints = quickHull(inputPoints);
    hullPoints.push_back(hullPoints[0]);
    for(int i=0;i<hullPoints.size();i++){
       // cout << "dhuke ni" << endl;
        cout << hullPoints[i].x << "->" << hullPoints[i].y << endl;
    }
//     getMinXPoint(inputPoints);
//     getMaxXPoint(inputPoints);
//    point p(1,1),a(2,3),b(3,4);
//    cout << distToLineSegment(p,a,b) << endl;


    //cout << "Hello World!" << endl;
    return 0;
}
