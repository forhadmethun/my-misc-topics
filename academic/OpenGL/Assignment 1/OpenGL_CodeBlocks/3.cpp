#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))


double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle,zAxisAngle,xAxisAngle;

bool temp = true;

struct point
{
	double x,y,z;
};
///4 variables
struct point pos,u,r,l;

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
		    glColor3f(1,0,0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);
            glColor3f(0,1,0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);
            glColor3f(0,0,1);
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


///square
void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		//glVertex3f( a,-a,2);
		glVertex3f( a,0,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(0,0,0);

		//glVertex3f(-a, a,2);
		glVertex3f(0, a,0);
	}glEnd();


	glBegin(GL_QUADS);{
		glVertex3f( a, 0,a);
		//glVertex3f( a,-a,2);
		glVertex3f( a,0,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(a,a,0);

		//glVertex3f(-a, a,2);
		glVertex3f(a, a,a);
	}glEnd();

		glBegin(GL_QUADS);{
		    glColor3f(1.0,1.0,0.0);
		glVertex3f( 0,0,0);
		//glVertex3f( a,-a,2);
		glVertex3f( 0,0,a);

		//glVertex3f(-a,-a,2);
		glVertex3f(a,0,a);

		//glVertex3f(-a, a,2);
		glVertex3f(a, 0,0);
	}glEnd();


			glBegin(GL_QUADS);{
		    glColor3f(0,1.0,1.0);
		glVertex3f( a,a,a);
		//glVertex3f( a,-a,2);
		glVertex3f( a,a,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(0,a,0);

		//glVertex3f(-a, a,2);
		glVertex3f(0,a,a);
	}glEnd();



}




void drawCylinder(double radius,double height,int segments)
{
    int i;
    double shade;
    struct point points[100];
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);

        cout << i << "->" << points[i].x << "--- " << points[i].y << endl;
    }
    //draw triangles using generated points
    for(i=0;i<segments;i++)
    {
        //create shading effect
        if(i<segments/2)shade=2*(double)i/(double)segments;
        else shade=2*(1.0-(double)i/(double)segments);
        glColor3f(shade,shade,shade);

        glBegin(GL_QUADS);
        {
            //glVertex3f(0,0,height);
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i].x,points[i].y,height);
			glVertex3f(points[i+1].x,points[i+1].y,height);
			glVertex3f(points[i+1].x,points[i+1].y,0);

        }
        glEnd();
    }
}


void drawCrossPlane(double a)
{
        //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, 0,0);
		//glVertex3f( a,-a,2);
		glVertex3f( -a,0,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(-a,0,a);

		//glVertex3f(-a, a,2);
		glVertex3f(a, 0,a);
	}glEnd();

		glBegin(GL_QUADS);{
		glVertex3f( 0, a,0);
		//glVertex3f( a,-a,2);
		glVertex3f( 0,-a,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(0,-a,a);

		//glVertex3f(-a, a,2);
		glVertex3f(0, a,a);
	}glEnd();

}


double d = (2.0*pi * 20.0 * 5.0) / 360.0;
double m = d;

void drawWheel()
{
    glTranslatef(0,-10,20);
    glRotatef(zAxisAngle,0,0,1);

    glRotatef(xAxisAngle,1,0,0);
    //glTranslatef(0,-10,0);

    glRotatef(90,0,1,0);
    glTranslatef(0,0,-10);
    drawCrossPlane(20);
    drawCylinder(20,20,24);
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

        cout << i << "->" << points[i].x << "--- " << points[i].y << endl;
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


///one eighth of a sphere
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
			    if(points[i][j].x>=0 && points[i][j].y>=0 && points[i][j].z >=0 )
				glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				if(points[i][j+1].x>=0 && points[i][j+1].y>=0 && points[i][j+1].z>=0)
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				if(points[i+1][j+1].x>=0 && points[i+1][j+1].y >=0 &&  points[i+1][j+1].z)
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				if(points[i+1][j].x>=0 && points[i+1][j].y>=0 &&points[i+1][j].z >=0)
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);
				/*
                //lower hemisphere
                glVertex3f(points[i][j].x,points[i][j].y,-points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,-points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,-points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,-points[i+1][j].z);
				*/
			}glEnd();
		}
	}
}




void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':

			drawgrid=1-drawgrid;
			break;

        case 'a':
            temp = false;
            zAxisAngle-=5;
            break;

        case 'd':
            temp =false;
            zAxisAngle+=5;
            break;

        case 'w':
            temp = true;
            xAxisAngle-=5;
            m = m + d;

            break;
        case 's':
            temp = true;
            xAxisAngle+=5;
            m  = m - d;
            break;

		default:
			break;
	}
}

void drawUpperSphere(){
        //drawSquare(30);
    drawSphere(30,24,20);
    /*
    //+x,+y,+z
    glRotatef(90,0,0,1);
    drawSphere(30,24,20);
    //drawSquare(30);

    //+x,-y,z
    glRotatef(180,0,0,1);
    drawSphere(30,24,20);

    //-x,y,z
    glRotatef(270,0,0,1);
    drawSphere(30,24,20);
    */
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

double g,h;

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

	//gluLookAt(cameraX,cameraY,cameraZ,	0,0,0,	0,0,1);
	gluLookAt(100*cos(cameraAngle), 100*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,200,	0,0,0,	0,1,0);


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
    ///glColor3f(1,0,0);


    //drawUpperSphere();

    //glScalef(1,0.5,0.5);


    //drawSquare(30);
    //glRotatef(180,1,0,0);
    //drawUpperSphere();






    //glRotatef(90,0,1,0);
    //drawSphere(30,24,20);
   // drawSquare(30);

   //glRotatef(180,0,0,1);
   //drawSphere(30,24,20);



   ///

    //+x,+y,+z
    //glRotatef(90,0,1,0);
    //drawSphere(30,24,20);
    //drawSquare(30);

    //+x,-y,z
    //glRotatef(180,0,1,0);
    //drawSphere(30,24,20);

    //-x,y,z
    //glRotatef(270,0,1,0);
    //drawSphere(30,24,20);




    //drawSS();

    //drawCircle(30,24);



    //
   if(temp){
        g = m*sin(zAxisAngle);
        h= m*cos(zAxisAngle);
        glTranslatef(g,h,0);
   }
   else{
   glTranslatef(g,h,0);
   }
   glTranslatef(0,10,0);
    drawWheel();


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
	drawgrid=1;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;
//	cameraX = 100;
	//cameraY = 0;
	//cameraZ = 0;

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

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
