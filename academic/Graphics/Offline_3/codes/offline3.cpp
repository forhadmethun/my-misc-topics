#include <bits/stdc++.h>
#include "bitmap_image.hpp"

using namespace std;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))


struct point
{
    double x,y,z;
    point()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    point(double px,double py,double pz)
    {
        x = px;
        y = py;
        z = pz;
    }
    point operator = (point p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }

};
struct triangle
{
    point a,b,c;
    point color;
};
struct line
{
    double a, b, c;
};          // a way to represent a line
// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS)                // vertical line is fine
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;           // default values
    }
    else
    {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}
bool areParallel(line l1, line l2)         // check coefficients a & b
{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areIntersect(line l1, line l2, point &p)
{
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}
double** create_2d_array(int row,int col,double value)
{
    double **array = new double*[row];
    for(int i=0; i<row; i++)
    {
        array[i] = new double[col];
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            array[i][j]  = value;
        }
    }
    return array;
}


point** create_2d_array(int row,int col)//,double value)
{
    point **array = new point*[row];
    for(int i=0; i<row; i++)
    {
        array[i] = new point[col];
    }

    return array;
}

template<class T>
void delete_memory(T** mat,int row)
{
    for(int i=0; i<row; i++)
    {
        delete[] mat[i];
        // printf("%d freeing memory\n",i);
    }

//    int **mat = create_2d_array();
//    print_matrix(mat,10,10);
//    delete_memory(mat,10);
//    print_matrix(mat,10,10);
}

int getRow()
{

}
int getCol()
{

}

int main()
{
    srand(time(NULL));
    FILE *fp1,*fp2,*fp3,*fp4,*stage1,*stage2,*stage3;
    //reading config
    fp1=fopen("config.txt","r");

    int Screen_Width, Screen_Height;
    double x_limit, y_limit, z_limit_front,z_limit_rear;
    //config input
    fscanf(fp1,"%d%d%lf%lf%lf%lf",&Screen_Height,&Screen_Width,&x_limit,&y_limit,&z_limit_front,&z_limit_rear);
    cout << "height: " << Screen_Height << ", width:" << Screen_Width << endl;
    //cout << z_limit_rear << endl;
    //reading stage3
    fp2=fopen("stage3.txt","r");
    vector<triangle> v;
    triangle t;
    //taking triangle input ..
    while( fscanf(fp2,"%lf%lf%lf%lf%lf%lf%lf%lf%lf\n", &t.a.x,&t.a.y,&t.a.z,&t.b.x,&t.b.y,&t.b.z,&t.c.x,&t.c.y,&t.c.z)!=EOF)
    {
        t.color.x = rand()%256;
        t.color.y = rand()%256;
        t.color.z = rand()%256;

        // cout << t.color.x << "," << t.color.y << "," << t.color.z << endl;
        v.push_back(t);

    }



//    cout << v.size() << "--> " << v[0].a.x << endl;

    double dx,dy,Top_Y,Left_X;

    dx = 2.0/Screen_Width;
    dy = 2.0/Screen_Height;

    Top_Y= 1-dy/2.0, Left_X = -1+dx/2;
    cout << "dx: " << dx << " , dy:" << dy << endl;
    cout << "top_y: " << Top_Y << " left_x: " << Left_X << endl;;
    cout << endl << endl;

    for(int r=0; r<Screen_Height; r++)
    {
        for(int c=0; c<Screen_Width; c++)
        {
            cout << "(x: " << Left_X+c*dx  << " y: " << Top_Y- r*dy << ")   ";// << endl;
        }
        cout << endl;
    }

    cout << "In real co-ordinate system: " << endl << endl;
    int xx,yy;
    for(int r=0; r<Screen_Height; r++)
    {
        for(int c=0; c<Screen_Width; c++)
        {
            double x,y;
            x =(Left_X+c*dx)*(Screen_Width/2.0);
            y = (Top_Y- r*dy)*(Screen_Height/2.0);

            //cout << "(x: " << (floor) x << " y: " <<(floor) y  << ")   ";// << endl;
            if(r==0&&c==0)
            {
                xx = floor(x);
                yy= floor(y);
                cout << "--> xx: " << xx << " -- yy: " << yy <<  endl;
            }
            //cout << "("<<floor(x) + (-xx)   << ","<< floor(y)   <<")";// << endl;
            //cout << "("<<floor(x) + (-xx)   << ","<< ceil(y)  -(yy)  <<")";// << endl;
            cout << "("<<floor(x) + (Screen_Width/2)   << ","<< ceil(y)  + (Screen_Height/2)  <<")";// << endl;


        }
        cout << endl;
    }

    cout << endl;


    //declaring the z buffer
    cout << "!!!!!!!!!!!!! printing Z buffer !!!!!!!!!!!!!!!!" << endl;
    double **Z_buffer = create_2d_array(Screen_Height + 1,Screen_Width + 1, z_limit_rear );
    point **frame_buffer = create_2d_array(Screen_Height + 1,Screen_Width + 1);

    for(int i=0; i<Screen_Height; i++)
    {
        for(int j=0; j<Screen_Width; j++)
        {
            cout << Z_buffer[i][j] << " ";
        }
        cout << endl;
    }





    //printing triangles...
    cout << "Triangles: " << endl;

    double top_y,bottom_y;
    for(int i=0; i<(int)v.size(); i++)
    {
        cout <<"\t\t("<< v[i].a.x <<"," <<v[i].a.y << ","<< v[i].a.z << ")(" <<  v[i].b.x <<"," <<v[i].b.y << ","<< v[i].b.z << ")("   << v[i].c.x <<"," <<v[i].c.y << ","<< v[i].c.z << ")" << endl;

        point a,b,c;

        point color = v[i].color;

        if(v[i].a.y >= v[i].b.y && v[i].a.y >= v[i].c.y )
        {
            top_y = v[i].a.y;
            a = v[i].a;
            b = v[i].b;
            c = v[i].c;
        }
        else if(v[i].b.y >= v[i].a.y && v[i].b.y >= v[i].c.y )
        {
            top_y = v[i].b.y;
            a = v[i].b;
            b = v[i].a;
            c = v[i].c;
        }
        else
        {
            // cout << "sobsooy ekhonaeii dehuke" << endl;
            top_y = v[i].c.y;
            a = v[i].c;
            b= v[i].b;
            c = v[i].a;

        }

        if(v[i].a.y <= v[i].b.y && v[i].a.y <= v[i].c.y )
        {
            bottom_y = v[i].a.y;
        }
        else if(v[i].b.y <= v[i].a.y && v[i].b.y <= v[i].c.y )
        {

            bottom_y = v[i].b.y;
        }
        else
        {
            //cout << "--------------> " << "bottom" << endl;
            bottom_y = v[i].c.y;
        }
        double ytop,ybottom;
        ytop =top_y*(Screen_Height/2.0);
        ybottom = bottom_y*(Screen_Height/2.0);

        cout <<"bottom_y: "  << bottom_y << " top_y: " << top_y << endl;
        for(double r = bottom_y; r<=top_y; r+=dy)
        {
            cout << "-------> y: " << r << endl;

            line scanLine;
            scanLine.a = 0;
            scanLine.b = 1;
            scanLine.c = -r;


            point leftIntersect, rightIntersect;
            line l1 ;
            pointsToLine(a,b,l1);
            line l2;
            pointsToLine(a,c,l2);

            areIntersect(l1,scanLine,leftIntersect);
            areIntersect(l2,scanLine,rightIntersect);
            if(b.y == a.y)
            {
                leftIntersect.z = a.z;
            }
            else
                leftIntersect.z = a.z - ((b.z - a.z)/(b.y - a.y))* (a.y - leftIntersect.y);

            if(c.y == a.y)
            {
                rightIntersect.z = a.z;
            }
            else
                rightIntersect.z = a.z - ((c.z - a.z)/(c.y -a.y))*(a.y-rightIntersect.y);

            cout << "\t\tleft Intersects: -> (" << leftIntersect.x << "," << leftIntersect.y << ","<< leftIntersect.z<< ")" << endl;
            cout << "\t\tright Intersects: -> (" << rightIntersect.x << "," << rightIntersect.y<<","<< rightIntersect.z << ")" << endl;

            for(double c = leftIntersect.x; c<=rightIntersect.x; c+=dx)
            {
                //linear interpolation...
                //;

                double z;
                if(leftIntersect.z == rightIntersect.z)
                {
                    z = leftIntersect.z;
                }
                else
                    z =  leftIntersect.z + ((rightIntersect.z - leftIntersect.z)/(rightIntersect.x - leftIntersect.x)) * (c - leftIntersect.x);
                cout << "\t\t\t\t interpolation -> x: " << c << ", z: " << z <<  endl;

                point inside(c,r,z);

                ///verify if inside the view plane...
                if((c>=Left_X && c<=-Left_X) && (r <=Top_Y &&  r>=-Top_Y))
                {
                    cout << "\t\t\t\t\t Inside the plane :  " ;

                    int row_index,col_index;

                    // for(int rr=0; rr<Screen_Height; rr++)
                    // {
                    for(int cc=0; cc<Screen_Width; cc++)
                    {

                        //  cout << "(x: " << Left_X+c*dx  << " y: " << Top_Y- r*dy << ")   ";// << endl;
                        if( Left_X+cc*dx < inside.x)
                            row_index = cc;

                    }
                    //cout << endl;
                    // }

                    for(int rr=0;rr<Screen_Height;rr++){
                        if(Top_Y- rr*dy > inside.y){
                            col_index = rr;
                        }

                    }
                    cout << row_index   << "," << col_index << endl;


                    if(inside.x <Z_buffer[row_index][col_index]){
                        Z_buffer[row_index][col_index] = inside.z;
                        frame_buffer[row_index][col_index] =color;
                    }



                    //int r = getRow();
                    //int c = getCol();



                }






            }

        }
    }

















    //creating the image...
    bitmap_image image(Screen_Width,Screen_Height);

    for(int i=0; i<Screen_Height; i++)
    {
        for(int j=0; j<Screen_Width; j++)
        {
            image.set_pixel(i,j,frame_buffer[i][j].x,frame_buffer[i][j].y,frame_buffer[i][j].z);
        }
    }

    image.save_image("output.bmp");

    cout << "!!!!!!!!!!!!! printing Z buffer !!!!!!!!!!!!!!!!" << endl;
//    double **Z_buffer = create_2d_array(Screen_Height + 1,Screen_Width + 1, z_limit_rear );
    //  point **frame_buffer = create_2d_array(Screen_Height + 1,Screen_Width + 1);

    for(int i=0; i<Screen_Height; i++)
    {
        for(int j=0; j<Screen_Width; j++)
        {
            cout << Z_buffer[i][j] << " ";
            // printf("%lf",Z_buffer[i][j]);
        }
        cout << endl;
    }

    //freeing memory


    delete_memory(Z_buffer,Screen_Height);
    delete_memory(frame_buffer,Screen_Height);
    return 0;
}
