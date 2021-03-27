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
        cout << random_range(35,80) << endl;
    }
}
void height()
{
    //
    freopen("gender.txt","r",stdin);
    freopen("height.txt", "w", stdout);
    char gender;
    double u1,u2;
    int x12,x13;
    float a;
    float b;
    a=0;b=1;
    int mean;//age mean=50,dev=10
    int dev;//height inch te deoa
    double v1,v2,w,x1,x2,y;
    int coun =1000;
    while(coun>0)
    {
        cin>>gender;
        if(gender=='M')
        {
            mean=70;
            dev=4;
        }
        else
        {
            mean=65;
            dev=3.5;
        }
        u1=RandomFloat(a,b);
        u2=RandomFloat(a,b);
        v1=2*u1-1;
        v2=2*u2-1;
        w=v1*v1+v2*v2;
        if(w<=1)
        {
          //  cout<<u1<<" "<<u2<<endl;
             // cout<<coun<<endl;;
            y=sqrt((-2*log(w))/w);
            x1=v1*y;
            x12=mean+dev*x1;
            cout<<x12<<endl;
            //printf("%d-%d-%d\n",2017-x12,random_range(1,12),random_range(1,28));
            x2=v2*y;
                x13=mean+dev*x2;
              //   printf("%d-%d-%d\n",2017-x13,random_range(1,12),random_range(1,28));
            cout<<x13<<endl;
            coun--;
        }


    }

}
void height_to_wieght(){
    //freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height.txt", "r", stdin);
    //freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\gender.txt", "r", stdin);

    freopen("weight24aug.txt", "w", stdout);

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
      f=f*2.54;
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
void dateGeneration(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\ThesisPrograms_by_me\\last_25_aug - (now... )\\patient_data_generation.txt","w",stdout);
    for(int i=1;i<=30;i++){
        for(int j=1;j<=6;j++){
            if( j== 1){
                for(int k=1;k<=31;k++){
                    //printf("%d\n",i);
                    printf("2017-01-%02d\n",k);
                }
            }
//            /*
            else if( j == 2 ){



                for(int k=1;k<=28;k++){
                    //printf("%d\n",i);
                    printf("2017-02-%02d\n",k);
                }

            }
            else if(j == 3){
                {


                    for(int k=1;k<=31;k++)
                    {
                        //printf("%d\n",i);
                        printf("2017-03-%02d\n",k);
                    }
                }

            }
            else if( j == 4){
                for(int k=1;k<=30;k++){
                    //printf("%d\n",i);
                    printf("2017-04-%02d\n",k);
                }

            }
            else if( j==5 ){
                for(int k=1;k<=31;k++){
                    printf("2017-05-%02d\n",k);
                    //printf("%d\n",i);
                }

            }
            else {
                for(int k=1;k<=30;k++){
                    //printf("%d\n",i);//
                    printf("2017-06-%02d\n",k);
                }
            }
//            */
        }
    }
}
void idGeneration(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\ThesisPrograms_by_me\\last_25_aug - (now... )\\patient_id_generation.txt","w",stdout);
    for(int i=1;i<=30;i++){
        for(int j=1;j<=6;j++){
            if( j== 1){
                for(int k=1;k<=31;k++){
                    printf("%d\n",i);
//                    printf("2017-01-%02d\n",k);
                }
            }
//            /*
            else if( j == 2 ){


                for(int k=1;k<=28;k++){
                    printf("%d\n",i);
//                    printf("2017-02-%02d\n",k);
                }

            }
            else if(j == 3){
                {


                    for(int k=1;k<=31;k++)
                    {
                        printf("%d\n",i);
//                        printf("2017-03-%02d\n",k);
                    }
                }

            }
            else if( j == 4){
                for(int k=1;k<=30;k++){
                    printf("%d\n",i);
//                    printf("2017-04-%02d\n",k);
                }

            }
            else if( j==5 ){
                for(int k=1;k<=31;k++){
//                    printf("2017-05-%02d\n",k);
                    printf("%d\n",i);
                }

            }
            else {
                for(int k=1;k<=30;k++){
                    printf("%d\n",i);//
//                    printf("2017-06-%02d\n",k);
                }
            }
//            */
        }
    }
}

void weight_time_base()
{
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\weight24aug.txt","r",stdin);
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\weight_time_based_27_aug.txt", "w", stdout);
    char gender;
    for(int i=1;i<=30;i++)
    {


    double u1,u2;
    float x12,x13;
    float a;
    float b;
    a=0;b=1;
    float mean;
    cin>>mean;//age mean=50,dev=10
    float dev=0.2;//height inch te deoa
    double v1,v2,w,x1,x2,y;
    int coun =181;
    while(coun>0)
    {
        //cin>>gender;

        u1=RandomFloat(a,b);
        u2=RandomFloat(a,b);
        v1=2*u1-1;
        v2=2*u2-1;
        w=v1*v1+v2*v2;
        if(w<=1)
        {
          //  cout<<u1<<" "<<u2<<endl;
             // cout<<coun<<endl;;
            y=sqrt((-2*log(w))/w);
            x1=v1*y;
            x12=mean+dev*x1;
            cout<<x12<<endl;
            //printf("%d-%d-%d\n",2017-x12,random_range(1,12),random_range(1,28));
            x2=v2*y;
                x13=mean+dev*x2;
              //   printf("%d-%d-%d\n",2017-x13,random_range(1,12),random_range(1,28));
            //cout<<x13<<endl;
            coun--;
        }
        mean = x12;


    }
    }

}

void BMI()
{
   // freopen("C:\\Users\\Acer\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height_weight.txt", "r", stdin);
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\bmi27aug.txt", "w", stdout);
     FILE *fp3,*fp4;
   double w;
   double h;


   fp3 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\height.txt","r");

   fp4 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\weight_time_based_27_aug.txt","r");
   int i=1;
   for(i=1;i<=30;i++)
   {
      fscanf(fp3,"%lf",&h);
       h=(h*2.54)/100 ;
       for(int j=1;j<=181;j++)
       {
                 fscanf(fp4,"%lf",&w);
                       cout<<w/(h*h)<<endl;


       }


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
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\workingtype25aug.txt","r",stdin);
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\exerciestime27aug.txt","w",stdout);
    for(int i=1;i<=30;i++){
             cin>>s;

//            for(int j=1;j<=5;j++){
            int time;
            if(s=="city_office")//weekly time base generation then divide it by 7 for average generation
            {
                        time = random_range(20,300);// << endl;

                        //40 minutes

            }
            else if(s=="city_field")
            {
                      time =  random_range(8,20);// << endl;
                        //10 minutes
            }
            else if(s=="village_at_work")
            {
                        time =  random_range(8,20) ;//<< endl;
                        //10 minutes

            }
            else if(s=="village_no_work")
            {
                        time = random_range(20,300);// << endl;
                        //40 minutes
            }


//            for(int k=1; j == 5 ? k <= 3 : k <= 7;k++){
//                printf("%d\n", time/7);
//            }
//            }
            for(int k = 1;k<=181;k++){
                cout << time/7 << endl;
            }

    }
}
/// http://www.globalrph.com/resting_metabolic_rate.htm
void caloryneed()
{
   freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\calorieneed_28_aug.txt", "w", stdout);

    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    char c;
    //string d;
    char d[100];
    double h,w,cal,fac,a;
    int e;
    fp1 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\weight_time_based_27_aug.txt","r");
    fp2 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\height_27_aug_time_based.txt","r");
    fp3 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\age_27_aug.txt","r");
    fp4 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\gender_27_aug_time_based.txt","r");
    fp5=fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\exercise28aug.txt","r"); //// generate...exercise.... here....

    fp6=fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\workingtype_27_aug_time_based.txt","r");
   // ifstream myfile ("workingtype.txt");
     int count=0;
    //cout << "test" << endl;
    while(
      count < 5430
          )
    { /*if( feof(fp1) &&feof(fp4) &&feof(fp2)&&feof(fp3)&&feof(fp5))
      {
        //cout << "breaking" <<endl;
         break ;
      }*/
      //cout << "test" << endl;
      //fscanf(fp1,"%lf",&w);
      //fscanf(fp2,"%lf",&h);
      //fscanf(fp3,"%d",&a);
      //fscanf(fp5,"%d",&e);
           fscanf(fp1,"%lf",&w);
      fscanf(fp2,"%lf",&h);
      fscanf(fp3,"%lf",&a);
      fscanf(fp5,"%d",&e);
      //e=e/7;


      c = fgetc(fp4);
      fgetc(fp4) ;
        fscanf(fp6,"%s",&d);
        string dd(d);

//       cout << "w: " << w << " h: " << h << " a: " << a << " ex: " << e << " gen: " << c << endl;
      //getline(cin,d);
      if(dd=="city_field"||dd=="village_at_work")
      {
          fac=1.7;
         // cout<<"hello"<<endl;

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
      }

      if(c=='M')
      {

          cal=(10*w+ 6.25* h - 5*a + 5)*fac;
         // cout<<"Male"<<endl;
          cout<<cal<<endl;

      }
      else{
           // cout << "female" << endl;
            cal=(10*w+ 6.25* h - 5*a -161)*fac;
            cout<<cal<<endl;

      }
      count++;



    }
    //cout << "--->> " << count << endl;
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}

void blood_pressure_time_base()
{
    freopen("blood_pressure_27_aug.txt","w",stdout);
     //
   // freopen("gender.txt","r",stdin);
    //freopen("height.txt", "w", stdout);
    //char gender;
    double u1,u2;
    int x12,x13;
    float a;
    float b;
    a=0;b=1;
    int mean;//age mean=50,dev=10
    int dev;//height inch te deoa
    double v1,v2,w,x1,x2,y;
    int coun =930;
    while(coun>0)
    {
        //cin>>gender;
        //if(gender=='M')
        //{
            mean=125;
            dev=15;
        //}

        u1=RandomFloat(a,b);
        u2=RandomFloat(a,b);
        v1=2*u1-1;
        v2=2*u2-1;
        w=v1*v1+v2*v2;
        if(w<=1)
        {
          //  cout<<u1<<" "<<u2<<endl;
             // cout<<coun<<endl;;
            y=sqrt((-2*log(w))/w);
            x1=v1*y;
            x12=mean+dev*x1;
            cout<<x12<<endl;
            //printf("%d-%d-%d\n",2017-x12,random_range(1,12),random_range(1,28));
            x2=v2*y;
                x13=mean+dev*x2;
              //   printf("%d-%d-%d\n",2017-x13,random_range(1,12),random_range(1,28));
            //cout<<x13<<endl;
            coun--;
        }


    }





}

//food grain sugar /starch = 19
//fat oily = 6
//protein = 7
//fruit = 28
    // 21 -> 2
    //22- 28 -> 1
//mmilk = 4
// pulse other = 6
// vegetable
    //21 - >> 2
    // 22 - 33 => 1


void breakfast_generation(){
    //starch

    //protein
    //pulse

    //veg 1
   // freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_29_aug.txt","w",stdout);
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    char  c;
    double f;


    fp1 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_starch_29_aug.txt","w");

    fp2 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_protein_29_aug.txt","w");

    fp3 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_pulse_29_aug.txt","w");

    fp4 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_veg_29_aug.txt","w");
    fp5 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_pk_29_aug.txt","w");

    int count = 1;
    for(int i=1;i<=19;i++){
      //  for(int j=1; j<=7;j++){
            for(int k=1;k<=6;k++){
                for(int l=22;l<=33;l++){
                    //cout << i  << " "<<0 << " " << k << " " << l << endl;
                    fprintf(fp1,"%d\n",i);
                    fprintf(fp2,"%d\n",0);
                    fprintf(fp3,"%d\n",k);
                    fprintf(fp4,"%d\n",l);
                    fprintf(fp5,"%d\n",count++);


                }
            }
      //  }
    }
    for(int i=1;i<=19;i++){
       for(int j=1; j<=7;j++){
           // for(int k=1;k<=6;k++){
                for(int l=22;l<=33;l++){
                   // cout << i  << " " << j << " " << 0 << " " << l << endl;
                    fprintf(fp1,"%d\n",i);
                    fprintf(fp2,"%d\n",j);
                    fprintf(fp3,"%d\n",0);
                    fprintf(fp4,"%d\n",l);
                    fprintf(fp5,"%d\n",count++);

                }
            }
      //  }
    }

}

void dinner_generation() {
    //starch 19
    //protein 7
    //pulse 6
    //veg 2 - 21
    //veg 1 - 22-33

    // freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_29_aug.txt","w",stdout);
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    char c;
    double f;


    fp1 = fopen(
            "D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_starch_29_aug.txt",
            "w");

    fp2 = fopen(
            "D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_protein_29_aug.txt",
            "w");

    fp3 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_pulse_29_aug.txt",
                "w");

//    fp4 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_veg_29_aug.txt","w");
    fp5 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_pk_29_aug.txt",
                "w");

    int count = 1;
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 7; j++) {
            for (int k = 1; k <= 6; k++) {
//                for(int l=22;l<=33;l++){
                //cout << i  << " "<<0 << " " << k << " " << l << endl;
                fprintf(fp1, "%d\n", i);
                fprintf(fp2, "%d\n", j);
                fprintf(fp3, "%d\n", k);
//                    fprintf(fp4,"%d\n",l);
                fprintf(fp5, "%d\n", count++);


//                }
            }
            //  }
        }

    }
}

void lunch_generation(){


   // freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_29_aug.txt","w",stdout);

    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    char  c;
    double f;
    fp1 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_starch_29_aug.txt","w");
    fp2 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_protein_29_aug.txt","w");
    fp3 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_pulse_29_aug.txt","w");
    fp4 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_veg_1_29_aug.txt","w");
    fp5 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_veg_2_29_aug.txt","w");
    fp5 = fopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_pk_29_aug.txt","w");

    int count = 1;
    for(int starch=1;starch<=19;starch++) {
        for (int protein = 1; protein <= 7; protein++) {
            for (int pulse = 1; pulse <= 6; pulse++) {
                for (int veg1 = 1; veg1 <= 21; veg1++) {
//                    for (int veg2 = 22; veg2 <= 33; veg2++) {
                        //cout << i  << " "<<0 << " " << k << " " << l << endl;
                        fprintf(fp1, "%d\n", starch);
                        fprintf(fp2, "%d\n", protein);
                        fprintf(fp3, "%d\n", pulse);

                        fprintf(fp4, "%d\n", veg1);
//                        fprintf(fp5, "%d\n", veg2);

                        fprintf(fp5, "%d\n", count++);


//                    }
                }
            }
        }
    }

}

void meal_planning_id_from_calorie_need(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\calorie_need_time_based_29_aug.txt","r",stdin);
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\meal_planning_id_from_calorie_need_29_aug.txt","w",stdout);
    float f;
    for(int i=1;i<=5430;i++){
        cin >> f;
        if(f <= 1000){
            cout << 1 << endl;
        }
        else if( f <= 1200){
            cout << 2 << endl;
        }
        else if( f <= 1400){
            cout << 3 << endl;
        }
        else if( f <= 1600 ){
            cout << 4 << endl;
        }
        else if( f <= 1800){
            cout << 5 << endl;
        }
        else if( f <= 2000){
            cout << 6 << endl;

        }else if(f <= 2200){
            cout << 7 << endl;
        }
        else if(f <= 2400){
            cout << 8 << endl;
        }
        else if( f <= 2600 )cout << 9 << endl;
        else if( f <= 2800) cout << 10 << endl;
    }

}

void breakfast_meal_id_generation_time_based(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\breakfast_meal_id_generation_time_based.txt","w",stdout);


    for(int i=1;i<=5430;i++){
        cout << random_range(1,2964) << endl;
    }
}
void lunch_meal_id_generation_time_based(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\lunch_meal_id_generation_time_based.txt","w",stdout);
    for(int i=1;i<=5430;i++){
        cout << random_range(1,16758) << endl;
    }
}
void dinner_meal_id_generation_time_based(){
    freopen("D:\\googleDrive\\_CSE\\Code\\Others\\Thesis\\_thesis_by_azad\\ThesisPrograms\\dinner_meal_id_generation_time_based.txt","w",stdout);
    for(int i=1;i<=5430;i++){
        cout << random_range(1,798) << endl;
    }
}


int main() {
//    srand(time(NULL));
//    breakfast_meal_id_generation_time_based();
//    lunch_meal_id_generation_time_based();
//    dinner_meal_id_generation_time_based();
    printf("hello forhad!");

//    meal_planning_id_from_calorie_need();
//    lunch_generation();
//    dinner_generation();
//    breakfast_generation();
    //blood_pressure_time_base();
    //freopen("weight.txt","r",stdin);
    //freopen("carbohydrate.txt","r",stdin);
    //height();
    //age() ;
    //random_Gender() ;
   // height_to_wieght();
    //BMI();
    //weight_time_base();
    //workingtype();


    // re analysis the exercise portion....
     // exercise();

//        caloryneed();
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
