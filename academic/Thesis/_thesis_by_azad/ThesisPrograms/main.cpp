#include <bits/stdc++.h>

using namespace std;

int random_range(int from, int to) {
    return from + (rand() % (to - from + 1));

}

double random_range(double from, double to) {
    return from + (double) (rand() % (int) (to - from + 1));

}

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
//float lb(float val){
  //  return 0.453592*val;
//}
//float fm(float val){
  //  return  (float).3048*val;
//}


void random_Gender(){
   // freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height_weight.txt", "r", stdin);
    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\gender.txt", "w", stdout);

    for(int i=0;i<1000;i++){
        int x = rand()%20;
        if(x%2 == 0){
            cout << 'F' << endl;
        }
        else{
            cout << "M" << endl;
        }
    }
}

void age()
{
    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\age.txt", "w", stdout);

    for(int i=0;i<1000;i++){
        cout << random_range(35,55) << endl;
    }
}
void meal_plan_generate()
{
    int i,j,k;
    freopen("meal_plan.txt","w",stdout);
    int count=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<5;k++)
            {
                //cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                count++;
            }
        }
    }
    cout<<count;
}
void height()
{
    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height.txt", "w", stdout);

    for(int i=0;i<1000;i++){
        cout << random_range(137,215) << endl;
    }
}
void height_to_wieght(){
    //freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height.txt", "r", stdin);
    //freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\gender.txt", "r", stdin);

    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\weight.txt", "w", stdout);

    FILE *fp1,*fp2;
   char  c;
   double f;


   fp1 = fopen("gender.txt","r");

   fp2 = fopen("height.txt","r");
  // printf("hello") ;

   while(1)
   {
      c = fgetc(fp1);
      fscanf(fp2,"%lf",&f);
      if( feof(fp1) &&feof(fp2) )
      {
         break ;
      }
    //  cout<<c ; ;
      if(c=='M')
        {
            if (f >= 137 && f < 140){
                printf("%0.2lf\n", RandomFloat( 28.5,34.9)) ;
            }
            if (f >= 140 && f < 142){
                printf("%0.2lf\n", RandomFloat( 30.8,38.1)) ;
            }
            if (f >= 142 && f < 145){
                printf("%0.2lf\n", RandomFloat( 33.5,40.8)) ;
            }
            if (f >= 145 && f < 147){
                printf("%0.2lf\n", RandomFloat( 35.8,43.9)) ;
            }
            if (f >= 147 && f < 150){
                printf("%0.2lf\n", RandomFloat( 38.5,46.7)) ;
            }
            if (f >= 150 && f < 152){
                printf("%0.2lf\n", RandomFloat( 40.8,49.9)) ;
            }
            if (f >= 152 && f < 155){
                printf("%0.2lf\n", RandomFloat( 43.1,53)) ;
            }
            if (f >= 155 && f < 157){
                printf("%0.2lf\n", RandomFloat( 45.8,55.8)) ;
            }
            if (f >= 157 && f < 160){
                printf("%0.2lf\n", RandomFloat( 48.1,58.9)) ;
            }
            if (f >= 160 && f < 163){
                printf("%0.2lf\n", RandomFloat( 50.8,61.6)) ;
            }
            if (f >= 163 && f < 165){
                printf("%0.2lf\n", RandomFloat( 53,64.8)) ;
            }
            if (f >= 165 && f < 168){
                printf("%0.2lf\n", RandomFloat( 55.3,68)) ;
            }
            if (f >= 168 && f < 170){
                printf("%0.2lf\n", RandomFloat( 58,70.7)) ;
            }
            if (f >= 170 && f < 173){
                printf("%0.2lf\n", RandomFloat( 60.3,73.9)) ;
            }
             if (f >= 173 && f < 175){
                printf("%0.2lf\n", RandomFloat( 63,76.6)) ;
            }
             if (f >= 175 && f < 178){
                printf("%0.2lf\n", RandomFloat( 65.3,79.8)) ;
            }
             if (f >= 178 && f < 180){
                printf("%0.2lf\n", RandomFloat( 67.6,83)) ;
            }
             if (f >= 180 && f < 183){
                printf("%0.2lf\n", RandomFloat( 70.3,85.7)) ;
            }
             if (f >= 183 && f < 185){
                printf("%0.2lf\n", RandomFloat( 72.6,88.9)) ;
            }
             if (f >= 185 && f < 188){
                printf("%0.2lf\n", RandomFloat( 75.3,91.6)) ;
            }
             if (f >= 188 && f < 191){
                printf("%0.2lf\n", RandomFloat( 77.5,94.8)) ;
            }
             if (f >= 191 && f < 193){
                printf("%0.2lf\n", RandomFloat( 79.8,98)) ;
            }
             if (f >= 193 && f < 195){
                printf("%0.2lf\n", RandomFloat( 82.5,100.6)) ;
            }
             if (f >= 195 && f < 198){
                printf("%0.2lf\n", RandomFloat( 84.8,103.8)) ;
            }
            if (f >= 198 && f < 201){
                printf("%0.2lf\n", RandomFloat( 87.5,106.5)) ;
            }
            if (f >= 201 && f < 203){
                printf("%0.2lf\n", RandomFloat( 89.8,109.7)) ;
            }
            if (f >= 203 && f < 205){
                printf("%0.2lf\n", RandomFloat( 92,112.9)) ;
            }
            if (f >= 205 && f < 208){
                printf("%0.2lf\n", RandomFloat( 94.8,115.6)) ;
            }
            if (f >= 208 && f < 210){
                printf("%0.2lf\n", RandomFloat( 97,118.8)) ;
            }
            if (f >= 210 && f < 213){
                printf("%0.2lf\n", RandomFloat( 99.8,121.5)) ;
            }
            if (f >= 213){
                printf("%0.2lf\n", RandomFloat( 102,124.7)) ;
            }
        }

        if(c=='F')
        {
            if (f >= 137 && f < 140){
                printf("%0.2lf\n", RandomFloat( 28.5,34.9)) ;
            }
            if (f >= 140 && f < 142){
                printf("%0.2lf\n", RandomFloat( 30.8,37.6)) ;
            }
            if (f >= 142 && f < 145){
                printf("%0.2lf\n", RandomFloat( 32.6,39.9)) ;
            }
            if (f >= 145 && f < 147){
                printf("%0.2lf\n", RandomFloat( 34.9,42.6)) ;
            }
            if (f >= 147 && f < 150){
                printf("%0.2lf\n", RandomFloat( 36.4,44.9)) ;
            }
            if (f >= 150 && f < 152){
                printf("%0.2lf\n", RandomFloat( 39,47.6)) ;
            }
            if (f >= 152 && f < 155){
                printf("%0.2lf\n", RandomFloat( 40.8,49.9)) ;
            }
            if (f >= 155 && f < 157){
                printf("%0.2lf\n", RandomFloat( 43.1,52.6)) ;
            }
            if (f >= 157 && f < 160){
                printf("%0.2lf\n", RandomFloat( 44.9,54.9)) ;
            }
            if (f >= 160 && f < 163){
                printf("%0.2lf\n", RandomFloat( 47.2,57.6)) ;
            }
            if (f >= 163 && f < 165){
                printf("%0.2lf\n", RandomFloat( 49,59.9)) ;
            }
            if (f >= 165 && f < 168){
                printf("%0.2lf\n", RandomFloat( 51.2,62.6)) ;
            }
            if (f >= 168 && f < 170){
                printf("%0.2lf\n", RandomFloat( 53,64.8)) ;
            }
            if (f >= 170 && f < 173){
                printf("%0.2lf\n", RandomFloat( 55.3,67.6)) ;
            }
             if (f >= 173 && f < 175){
                printf("%0.2lf\n", RandomFloat( 57.1,69.8)) ;
            }
             if (f >= 175 && f < 178){
                printf("%0.2lf\n", RandomFloat( 59.4,72.6)) ;
            }
             if (f >= 178 && f < 180){
                printf("%0.2lf\n", RandomFloat( 61.2,74.8)) ;
            }
             if (f >= 180 && f < 183){
                printf("%0.2lf\n", RandomFloat( 63.5,77.5)) ;
            }
             if (f >= 183 && f < 185){
                printf("%0.2lf\n", RandomFloat( 65.3,79.8)) ;
            }
             if (f >= 185 && f < 188){
                printf("%0.2lf\n", RandomFloat( 67.6,82.5)) ;
            }
             if (f >= 188 && f < 191){
                printf("%0.2lf\n", RandomFloat( 69.4,84.8)) ;
            }
             if (f >= 191 && f < 193){
                printf("%0.2lf\n", RandomFloat( 71.6,87.5)) ;
            }
             if (f >= 193 && f < 195){
                printf("%0.2lf\n", RandomFloat( 73.5,89.8)) ;
            }
             if (f >= 195 && f < 198){
                printf("%0.2lf\n", RandomFloat( 75.7,92.5)) ;
            }
            if (f >= 198 && f < 201){
                printf("%0.2lf\n", RandomFloat(77.5,94.8 )) ;
            }
            if (f >= 201 && f < 203){
                printf("%0.2lf\n", RandomFloat(79.8,97.5 )) ;
            }
            if (f >= 203 && f < 205){
                printf("%0.2lf\n", RandomFloat( 81.6,99.8)) ;
            }
            if (f >= 205 && f < 208){
                printf("%0.2lf\n", RandomFloat(83.9,102.5 )) ;
            }
            if (f >= 208 && f < 210){
                printf("%0.2lf\n", RandomFloat(85.7,104.8 )) ;
            }
            if (f >= 210 && f < 213){
                printf("%0.2lf\n", RandomFloat( 88,107.5)) ;
            }
            if (f >= 213){
                printf("%0.2lf\n", RandomFloat( 89.8,109.7)) ;
            }

   }




}
   fclose(fp1);
   fclose(fp2);
}
void BMI()
{
   // freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height_weight.txt", "r", stdin);
    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\bmi.txt", "w", stdout);
     FILE *fp3,*fp4;
   double w;
   double h;


   fp3 = fopen("height.txt","r");

   fp4 = fopen("weight.txt","r");
   while(1)
   {
      fscanf(fp3,"%lf",&h);
      fscanf(fp4,"%lf",&w);
      if( feof(fp3) &&feof(fp4) )
      {
         break ;
      }
      h=h/100 ;
      cout<<w/(h*h)<<endl;

   }

  fclose(fp3);
  fclose(fp4);
}

void workingtype()
{
    freopen("workingtype.txt","w",stdout);
    vector<string> vs;
    vs.push_back("city_office");
    vs.push_back("city_field");
    vs.push_back("village_at_work");
    vs.push_back("village_no_work");
    for(int i=0;i<1000;i++){
        cout << vs[rand()%4] << endl;
    }


}
void exercise()
{
    int extime;
    string s;
    freopen("workingtype.txt","r",stdin);
    freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\exercise.txt","w",stdout);
    for(int i=0;i<1000;i++){
            cin>>s;

            if(s=="city_office")
            {
                        cout << random_range(20,300) << endl;

            }
            else if(s=="city_field")
            {
                        cout << random_range(5,20) << endl;


            }
            else if(s=="village_at_work")
            {
                        cout << random_range(5,20) << endl;


            }
            else if(s=="village_no_work")
            {
                        cout << random_range(20,300) << endl;

            }

    }
}
void caloryneed()
{
   freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\caloryneed.txt", "w", stdout);

    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    char c;
    //string d;
    char d[100];
    double h,w,cal,fac;
    int a,e;
    fp1 = fopen("weight.txt","r");
    fp2 = fopen("height.txt","r");
    fp3 = fopen("age.txt","r");
    fp4 = fopen("gender.txt","r");
    fp5=fopen("exercise.txt","r");
    fp6=fopen("workingtype.txt","r");
   // ifstream myfile ("workingtype.txt");
     int count=0;
    //cout << "test" << endl;
    while(count<1000)
    { /*if( feof(fp1) &&feof(fp4) &&feof(fp2)&&feof(fp3)&&feof(fp5))
      {
        //cout << "breaking" <<endl;
         break ;
      }*/
      //cout << "test" << endl;
      fscanf(fp1,"%lf",&w);
      fscanf(fp2,"%lf",&h);
      fscanf(fp3,"%d",&a);
      fscanf(fp5,"%d",&e);
      c = fgetc(fp4);
        fscanf(fp6,"%s",&d);
        string dd(d);
      //getline(cin,d);
      if(dd=="city_field"||dd=="village_at_work")
      {
          fac=1.7;
      }
      else{
      if(e>=5&&e<20)
          {
              fac=1.2;
          }
       if(e>=20&&e<60)
          {
              fac=1.375;
          }
       if(e>=60&&e<240)
          {
              fac=1.55;
          }
        if(e>=240&&e<420)
          {
              fac=1.7;
          }
          if(e>420)
          {
              fac=1.9;
          }
      }

      if(c=='M')
      {

          cal=(10*w+ 6.25* h - 5*a + 5)*fac;
          cout<<cal<<endl;

      }
      else{
            cal=(10*w+ 6.25* h - 5*a -161)*fac;
            cout<<cal<<endl;

      }
      count++;



    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}
int main() {

    srand(time(NULL));

    //freopen("weight.txt","r",stdin);
    //freopen("carbohydrate.txt","r",stdin);

    //height();
    //age() ;
    //random_Gender() ;
    //height_to_wieght();
    //BMI();


    //workingtype();
      //exercise();
        //caloryneed();
        meal_plan_generate();





    //freeFood();
    //fruit();
    //milk();
    //non_starch();
    //meat();
    //sweet();



    //age();
   //BMI();
    //random_Gender();
    //starch_per_serving();




    return 0;
}
