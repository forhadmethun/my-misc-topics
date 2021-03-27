#include <bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
struct point{
    double x,y,z;
    point(){
        x = 0;
        y = 0;
        z = 0;
    }
    point(double px,double py,double pz){
        x = px;
        y = py;
        z = pz;
    }
   point operator = (point p){
        x = p.x;
        y = p.y;
        z = p.z;
    }

};
struct triangle{
    point a,b,c;
};

point R(point x,point a,double theta){
    point p;
    theta = (pi * theta )/180.0;
    p.x = x.x * cos(theta) + (1-cos(theta))*(a.x*x.x + a.y *x.y + a.z * x.z)*a.x + sin(theta)*(a.y*x.z - x.y*a.z);
    p.y = x.y * cos(theta) + (1-cos(theta))*(a.x*x.x + a.y *x.y + a.z *x.z) *a.y + sin(theta)*(a.z*x.x - a.x*x.z);
    p.z = x.z * cos(theta) + (1-cos(theta))*(a.x*x.x + a.y *x.y + a.z *x.z) *a.z + sin(theta)*(a.x*x.y - a.y*x.x);
    return p;
}



//a function for creating a 2d matrix and return as int** type... :)
double** create_2d_array(){
    double **array = new double*[4];
    for(int i=0;i<4;i++){
        array[i] = new double[4];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            array[i][j]  = 0;
        }
    }
    return array;
}

//multiplying two mtrix
double** mul(double** mat1, double** mat2,int r1,int c1,int r2,int c2){
    double** mult = create_2d_array();
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j){
            for(int k = 0; k < c1; ++k) {
                mult[i][j] += mat1[i][k] * mat2[k][j];
                //mult[i][j] <<

            }
           // cout << mult[i][j]  << " ";

        }

    return mult;
}

//print the matrix
void print_matrix(double** mat,double row,int col){
    printf("\n==================================\n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%0.7lf ",mat[i][j]);
        }
        printf("\n");
    }
    //printf("");
    printf("==================================\n");
}
//input two matrix and check the mul() function
void matrix_multipicatin(){
    //creating first matrix
    double** mult1 = create_2d_array();
    //creating second matrix
    double** mult2 = create_2d_array();
    //creating the matrix which will hold mult = mat1*mat2
    double** mult = create_2d_array();

    //initialize matrix 1
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
        {
            mult1[i][j]=0;
        }
    mult1[0][0] = 1;
    mult1[1][1] = 1;
    mult1[2][2] = 1;
    mult1[3][3] = 1;

    //initialize matrix 2;
//    for(int i = 0; i < 4; ++i)
//        for(int j = 0; j < 4; ++j)
//        {
//            mult2[i][j]=1;
//        }
//
//    mult2[0][0] = 1;
//    mult2[1][1] = 2;
//    mult2[2][2] = 3;
//    mult2[3][3] = 4;
    //initialize matrix two
    mult2[0][0] = 1;
    mult2[1][0] = 2;
    mult2[2][0] = 3;
    mult2[3][0] = 4;


    //printing the content of the matrix
    print_matrix(mult1,4,4);
    printf("\n");
    print_matrix(mult2,4,1);
    printf("\n");


    //multiplying the matrix
    mult = mul(mult1,mult2,4,4,4,1);
    print_matrix(mult,4,1);

}

//array of matrix
void vector_of_matrix(){

    double **mat = create_2d_array();
    mat[0][0] = 1;
    vector< double** > vi;
    vi.push_back(mat);
    mat = create_2d_array();
    mat[0][0] = 2;
    vi.push_back(mat);

    for(int i=0;i<vi.size();i++){
        print_matrix(vi[i],4,4);
        printf("\n");
    }

}
//we should clear the memory after creating...2d matrix with new operator
void delete_memory(double** mat,int row){
    for(int i=0;i<row;i++){
        delete[] mat[i];
        printf("freeing memory\n");
    }

//    int **mat = create_2d_array();
//    print_matrix(mat,10,10);
//    delete_memory(mat,10);
//    print_matrix(mat,10,10);
}

void transformPoint(int **top,point p){


}




int main(){
    // input from file and print to three different files ...

    FILE *fp1,*fp2,*fp3,*fp4,*stage1,*stage2,*stage3;
    //input the strings
    char buff[255];

    fp1=fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\scene.txt","r");
    point eye,look_at,up,l,r,u,a;
    double field_of_view, aspect_ratio, near, far;
    //cin >> eye.x >> eye.y >> eye.z >> look_at.x >> look_at.y >> look_at.z >> up.x >> up.y >> up.z;
    //input gluLookAt
    fscanf(fp1,"%lf%lf%lf%lf%lf%lf%lf%lf%lf\n",&eye.x,&eye.y,&eye.z,&look_at.x,&look_at.y,&look_at.z,&up.x,&up.y,&up.z);
    //cin >> field_of_view >> aspect_ratio>>near >> far;
    //input gluPerspective
    fscanf(fp1,"%lf%lf%lf%lf\n",&field_of_view,&aspect_ratio,&near,&far);
    //getchar();
    //fgetc(fp1);

    string input;

    triangle t;
    point scale;
    double angle;point p;
    point translate;

    vector<triangle> v;
    stack<double**> s;

    //creating first matrix, Identity Matrix
    double** mult1 = create_2d_array();

    mult1[0][0] = 1;
    mult1[1][1] = 1;
    mult1[2][2] = 1;
    mult1[3][3] = 1;
    s.push(mult1);
   // for(auto it= s.)

  //  print_matrix(temp,4,4);
    stack<int> si;

    stage1  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage1.txt","w");
    while(true){
        //taking input string(triangle,push,triangle,translate,rotate,push,pop,end,scale)
        fgets(buff, 255, (FILE*)fp1);
        string input(buff);
        input.pop_back();

        if(input == "triangle"){

            //taking input of 3 points of a triangle...
            fscanf(fp1,"%lf%lf%lf%lf%lf%lf%lf%lf%lf\n",
                   &t.a.x ,&t.a.y ,&t.a.z,&t.b.x,&t.b.y,&t.b.z,&t.c.x,&t.c.y,&t.c.z);
            double **a,**b,**c;
            a = create_2d_array();
            b = create_2d_array();
            c = create_2d_array();
            a[0][0] = t.a.x;
            a[1][0] = t.a.y;
            a[2][0] = t.a.z;
            a[3][0] = 1;

            b[0][0] = t.b.x;
            b[1][0] = t.b.y;
            b[2][0] = t.b.z;
            b[3][0] = 1;

            c[0][0] = t.c.x;
            c[1][0] = t.c.y;
            c[2][0] = t.c.z;
            c[3][0] = 1;

            double **resulta,**resultb,**resultc;
            //transform_point
            print_matrix(s.top(),4,4);

            resulta = mul(s.top(),a,4,4,4,1);
            resultb = mul(s.top(),b,4,4,4,1);
            resultc = mul(s.top(),c,4,4,4,1);
            /*
            cout << "********************************** " << endl;
         print_matrix(resulta,4,1);
            print_matrix(resultb,4,1);
            print_matrix(resultc,4,1);
            cout << "********************************** " << endl;
            */
            t.a.x = resulta[0][0];
            t.a.y = resulta[1][0];
            t.a.z = resulta[2][0];

            t.b.x = resultb[0][0];
            t.b.y = resultb[1][0];
            t.b.z = resultb[2][0];

            t.c.x = resultc[0][0];
            t.c.y = resultc[1][0];
            t.c.z = resultc[2][0];



            v.push_back(t);


        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n",t.a.x,t.a.y,t.a.z);
        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n",t.b.x,t.b.y,t.b.z);
        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n\n",t.c.x,t.c.y,t.c.z);


        }
        else if(input == "push"){
            si.push((int)s.size());
           // continue;
        }
        else if(input == "pop"){
          int pop_size = (int)s.size() - si.top();

            int y = 0;
            /*
            for(int i= ((int) si.top()- 1 );i<s.size();i++){
                y++;
                s.pop();
            }
             */
            for(int i=0;i<pop_size;i++){
                s.pop();
                y++;
            }
           // cout << "--> " <<  pop_size  << endl;
            si.pop();


            //continue;
        }
        else if(input == "scale"){

           // cin >> scale.x >> scale.y >> scale.z;
            fscanf(fp1,"%lf%lf%lf\n",&scale.x,&scale.y,&scale.z);
            double** sc = create_2d_array();
            sc[0][0] = scale.x;
            sc[1][1] = scale.y;
            sc[2][2] = scale.z;
            sc[3][3] = 1;

            double **temp = s.top();
            double **ans = mul(temp,sc,4,4,4,4);
            /*
            //cheking identity matrix
            cout << "checking idendityt Matrix" << endl;
            print_matrix(temp,4,4);
            //checking
            cout << "checking scaling operation" << endl;
            print_matrix(sc,4,4);
             */
            s.push(ans);


        }
        else if(input == "rotate"){

            //cin >> angle >> p.x >> p.y >> p.z;
            fscanf(fp1,"%lf%lf%lf%lf\n",&angle,&a.x,&a.y,&a.z);
            //normalizing a
            double sq = sqrt(a.x*a.x + a.y*a.y + a.z *a.z);
            a.x = a.x / sq;
            a.y = a.y / sq;
            a.z = a.z / sq;

            point c1,c2,c3,i(1,0,0),j(0,1,0),k(0,0,1);


            c1 = R(i,a,angle);
            c2 = R(j,a,angle);
            c3 = R(k,a,angle);




            double** sc = create_2d_array();
            sc[0][0] = c1.x;
            sc[1][0] = c1.y;
            sc[2][0] = c1.z;

            sc[0][1] = c2.x;
            sc[1][1] = c2.y;
            sc[2][1] = c2.z;

            sc[0][2] = c3.x;
            sc[1][2] = c3.y;
            sc[2][2] = c3.z;

            sc[3][3] = 1;
            /*
            cout<<"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
            print_matrix(sc,4,4);
            cout<<"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;

            */




            print_matrix(sc,4,4);
            double **temp = s.top();
            double **ans = mul(temp,sc,4,4,4,4);

            cout << "checking rotation matrix" << endl;
            print_matrix(temp,4,4);
            print_matrix(ans,4,4);

            s.push(ans);







        }
        else if(input =="translate"){

            //cin >> translate.x >> translate.y >> translate.z;
            fscanf(fp1,"%lf%lf%lf\n",&translate.x,&translate.y,&translate.z);
            double** sc = create_2d_array();
            sc[0][0] = 1;
            sc[1][1] = 1;
            sc[2][2] = 1;
            sc[3][3] = 1;

            sc[0][3] = translate.x;
            sc[1][3] = translate.y;
            sc[2][3] = translate.z;

            double **temp = s.top();
            double **ans = mul(temp,sc,4,4,4,4);
            /*
            cout << "checking translate" << endl;
            print_matrix(ans,4,4);
             */
            s.push(ans);

        }
        else if(input == "end" || input == "en"){
            break;
        }
        //fgetc(fp1);
    }
    fclose(stage1);
    //View Transformation


    stage1  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage1.txt","r");
    stage2 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage2.txt","w");
    double** T = create_2d_array();
    T[0][3] = - eye.x;
    T[1][3] = -eye.y;
    T[2][3] = -eye.z;

    T[0][0] = 1;
    T[1][1] = 1;
    T[2][2] = 1;
    T[3][3] = 1;
//http://www.sanfoundry.com/cpp-program-compute-cross-product-two-vectors/
    l.x = look_at.x - eye.x;
    l.y = look_at.y - eye.y;
    l.z = look_at.z - eye.z;
    double sq = sqrt(l.x*l.x + l.y*l.y + l.z*l.z);
    l.x = l.x / sq;
    l.y = l.y / sq;
    l.z = l.z / sq;


    r.x = l.y * up.z - up.y * l.z;
    r.y = up.x *l.z - l.x * up.z;
    r.z =l.x * up.y - up.x * l.y;

    sq = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);;
    r.x = r.x / sq;
    r.y = r.y / sq;
    r.z = r.z / sq;


    u.x = r.y*l.z  - l.y * r.z;
    u.y =  l.x  *r.z -r.x  * l.z;
    u.z = r.x *l.y - l.x*r.y;



    double** R = create_2d_array();
    R[0][0] = r.x;
    R[0][1] = r.y;
    R[0][2] = r.z;

    R[1][0] = u.x;
    R[1][1]  = u.y;
    R[1][2] = u.z;
    R[2][0] = -l.x;
    R[2][1] = -l.y;
    R[2][2] = -l.z;
    R[3][3] = 1;

    double **V = mul(R,T,4,4,4,4);
   // print_matrix(V,4,4);

    double x, y, z;
    int sum = 0;
    //printf("dhukse");
    while (fscanf(stage1, "%lf%lf%lf\n", &x, &y, &z) != EOF) {
        //printf("-> --> %0.7f %0.7f %0.7f\n",x,y,z);
       // printf("dhuksiii");

        double **p = create_2d_array();
        p[0][0] = x;
        p[1][0] = y;
        p[2][0] = z;
        p[3][0] = 1;
       // cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! start " <<endl;
      //  print_matrix(V,4,4);
       // print_matrix(p,4,4);
       // cout << "!!!!!!!!!!!!!!!!!!!!!! end" << endl;

       double **ans = mul(V, p , 4, 4, 4, 4);
        //print_matrix(ans,4,4);
       // cout << "-->" << x << " - " << y << " " <<  z << endl;

        //printf("--------------------");
       // print_matrix(ans,4,4);
        fprintf(stage2, "%0.07f %0.07f %0.07f\n", ans[0][0], ans[1][0], ans[2][0]);
       // print_matrix(ans,4,4);

        sum++;
        if (sum % 3 == 0)fprintf(stage2, "\n");



    }
    fclose(stage2);






    //Projection Transformation
    stage2  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage2.txt","r");
    //stage 2 processing shoule be here...
    //fprintf(stage2,"%d",(int)v.size());
    stage3  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage3.txt","w");

    //fprintf(fp3,"%d",(int)v.size());
   // printf("asheni ");

        //double x, y, z;
         sum = 0;
        while (fscanf(stage2, "%lf%lf%lf\n", &x, &y, &z) != EOF) {
            //printf("-> %0.7f %0.7f %0.7f\n",x,y,z);
            double **p = create_2d_array();
            p[0][0] = x;
            p[1][0] = y;
            p[2][0] = z;
            p[3][0] = 1;
           // print_matrix(p,4,4);

            double fovX, fovY, t, r;
            fovY = field_of_view;
            fovX = field_of_view * aspect_ratio;

            fovY = (fovY * pi) / 180.0;
            fovX = (fovX * pi) / 180.0;

            t = near * tan(fovY / 2.0);
            r = near * tan(fovX / 2.0);

            double **projection_matrix = create_2d_array();
            projection_matrix[0][0] = near / r;
            projection_matrix[1][1] = near / t;
            projection_matrix[2][2] = -(far + near) / (far - near);
            projection_matrix[2][3] = -(2.0 * far * near) / (far - near);
            projection_matrix[3][2] = -1.0;

            double **ans = mul(projection_matrix, p, 4, 4, 4, 4);
            double d = ans[3][0];
            fprintf(stage3, "%0.07f %0.07f %0.07f\n", ans[0][0]/d, ans[1][0]/d, ans[2][0]/d);



            //print_matrix(projection_matrix,4,4);
           // print_matrix(ans,4,4);

            sum++;
            if (sum % 3 == 0)fprintf(stage3, "\n");

        }
        //stage 3 processing should be here...

        fclose(fp1);
        fclose(stage2);
        fclose(stage3);


        return 0;
    }

/*
 * http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function
 */