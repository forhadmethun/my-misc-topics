#include <bits/stdc++.h>
#include "bitmap_image.hpp"

using namespace std;
bitmap_image image(500,500),image2(500,500),image3(500,500);

int width = 500/2,height = 500/2;
void initialization(int &x,int &y){
    x = width/2;
    y = height/2;
}
void changeThePoint(int x,int y, int &a,int &b){
    if(x>=0 && y>=0){
        a = width + x;
        b = height - y;
    }
    else if(x>=0 && y <=0){
        a = width + x;
        b = height - y;
    }
    else if(x <=0 && y >=0){
        a = width + x;
        b = height - y;
    }
    else if(x <=0 && y <= 0 ){
        a = width + x;
        b = height - y;
    }
}

bool isTrue(int a,int b,int c, int x,int y){
    if(a * x + b * y + c == 0)return true;
    return false;
}

bool drawLine(int a,int b,int c){
    for(int i=-height/2;i<height/2;i++){
        for(int j=-width/2;j<width/2;j++){
            int p,q;
            changeThePoint(i,j,p,q);
           // cout << "(" << i << "," << j <<") => " << "("<< p << "," << q << ")" << endl;
            if(isTrue(a,b,c,i,j)){
                image.set_pixel(p,q,0,0,0);
                image2.set_pixel(p,q,0,0,0);
                image3.set_pixel(p,q,0,0,0);
             //   cout << "(" << p << "," << q << ")" << endl;
            }
           // cout << "(" << i << "," << j <<") => " << "("<< p << "," << q << ")" << endl;
           // if(i==j) image.set_pixel(p,q,0,0,0);
        }
    }
}

void swap(int& a, int &b){
    int t = a;
    a = b;
    b = t;
}

//void midPointLine(int x1,int y1,int x2,int y2){
//    int dx = abs(x1-x2);
//    int dy = abs(y1-y2);
//
//    bool flag = false;
//
//    if(dy>dx){
//        swap(x1,y1);
//        swap(x2,y2);
//        swap(dx,dy);
//        flag = true;
//    }
//    if(x1>x2){
//        swap(x1,x2);
//        swap(y1,y2);
//
//    }
//    int incry;
//    if(y1 > y2){
//        incry  = -1;
//    }
//    else{
//        incry = +1;
//    }
//    int d = 2 * dy - dx;
//    int incre = 2 * dy;
//    int incrne = 2 * (dy - dx);
//    while( x1 < x2){
//        if(d <= 0){
//            d += incre;
//        }else{
//            d += incrne;
//            y1+= incry;
//        }
//        x1++;
//
//        int p,q;
//        changeThePoint(x1,y1,p,q);
//
//        if(flag){
//            image.set_pixel(q,p,0,0,0);
//        }
//        else{
//            image.set_pixel(p,q,0,0,0);
//        }
//    }
//}

void midPoint(int x0,int y0,int x1,int y1){
    if(x1 < x0){
        swap(x0,x1);
        swap(y0,y1);
    }
    int dx,dy;double m;
    dx = x1 - x0;
    dy = y1 - y0;
    m = (double)dx / double(dy)  * 1.00;
    if(m >= 0.0  && m <= 1.0){
        int d,incrE,incrNE,x,y;
        d = (2*dy) - dx;
        incrE = 2 * dy;
        incrNE = 2 * (dy - dx);
        x = x0;
        y = y0;
        int p,q;
        changeThePoint(x,y, p,q);
        image.set_pixel(p,q,0,0,0);

        while(x<x1)
        {
            if(d<=0)
            {
                d+=incrE;
                x++;
            }
            else
            {

                d+=incrNE;
                x++;
                y++;
            }

            int p,q;
            changeThePoint(x,y, p,q);
            image.set_pixel(p,q,0,0,0);
        }



    }
    if(m < -1.0){
        int d,incrE,incrNE,x,y;
        d = dy + 2*dx;
        incrE = 2 * dx;
        incrNE = 2* ( dy + dx);
        x = x0;
        y = y0;


        int p,q;
        changeThePoint(x,y, p,q);
        image.set_pixel(p,q,0,0,0);

        while(x<x1)
        {
            if(d<=0)
            {
                d+=incrE;
                y--;
            }
            else
            {

                d+=incrNE;
                x++;
                y--;
            }
            //cout<<d<<endl;
            int p,q;
            changeThePoint(x,y, p,q);
            image.set_pixel(p,q,0,0,0);

        }


    }
    if(m >=-1.0 && m < 0.0){
        int d,incrE,incrNE,x,y;
        d = (2*dy) + dx;
        incrE = 2 * dy;
        incrNE = 2 * (dy + dx);
        x = x0;
        y = y0;

        int p,q;
        changeThePoint(x,y, p,q);
        image.set_pixel(p,q,0,0,0);


        while(x<x1)
        {
            if(d>=0)
            {
                d+=incrE;
                x++;
            }
            else
            {

                d+=incrNE;
                x++;
                y--;
            }
            //cout<<d<<endl;
           // WritePixel(image,x,y);
            int p,q;
            changeThePoint(x,y, p,q);
            image.set_pixel(p,q,0,0,0);

        }

    }
    if(m>1.0){
        int d,incrE,incrNE,x,y;
        d = dy - 2 * dx;
        incrE = -2 * dx;
        incrNE = 2 * (dy - dx);
        x = x0 ; y = y0;

        int p,q;
        changeThePoint(x,y, p,q);
        image.set_pixel(p,q,0,0,0);


        while(x<x1)
        {
            if(d<0)
            {
                d+=incrNE;
                y++;
            }
            else
            {

                d+=incrE;
                x++;
                y++;
            }
            //cout<<d<<endl;
            //WritePixel(image,x,y);
            int p,q;
            changeThePoint(x,y, p,q);
            image.set_pixel(p,q,0,0,0);

        }

    }








}

void AAGuptaSproull(int x0,int y0,int x1,int y1){
    int dx,dy,d,incrE,incrNE; double var1,var2,var3,x,y;
    dx = x1-x0; dy =y1-y0;d = 2*dy - dx;incrE = 2 * dy;incrNE = 2 * (dy - dx );
    var1 = 0;
    var2 = 1.0/(2.0 *sqrt( (double)(dx * dx + dy * dy)) );
    var3 = 2.0 * dy * var2;
    x = x0;
    y = y0;

    int p,q;
    changeThePoint(x,y, p,q);
    //image.set_pixel(p,q,0,0,0);

    image3.set_pixel(p,q,0,0,0);
    image3.set_pixel(p,q+1,0,0,0);
//    image3.set_pixel(p,q+1,var3);
    image3.set_pixel(p,q-1,0,0,0);
//    image3.set_pixel(p,q-1,var3);

    while(x < x1){
        if(d>=0){
            var1 = d - dx;
            d+=incrNE;
            x++;y++;
        }
        else{
            var1 = d+dx;
            d += incrE;
            x++;
        }

        int p,q;
        changeThePoint(x,y, p,q);
        //image.set_pixel(p,q,0,0,0);


        image3.set_pixel(p,q,0,0,0);
//        image3.set_pixel(p,q,var1 * var2);
        image3.set_pixel(p,q+1,0,0,0 );
//        image3.set_pixel(p,q+1,var3 - var1 * var2 );
        image3.set_pixel(p,q-1,0,0,0);
//        image3.set_pixel(p,q-1,var3 + var1 * var2 );
//        cout << "--> "<< "duchaaaaaaa" << endl;

    }


}
void AAUnweightedAreaSampling(){

}
//bool drawCircle(int r){
//    for(int i=-250;i<250;i++){
//        for(int j=-250;j<250;j++){
//            int p,q;
//            changeThePoint(i,j,p,q);
//            cout << "circle-> (" << i << "," << j <<") => " << "("<< p << "," << q << ")" << endl;
//            if((i*i + j *j - r * r) <=0){
//                image.set_pixel(p,q,0,0,0);
//                cout << "dhuksiiiiii -> (" << p << "," << q << ")" << endl;
//            }
//            // cout << "(" << i << "," << j <<") => " << "("<< p << "," << q << ")" << endl;
//            // if(i==j) image.set_pixel(p,q,0,0,0);
//        }
//    }
//}

int main(){
//    cout << "hello test" << endl;
    //freopen("/home/forhadmethun/CLionProjects/Code/Others/Graphics/out.txt","w",stdout);
    freopen("/home/forhadmethun/CLionProjects/Code/Others/Graphics/in.txt","r",stdin);
    cin >> height >> width;
    height /= 2;
    width /= 2;


    for(int i=0;i<height*2;i++){
        for(int j=0;j<width*2;j++){
            image.set_pixel(i,j,255,255,255);
            image2.set_pixel(i,j,255,255,255);
            image3.set_pixel(i,j,255,255,255);

        }
    }


//    for(int i=0;i<500;i++){
//        for(int j=0;j<500;j++){
//           if(i==j) image.set_pixel(i,j,0,0,0);
//        }
//    }
    //x axes

    drawLine(0,1,0);


    //drawLine(0,1,-40);
    //y axes

    drawLine(1,0,0);

    int tc;
    cin >> tc;
    while(tc--){
        int x0,y0,x1,y1;
        cin >> x0 >> y0 >> x1 >> y1;
        midPoint(x0,y0,x1,y1);
        AAGuptaSproull(x0,y0,x1,y1);
    }


    // y = x
   // drawLine(1,-1,0);
    // y = 2x
    //drawLine(1,-2,0);
    // y = -x
    //drawLine(1,1,0);

    //y = mx + c
    //drawLine(2,-3,-30);
    //drawLine(2,-3,40);
//    drawCircle(30);


//    for(int i=-250;i<250;i++){
//        for(int j=-250;j<250;j++){
//            int p,q;
//            changeThePoint(i,j,p,q);
//           // cout << "(" << i << "," << j <<") => " << "("<< p << "," << q << ")" << endl;
//           if(i==j) image.set_pixel(p,q,0,0,0);
//        }
//    }


    image.save_image("/home/forhadmethun/CLionProjects/Code/Others/Graphics/image1.bmp");;
    image2.save_image("/home/forhadmethun/CLionProjects/Code/Others/Graphics/image2.bmp");;
    image3.save_image("/home/forhadmethun/CLionProjects/Code/Others/Graphics/image3.bmp");;

    return 0;
}