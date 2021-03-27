///for every patient 6 month's data generation

#include<stdio.h>
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
int main(){
    idGeneration();
    return 0;
}
