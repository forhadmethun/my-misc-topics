#include <bits/stdc++.h>
using namespace std;
struct point{
    double x,y,z;
    point(){
        x = 0;
        y = 0;
        z = 0;
    }
};
struct triangle{
    point ab,bc,ca;
};




//a function for creating a 2d matrix and return as int** type... :)
int** create_2d_array(){
    int **array = new int*[4];
    for(int i=0;i<4;i++){
        array[i] = new int[4];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            array[i][j]  = 0;
        }
    }
    return array;
}

//multiplying two mtrix
int** mul(int** mat1, int** mat2,int r1,int c1,int r2,int c2){
    int** mult = create_2d_array();
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
            for(int k = 0; k < c1; ++k)
            {
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }

    return mult;
}

//print the matrix
void print_matrix(int** mat,int row,int col){
    printf("\n==================================\n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    //printf("");
    printf("==================================\n");
}
//input two matrix and check the mul() function
void matrix_multipicatin(){
    //creating first matrix
    int** mult1 = create_2d_array();
    //creating second matrix
    int** mult2 = create_2d_array();
    //creating the matrix which will hold mult = mat1*mat2
    int** mult = create_2d_array();

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

    int **mat = create_2d_array();
    mat[0][0] = 1;
    vector< int** > vi;
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
void delete_memory(int** mat,int row){
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
    point eye,look_at,up;
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
    stack<int**> s;

    //creating first matrix, Identity Matrix
    int** mult1 = create_2d_array();
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
        {
            mult1[i][j]=0;
        }
    mult1[0][0] = 1;
    mult1[1][1] = 1;
    mult1[2][2] = 1;
    mult1[3][3] = 1;
    s.push(mult1);
   // for(auto it= s.)
    int **temp = s.top();
    //print_matrix(temp,4,4);


    while(true){
        //taking input string(triangle,push,triangle,translate,rotate,push,pop,end,scale)
        fgets(buff, 255, (FILE*)fp1);
        string input(buff);
        input.pop_back();

        if(input == "triangle"){

            //taking input of 3 points of a triangle...
            fscanf(fp1,"%lf%lf%lf%lf%lf%lf%lf%lf%lf\n",
                   &t.ab.x ,&t.ab.y ,&t.ab.z,&t.bc.x,&t.bc.y,&t.bc.z,&t.ca.x,&t.ca.y,&t.ca.z);
            v.push_back(t);

        }
        else if(input == "push"){

            continue;
        }
        else if(input == "pop"){
            continue;
        }
        else if(input == "scale"){

           // cin >> scale.x >> scale.y >> scale.z;
            fscanf(fp1,"%lf%lf%lf\n",&scale.x,&scale.y,&scale.z);
        }
        else if(input == "rotate"){

            //cin >> angle >> p.x >> p.y >> p.z;
            fscanf(fp1,"%lf%lf%lf%lf\n",&angle,&p.x,&p.z,&p.z);
        }
        else if(input =="translate"){

            //cin >> translate.x >> translate.y >> translate.z;
            fscanf(fp1,"%lf%lf%lf\n",&translate.x,&translate.y,&translate.z);

        }
        else if(input == "end" || input == "en"){
            break;
        }
        //fgetc(fp1);
    }
    fclose(fp1);
    /*

    fp2 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\out.txt","w");
    fputs("successfully input taken",fp2);
    fclose(fp2);


    fp3  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\out2.txt","w");
    fprintf(fp3,"%d",(int)v.size());
    fclose(fp3);
    */



    stage1  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage1.txt","w");
    //fprintf(stage1,"%d",(int)v.size());
    //stage 1 processing should be here....

    for(int i=0;i<(int)v.size();i++){
        cout << v[i].ab.x << " " << v[i].ab.y << " " << v[i].ab.z << endl;
        cout << v[i].bc.x << " " << v[i].bc.y << " " << v[i].bc.z << endl;
        cout << v[i].ca.x << " " << v[i].ca.y << " " << v[i].ca.z << endl;
        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n",v[i].ab.x,v[i].ab.y,v[i].ab.z);
        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n",v[i].bc.x,v[i].bc.y,v[i].bc.z);
        fprintf(stage1,"%0.7lf %0.7lf %0.7lf\n",v[i].ca.x,v[i].ca.y,v[i].ca.z);
        //cout << endl;
        fprintf(stage1,"\n");
    }

    fclose(stage1);

    stage2  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage2.txt","w");
    //stage 2 processing shoule be here...
    //fprintf(stage2,"%d",(int)v.size());
    fclose(stage2);

    stage3  = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Graphics\\Offline_2\\stage3.txt","w");

    //fprintf(fp3,"%d",(int)v.size());
    //stage 3 processing should be here...

    fclose(stage3);



    return 0;
}

/*
 * http://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function
 */