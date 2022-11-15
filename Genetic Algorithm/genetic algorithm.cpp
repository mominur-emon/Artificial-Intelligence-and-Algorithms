#include<bits/stdc++.h>

using namespace std;

struct chromosome
{
    int a, b;
    double fitness ;
    vector<int>prob ;
} temp, dvalue[6], par[6];
int binary[6][8];

int f(int a, int b){
    return 2*a*a + 3*b - 38 ;
}
void calculateFitness()
{
    for(int i = 0 ; i < 6 ; i++){
        int fVal = abs(f(dvalue[i].a, dvalue[i].b)) ;
        dvalue[i].fitness = 1.00/fVal ;

    }
}
void copyToPar(int x, int y){
    par[y].a = dvalue[x].a ;
    par[y].b = dvalue[y].b ;

}
void chooseParent(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(dvalue[i].fitness < dvalue[j].fitness){
                temp = dvalue[i] ;
                dvalue[i] = dvalue[j] ;
                dvalue[j] = temp ;
            }
        }
    }


    int cur = 0 ;
    for(int i = 0 ; i < 6 ; i++){
        int randVal = rand() % 9 ;
        if(randVal == 0 || randVal == 6 || randVal == 7){
         copyToPar(0, i) ;
        }
        else if(randVal == 1 || randVal == 8)
            copyToPar(1, i) ;
        else if(randVal == 2)
            copyToPar(2, i) ;
        else if(randVal == 3)
            copyToPar(3, i) ;
        else if(randVal == 4)
            copyToPar(4, i) ;
        else if(randVal == 5)
            copyToPar(5, i) ;
    }
}


void decimal_to_binary(){
    int iteration, index, binary[6][8];
    for (iteration < 0 ; iteration< 6; iteration++){
        for(index = 3 ; index>= 0; index--){
            if(par[iteration].a != 0){
                binary[iteration][index] = par[iteration].a % 2;
                par[iteration].a = par[iteration].a/2;
            }
            else{
                binary[iteration][index] = 0;
            }
        }
    }
    for (iteration < 0 ; iteration< 6; iteration++){
        for(index = 3 ; index>= 0; index--){
            if(par[iteration].b != 0){
                binary[iteration][index] = par[iteration].b % 2;
                par[iteration].b = par[iteration].b/2;
            }
            else{
                binary[iteration][index] = 0;
            }
        }
    }
}
void crossOver(){
    int temp, iteration, index,flag, binary[6][6];

    for (iteration = 0; iteration< 6; iteration++){
        flag = rand() % 7;
        decimal_to_binary();
        for(index = 7; index > flag ; index--){
            temp = binary[iteration][index];
            binary[iteration][index] = binary[iteration + 1][index];
            binary[iteration + 1][index] = temp;
         }
         iteration++;
    }
}

int mutation(){
     int flag, binary[6][6];
     for (int iteration = 0; iteration<6 ;iteration++){
        for(int k = 0; k<(rand()%8); k++){
            flag = rand()% 7;
            if(binary[iteration][flag] != 0){
                binary[iteration][flag] = 0;
            }
            else{
                binary[iteration][flag] = 1;
            }
        }
     }

}

int main(){
    int i, j ;
    for(i = 0 ; i < 6 ; i++){
    int x = rand() % 10 ;
    int y = rand() % 10 ;
    dvalue[i].a = x ;
    dvalue[i].b = y ;
    dvalue[i].fitness = 0 ;
   }

   for(i = 0 ; i < 400 ; i++){
    printf("Iteration: %d\n", i) ;
    for(j = 0 ; j < 6 ; j++){
        if(f(dvalue[j].a , dvalue[j].b) == 0){
            printf("Solution %d %d\n", dvalue[j].a, dvalue[j].b) ;
            return 0;
        }
    calculateFitness() ;
    chooseParent() ;
    crossOver() ;
    mutation() ;
    }
   }


}

