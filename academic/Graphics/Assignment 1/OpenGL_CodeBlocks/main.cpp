// 2

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle, bigHandAngle,bigHandAngleY,bigHandAngleUpper,bigHandAngleLower1,bigHandAngleLower2,bigHandAngleLower3;







struct point
{
	double x,y,z;
};


void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
		    glColor3f(1.0, 0,0 );
			glVertex3f( 300,0,0);
			glVertex3f(-300,0,0);

            glColor3f(0, 1.0, 0);
			glVertex3f(0,-300,0);
			glVertex3f(0, 300,0);

            glColor3f(0,0,1.0);
			glVertex3f(0,0, 300);
			glVertex3f(0,0,-300);
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

void drawTriangle()
{
    glColor3f(1,1,0);
    	  glBegin(GL_TRIANGLES);{
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(-10, 0, 0);
        glVertex3f(10, 0, 0);
        glVertex3f(0, 0, 10);

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


void drawSS()
{

    glColor3f(1,0,0);
    drawSquare(50);
    drawSphere(30,24,20);

    glRotatef(angle,0,0,01);
    glTranslatef(0,110,0);



    //glRotatef(2*angle,0,0,1);

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
			//drawgrid=1-drawgrid;
			if(bigHandAngle<=45)
			bigHandAngle+=3;
			break;

        case '2':
            if(bigHandAngle>=-45)bigHandAngle-=3;
            break;
        case '3':
            if(bigHandAngleUpper<=90)
			bigHandAngleUpper+=3;

            break;
        case '4':
            if(bigHandAngleUpper>0)
			bigHandAngleUpper-=3;
            break;
        case '5':
            if(bigHandAngleLower1<=90)
			bigHandAngleLower1+=3;

            break;
        case '6':
            if(bigHandAngleLower1>0)
			bigHandAngleLower1-=3;
            break;
        case '7':
            if(bigHandAngleLower2<=90)
			bigHandAngleLower2+=3;
            break;
        case '8':

            if(bigHandAngleLower2>0)
			bigHandAngleLower2-=3;
			break;
        case '9':
            if(bigHandAngleLower3<=90)
			bigHandAngleLower3+=3;
            break;
        case '0':
            if(bigHandAngleLower3>0)
			bigHandAngleLower3-=3;
			break;

        case 'q':
                if(bigHandAngleY<=45)
			bigHandAngleY+=3;

            break;
        case 'w':
            if(bigHandAngleY>=-45)bigHandAngleY-=3;
            break;

		default:
			break;
	}
}

void drawUpperSphere(){
        //drawSquare(30);
    drawSphere(30,24,20);


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

double hfirstAngle,hSecondAngle,hThirdAngle,hFourthAngle;


void hand()
{
    // glColor3f(1,1,1);
    /*
    double top = 5,r1=10,r2=5,tri,fr;
    glTranslated(0,0,-1*top*r1);
    glScaled(1,1,top);
    glutWireSphere(r1 ,14,10);

    ///glutWireSphere(0,0,-2*5*)
    //glPushMatrix();
        glColor3f(1,0,0);
        //glTranslated(0,0,(-1)*top*r2);
        glScaled(1,1,top-1);
        glutWireSphere(r2,14,10);
    //glPopMatrix();
    */
   // glRotatef(30,0,1,0);
   ///hand 1st portion
        glPushMatrix();
    glTranslatef(0,0,-50);
    glScaled(1,1,5);
    glutWireSphere(10,10,10);
    glPopMatrix();

    //glRotatef(bigHandAngleUpper,0,1,0);
    glPushMatrix();
    ///hand 2nd portion
            glColor3f(1,0,0);

           glTranslatef(0,0,-50-50);
          glRotatef(bigHandAngleUpper,0,1,0);
          glTranslatef(0,0,-30);


        glScaled(1,1,3);


        glutWireSphere(10,10,10);
    glPopMatrix();

    ///HandTriangle Portion
    double x = -50-50;
    glPushMatrix();

        glTranslatef(0,0,-50-50);
        glRotatef(bigHandAngleUpper,0,1,0);
        glTranslatef(0,0,-30-30-10);


        drawTriangle();
    glPopMatrix();
    ///middle finger
    glPushMatrix();
        glColor3f(0,1,1);

        glTranslatef(0,0,-50-50);
        glRotatef(bigHandAngleUpper,0,1,0);
         glTranslatef(-0,0,-30-30-10);


        glRotatef(bigHandAngleLower1,1,0,0);
        glTranslatef(-0,0,-10);


        glScaled(1,1,5);
        glutWireSphere(2,10,10);
    glPopMatrix();
    ///right finger
    glPushMatrix();
        glColor3f(0,1,1);

         glTranslatef(-0,0,-50-50);
         glRotatef(bigHandAngleUpper,0,1,0);
         glTranslatef(0,0,-10-30-30);

        glRotatef(bigHandAngleLower2,1,0,0);


        glTranslatef(+10,0,-10);
        glScaled(1,1,5);
        glutWireSphere(2,10,10);
    glPopMatrix();
    ///left finger
    glPushMatrix();
        glColor3f(0,1,1);

         glTranslatef(-0,0,-50-50);
         glRotatef(bigHandAngleUpper,0,1,0);
         glTranslatef(0,0,-10-30-30);

        glRotatef(bigHandAngleLower3,1,0,0);
        glTranslatef(-10,0,-10);

        glScaled(1,1,5);
        glutWireSphere(2,10,10);
    glPopMatrix();










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

	//gluLookAt(100,100,-100,	0,0,0,	0,0,1);
	gluLookAt(300*cos(cameraAngle), 300*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,200,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	drawAxes();
	drawGrid();

    glRotatef(bigHandAngleY,1,0,0);
    glRotatef(bigHandAngle,0,1,0);
    //drawSquare(30);
   // drawSquare(50);
    hand();


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
	cameraHeight=100.0;
	cameraAngle=1.0;
	angle=0;

	bigHandAngle = 0;
	bigHandAngleY = 0;

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
