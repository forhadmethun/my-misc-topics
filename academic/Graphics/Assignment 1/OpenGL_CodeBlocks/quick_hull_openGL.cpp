#include<bits/stdc++.h>
using namespace std;


#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
/*
struct point
{
	double x,y,z;
};
*/
#define  EPS 1e-9

struct point{
    double x,y,z;
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



vector<point> inputPoints,pointCloud;  //set of points as input

void drawAxes()
{
    if(drawaxes==1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);{
            glVertex3f( 100,0,0);
            glVertex3f(-100,0,0);

            glVertex3f(0,-100,0);
            glVertex3f(0, 100,0);

            glVertex3f(0,0, 100);
            glVertex3f(0,0,-100);
        }glEnd();
    }
}


void drawGrid()
{
    int i;
    if(drawgrid==1)
    {
        glColor3f(0.6, 0.6, 0.6);	//grey
        glBegin(GL_LINES);{
            for(i=-8;i<=8;i++){

                if(i==0)
                    continue;	//SKIP the MAIN axes

                //lines parallel to Y-axis
                glVertex3f(i*10, -90, 0);
                glVertex3f(i*10,  90, 0);

                //lines parallel to X-axis
                glVertex3f(-90, i*10, 0);
                glVertex3f( 90, i*10, 0);
            }
        }glEnd();
    }
}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);{
        glVertex3f( a, a,2);
        glVertex3f( a,-a,2);
        glVertex3f(-a,-a,2);
        glVertex3f(-a, a,2);
    }glEnd();
}


void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
        }
        glEnd();
    }
}

void drawCone(double radius,double height,int segments)
{
    int i;
    double shade;
    struct point points[100];
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw triangles using generated points
    for(i=0;i<segments;i++)
    {
        //create shading effect
        if(i<segments/2)shade=2*(double)i/(double)segments;
        else shade=2*(1.0-(double)i/(double)segments);
        glColor3f(shade,shade,shade);

        glBegin(GL_TRIANGLES);
        {
            glVertex3f(0,0,height);
            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
        }
        glEnd();
    }
}


void drawSphere(double radius,int slices,int stacks)
{
    struct point points[100][100];
    int i,j;
    double h,r;
    //generate points
    for(i=0;i<=stacks;i++)
    {
        h=radius*sin(((double)i/(double)stacks)*(pi/2));
        r=radius*cos(((double)i/(double)stacks)*(pi/2));
        for(j=0;j<=slices;j++)
        {
            points[i][j].x=r*cos(((double)j/(double)slices)*2*pi);
            points[i][j].y=r*sin(((double)j/(double)slices)*2*pi);
            points[i][j].z=h;
        }
    }
    //draw quads using generated points
    for(i=0;i<stacks;i++)
    {
        glColor3f((double)i/(double)stacks,(double)i/(double)stacks,(double)i/(double)stacks);
        for(j=0;j<slices;j++)
        {
            glBegin(GL_QUADS);{
                //upper hemisphere
                glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
                glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
                glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
                glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);
                //lower hemisphere
                glVertex3f(points[i][j].x,points[i][j].y,-points[i][j].z);
                glVertex3f(points[i][j+1].x,points[i][j+1].y,-points[i][j+1].z);
                glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,-points[i+1][j+1].z);
                glVertex3f(points[i+1][j].x,points[i+1][j].y,-points[i+1][j].z);
            }glEnd();
        }
    }
}


void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);

    glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);

    glPushMatrix();
    {
        glRotatef(angle,0,0,1);
        glTranslatef(60,0,0);
        glRotatef(2*angle,0,0,1);
        glColor3f(0,0,1);
        drawSquare(10);
    }
    glPopMatrix();

    glRotatef(3*angle,0,0,1);
    glTranslatef(40,0,0);
    glRotatef(4*angle,0,0,1);
    glColor3f(1,1,0);
    drawSquare(5);
}

void keyboardListener(unsigned char key, int x,int y){
    switch(key){

        case '1':
            drawgrid=1-drawgrid;
            break;

        default:
            break;
    }
}


void specialKeyListener(int key, int x,int y){
    switch(key){
        case GLUT_KEY_DOWN:		//down arrow key
            cameraHeight -= 3.0;
            break;
        case GLUT_KEY_UP:		// up arrow key
            cameraHeight += 3.0;
            break;

        case GLUT_KEY_RIGHT:
            cameraAngle += 0.03;
            break;
        case GLUT_KEY_LEFT:
            cameraAngle -= 0.03;
            break;

        case GLUT_KEY_PAGE_UP:
            break;
        case GLUT_KEY_PAGE_DOWN:
            break;

        case GLUT_KEY_INSERT:
            break;

        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;

        default:
            break;
    }
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
                drawaxes=1-drawaxes;
            }
            break;

        case GLUT_RIGHT_BUTTON:
            //........
            break;

        case GLUT_MIDDLE_BUTTON:
            //........
            break;

        default:
            break;
    }
}



void display(){

    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);	//color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /********************
    / set-up camera here
    ********************/
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);

    //initialize the matrix
    glLoadIdentity();

    //now give three info
    //1. where is the camera (viewer)?
    //2. where is the camera looking?
    //3. Which direction is the camera's UP direction?

    //gluLookAt(100,100,100,	0,0,0,	0,0,1);
    //gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
    gluLookAt(0,0,150,	0,0,0,	0,1,0);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/
    //add objects

    drawAxes();
    drawGrid();

    //glColor3f(1,0,0);
    //drawSquare(10);

    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for(int i=0;i<pointCloud.size();i++)
    {
        glVertex2f(pointCloud[i].x,pointCloud[i].y);
    }
    glEnd();

    //Green Color for boundary points
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    for(int i=0;i<pointCloud.size()-1;i++)
    {
        //glVertex2f(drawablePoints[i].getX(),drawablePoints[i].getY());
        glVertex2f(pointCloud[i].x,pointCloud[i].y);
        glVertex2f(pointCloud[i+1].x,pointCloud[i+1].y);

    }
    glEnd();

    //drawSS();

    //drawCircle(30,24);

    //drawCone(20,50,24);

    //drawSphere(30,24,20);




    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}


void animate(){
    angle+=0.05;
    //codes for any changes in Models, Camera
    glutPostRedisplay();
}

void init(){
    //codes for initialization
    drawgrid=0;
    drawaxes=1;
    cameraHeight=150.0;
    cameraAngle=1.0;
    angle=0;

    //clear the screen
    glClearColor(0,0,0,0);

    /************************
    / set-up projection here
    ************************/
    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    //give PERSPECTIVE parameters
    gluPerspective(80,	1,	1,	1000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}




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






void generatePointCloud(int limit)
{
    pointCloud.clear();

    for(int i=0;i<limit;i++)
    {
        srand (i*time(NULL));
        float randX = (rand()%100);
        float randY = (rand()%100);

        pointCloud.push_back(point(randX,randY));
    }

}




int main(int argc, char **argv){

    freopen("D:\\googleDrive\\_CSE\\Code\\in.txt","r",stdin);

    vector<point> hullPoints;  // points which create convex hull

    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        point input;
        cin >> input.x >> input.y;
        inputPoints.push_back(input);
    }
    generatePointCloud(50);
    hullPoints = quickHull(inputPoints);
    hullPoints.push_back(hullPoints[0]);
    /*
    for(int i=0;i<hullPoints.size();i++){
       // cout << "dhuke ni" << endl;
        cout << hullPoints[i].x << "->" << hullPoints[i].y << endl;

    }
    */

    for(int i=0;i<pointCloud.size();i++){
        // cout << "dhuke ni" << endl;
        cout << pointCloud[i].x << "->" << pointCloud[i].y << endl;

    }
    pointCloud = quickHull(pointCloud);
    pointCloud.push_back(pointCloud[0]);



    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

    glutCreateWindow("My Graphics Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    glutMainLoop();		//The main loop of Graphics

    return 0;
}
