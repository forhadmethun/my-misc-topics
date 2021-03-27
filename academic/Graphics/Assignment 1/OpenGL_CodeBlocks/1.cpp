#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#include <windows.h>
#include <glut.h>
using namespace std;
#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;

double radius = 10;

double height = 20;
double corner = 10;
double square_corner= 0;
double theta= (pi * 3.0 )/ 180.0;



struct point
{
	double x,y,z;
};

point pos,l,u,r;

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
		    glColor3f(1.0, 0, 0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);
            glColor3f(0, 1.0, 0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);
            glColor3f(0, 0, 1.0);
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
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		//glVertex3f( a,-a,2);
		glVertex3f( a,-a,0);

		//glVertex3f(-a,-a,2);
		glVertex3f(-a,-a,0);

		//glVertex3f(-a, a,2);
		glVertex3f(-a, a,0);
	}glEnd();

/*
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

*/

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
        glColor3f(1,0,0);
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

void drawCylinder(double radius,double height,int segments)
{
    //radius = radius/2;
    int i;
    double shade;
    struct point points[100];
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);

//        cout << i << "->" << points[i].x << "--- " << points[i].y << endl;
    }
    //draw triangles using generated points
    for(i=0;i<segments;i++)
    {
        //create shading effect
        if(i<segments/2)shade=2*(double)i/(double)segments;
        else shade=2*(1.0-(double)i/(double)segments);
        glColor3f(shade,shade,shade);
         glColor3f(0,1,0);

        glBegin(GL_QUADS);
        {
            //glVertex3f(0,0,height);
            if(points[i].x >=0 && points[i].y >=0)

			glVertex3f(points[i].x,points[i].y,0);
			if(points[i].x>=0 && points[i].y>=0)
			glVertex3f(points[i].x,points[i].y,height);
			if(points[i+1].x>=0 && points[i+1].y>=0)
			glVertex3f(points[i+1].x,points[i+1].y,height);
			if(points[i+1].x>=0 && points[i+1].y>=0)
			glVertex3f(points[i+1].x,points[i+1].y,0);

        }
        glEnd();
    }
}
double fff = 0;
void oneSide()
{
 glTranslatef(0,fff,0);
    glRotatef(45,0,0,1);
   // glTranslatef(0,20-height,0);



    glPushMatrix();


    //glTranslatef(0,height-20,0);

    glPushMatrix();
    //
    glTranslatef(corner,corner,0);
    //
    drawCylinder(radius,height,20);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(corner,corner,0);
    glRotatef(-180,01,1,0);
    //
    drawSphere(radius,20,20);
    glPopMatrix();


    glPopMatrix();


    // cout << "radius : " << radius << " hieght: " << height << " corner: " << corner << endl;


        glPushMatrix();
    ///
    glTranslatef(corner,corner,height);
    glColor3f(1,0,0);
    //
    drawSphere(radius,20,20);
    glPopMatrix();

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


double unitConvert(double x,double y,double z,double c)
{
    return c/sqrt(x*x + y*y+z*z);
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){
        point l_;
        point u_;
          point r_;

		case '1':
		             		//	point l_;
			l_.x = l.x;
			l_.y = l.y;
			l_.z = l.z;


        l.x = l.x*cos(theta) -r.x * sin(theta);
        l.y = l.y * cos(theta)  - r.y* sin(theta);
        l.z = l.z *cos(theta) - r.z*sin(theta);

        l.x = unitConvert(l.x,l.y,l.z,l.x);
        l.y = unitConvert(l.x,l.y,l.z,l.y);
        l.z = unitConvert(l.x,l.y,l.z,l.z);


        r.x = r.x*cos(theta) +l_.x*sin(theta);
        r.y = r.y*cos(theta) +l_.y*sin(theta);
        r.z = r.z*cos(theta) + l_.z*sin(theta);

        r.x = unitConvert(r.x,r.y,r.z,r.x);
        r.y = unitConvert(r.x,r.y,r.z,r.y);
        r.z = unitConvert(r.x,r.y,r.z,r.z);
			//drawgrid=1-drawgrid;


			break;

        case '2':

            l_.x = l.x;
			l_.y = l.y;
			l_.z = l.z;


        l.x = l.x*cos(theta) +r.x * sin(theta);
        l.y = l.y * cos(theta)  + r.y* sin(theta);
        l.z = l.z *cos(theta) + r.z*sin(theta);

        l.x = unitConvert(l.x,l.y,l.z,l.x);
        l.y = unitConvert(l.x,l.y,l.z,l.y);
        l.z = unitConvert(l.x,l.y,l.z,l.z);


        r.x = r.x*cos(theta) -l_.x*sin(theta);
        r.y = r.y*cos(theta) -l_.y*sin(theta);
        r.z = r.z*cos(theta) - l_.z*sin(theta);

        r.x = unitConvert(r.x,r.y,r.z,r.x);
        r.y = unitConvert(r.x,r.y,r.z,r.y);
        r.z = unitConvert(r.x,r.y,r.z,r.z);



            break;
        case '3':
			l_.x = l.x;
			l_.y = l.y;
			l_.z = l.z;


        l.x = l.x*cos(theta) -u.x * sin(theta);
        l.y = l.y * cos(theta)  - u.y* sin(theta);
        l.z = l.z *cos(theta) - u.z*sin(theta);

        l.x = unitConvert(l.x,l.y,l.z,l.x);
        l.y = unitConvert(l.x,l.y,l.z,l.y);
        l.z = unitConvert(l.x,l.y,l.z,l.z);


        u.x = u.x*cos(theta) +l_.x*sin(theta);
        u.y = u.y*cos(theta) +l_.y*sin(theta);
        u.z = u.z*cos(theta) + l_.z*sin(theta);

        u.x = unitConvert(u.x,u.y,u.z,u.x);
        u.y = unitConvert(u.x,u.y,u.z,u.y);
        u.z = unitConvert(u.x,u.y,u.z,u.z);
			//drawgrid=1-drawgrid;


        break;

        case '4':

			l_.x = l.x;
			l_.y = l.y;
			l_.z = l.z;


        l.x = l.x*cos(theta) +u.x * sin(theta);
        l.y = l.y * cos(theta)  + u.y* sin(theta);
        l.z = l.z *cos(theta) + u.z*sin(theta);

        l.x = unitConvert(l.x,l.y,l.z,l.x);
        l.y = unitConvert(l.x,l.y,l.z,l.y);
        l.z = unitConvert(l.x,l.y,l.z,l.z);


        u.x = u.x*cos(theta) -l_.x*sin(theta);
        u.y = u.y*cos(theta) -l_.y*sin(theta);
        u.z = u.z*cos(theta) - l_.z*sin(theta);

        u.x = unitConvert(u.x,u.y,u.z,u.x);
        u.y = unitConvert(u.x,u.y,u.z,u.y);
        u.z = unitConvert(u.x,u.y,u.z,u.z);

            break;
        case '5':
                     r_.x = r.x;
			r_.y = r.y;
			r_.z = r.z;


        r.x = r.x*cos(theta) -r.x * sin(theta);
        r.y = r.y * cos(theta)  - r.y* sin(theta);
        r.z = r.z *cos(theta) - r.z*sin(theta);

        r.x = unitConvert(r.x,r.y,r.z,r.x);
        r.y = unitConvert(r.x,r.y,r.z,r.y);
        r.z = unitConvert(r.x,r.y,r.z,r.z);


        u.x = u.x*cos(theta) +r_.x*sin(theta);
        u.y = u.y*cos(theta) +r_.y*sin(theta);
        u.z = u.z*cos(theta) + r_.z*sin(theta);

        u.x = unitConvert(u.x,u.y,u.z,u.x);
        u.y = unitConvert(u.x,u.y,u.z,u.y);
        u.z = unitConvert(u.x,u.y,u.z,u.z);


            break;
        case '6':
                r_.x = r.x;
			r_.y = r.y;
			r_.z = r.z;


        r.x = r.x*cos(theta) +r.x * sin(theta);
        r.y = r.y * cos(theta)  + r.y* sin(theta);
        r.z = r.z *cos(theta) + r.z*sin(theta);

        r.x = unitConvert(r.x,r.y,r.z,r.x);
        r.y = unitConvert(r.x,r.y,r.z,r.y);
        r.z = unitConvert(r.x,r.y,r.z,r.z);


        u.x = u.x*cos(theta) -r_.x*sin(theta);
        u.y = u.y*cos(theta) -r_.y*sin(theta);
        u.z = u.z*cos(theta) - r_.z*sin(theta);

        u.x = unitConvert(u.x,u.y,u.z,u.x);
        u.y = unitConvert(u.x,u.y,u.z,u.y);
        u.z = unitConvert(u.x,u.y,u.z,u.z);

            break;

		default:
			break;
	}
}

void drawUpperSphere(){
        //drawSquare(30);

    drawSphere(20,20,20);

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
			cameraAngle += 0.03;
			pos.x++;
			pos.y++;
			break;

		case GLUT_KEY_UP:		// up arrow key
			cameraHeight += 3.0;
			pos.x--;
			pos.y--;
			break;

		case GLUT_KEY_RIGHT:
            pos.x--;
            pos.y++;

			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.03;
			pos.x++;
            pos.y--;

			break;

		case GLUT_KEY_PAGE_UP:
		    pos.z++;
			break;
		case GLUT_KEY_PAGE_DOWN:
		    pos.z--;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
		    if(radius<30){
            fff+=0.7;
            radius++;
            height--;
            corner-=1;
            square_corner-=1;
		    }

			break;
		case GLUT_KEY_END:
		    if(corner<20){
                    fff -=0.7;
            radius--;
            height++;
            corner+=1;
            square_corner+=1;
		    }


			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				//drawaxes=1-drawaxes;
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
	//gluLookAt(100*cos(cameraAngle), 100*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(pos.x, pos.y, pos.z,pos.x + l.x, pos.y + l.y, pos.z + l.z,u.x, u.y, u.z);
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

    //glRotatef(45,0,0,1);
    //glTranslatef(0,14,0);
    //oneSide();

    //glScalef(0.5,0.5,1);

    glPushMatrix();
      glRotatef(-45,0,0,1);
    glPushMatrix();

    glPushMatrix();

    glPushMatrix();

    glPushMatrix();
    glPushMatrix();
    oneSide();
    glPopMatrix();

   //glTranslatef(90,20,0);
    glRotatef(90,0,0,1);
    oneSide();
    glPopMatrix();

    glRotatef(180,0,0,1);
    oneSide();

    glPopMatrix();

    glRotatef(270,0,0,1);
    oneSide();

    glPopMatrix();

    glTranslatef(0,0,-10);

    glRotatef(45,0,0,1);
    //
    drawSquare(square_corner);
    glPopMatrix();

    glTranslatef(0,0,10+20);
    glRotatef(45,0,0,1);
    //
    drawSquare(square_corner);
    glPopMatrix();


    glPushMatrix();
         glTranslatef(-corner,corner,0);
      // glRotatef(90,1,1,  0);
         glRotatef(90,0,01,0);
         //
        drawCylinder(radius,height,20);
    glPopMatrix();




     glPushMatrix();
     glRotatef(180,0,0,1);
         glTranslatef(-corner,corner,0);
      // glRotatef(90,1,1,  0);
         glRotatef(90,0,01,0);
         //
        drawCylinder(radius,height,20);
    glPopMatrix();




        glPushMatrix();
            glTranslatef(-corner,corner,height);
            glRotatef(90,1,0,0);
            glRotatef(90,0,1,0);
            //
            drawCylinder(radius,height,20);
        glPopMatrix();

        //2nd opposite
         ///now i am working here

         glPushMatrix();
            glRotatef(180,0,0,1);
            glTranslatef(-corner,corner,height);
            glRotatef(90,1,0,0);
            glRotatef(90,0,1,0);
            drawCylinder(radius,height,20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-corner,0,0);
            glRotatef(90,0,0,1);
            glTranslatef(-corner,0,0);
            glRotatef(90,0,1,0);
            drawCylinder(radius,height,20);
        glPopMatrix();

        glPushMatrix();
            glRotatef(180,0,0,1);
            glTranslatef(-corner,0,0);
            glRotatef(90,0,0,1);
            glTranslatef(-corner,0,0);
            glRotatef(90,0,1,0);
            drawCylinder(radius,height,20);
        glPopMatrix();
//here is a problem
        glPushMatrix();
            glTranslatef(-corner,0,height);
            glRotatef(90,0,0,1);
            glTranslatef(-corner,0,0);
            glRotatef(90,1,0,0);
            glRotatef(90,0,1,0);
            drawCylinder(radius,height,20);
        glPopMatrix();
        glPushMatrix();
            glRotatef(180,0,0,1);
           glTranslatef(-corner,0,height );
            glRotatef(90,0,0,1);
            glTranslatef(-corner,0,0);
            glRotatef(90,1,0,0);
            glRotatef(90,0,1,0);
            drawCylinder(radius,height,20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,20,0);
        glTranslatef(0,0,10);
        glRotatef(90,1,0,0);
        //
        drawSquare(square_corner);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(0,-20,0);
        glTranslatef(0,0,10);

        glRotatef(90,1,0,0);
        //
        drawSquare(square_corner);
    glPopMatrix();

         glPushMatrix();
       glTranslatef(20,0,0);
       glRotatef(90,0,0,1);
        glTranslatef(0,0,10);
        glRotatef(90,1,0,0);
        //
        drawSquare(square_corner);
    glPopMatrix();

             glPushMatrix();
       glTranslatef(-20,0,0);
       glRotatef(90,0,0,1);
        glTranslatef(0,0,10);
        glRotatef(90,1,0,0);
        //
        drawSquare(square_corner);

    glPopMatrix();






     cout << "radius : " << radius << " hieght: " << height << " corner: " << corner << " Square corner " << square_corner << endl;


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
	square_corner = corner;
	angle=0;
	pos.x = 100;
	pos.y = 100;
	pos.z = 0;

    l.x = -1.0/(sqrt(2));
    l.y = -1.0/sqrt(2);
    l.z = 0;

    u.x = 0;
    u.y = 0;
	u.z = 1;

	r.x = -1.0/sqrt(2.0);
	r.y = 1.0/sqrt(2.0);
	r.z = 0;


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
