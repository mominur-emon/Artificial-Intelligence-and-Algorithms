#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std ;

vector<string>avalue ;
vector<string>cvalue ;

int numberofobject = 0 ;

int findOccurance(string att, string cl)
{
    FILE *fptr;
    char a[100], c[100] ;
    int count = 0 ;
    if ((fptr = fopen("data.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF){
        string s = "" ;
        string s2 = "" ;

        for(int i = 0 ; i < strlen(a) ; i++){
            s += a[i] ;
         }
         for(int i = 0 ; i < strlen(c) ; i++){
            s2 += c[i] ;
         }
         if(s == att && s2 == cl) count++ ;
    }
    fclose(fptr);
    return count ;
}


int findOccurance2(string cl)
{
    FILE *fptr;
    char a[100], c[100] ;
    int count = 0 ;
    if ((fptr = fopen("data.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF){
        string s = "" ;
        string s2 = "" ;
         for(int i = 0 ; i < strlen(c) ; i++){
            s2 += c[i] ;
         }
         if(s2 == cl) count++ ;
    }
    fclose(fptr);
    return count ;
}
int main() {
    char a[100], c[100];
    FILE *fptr;
    if ((fptr = fopen("data.txt", "r")) == NULL) { /*file is read here*/
        printf("Error! opening file");
        exit(1);
    }
    string s = "" ;
    while (fscanf(fptr, "%s %s", a, c)!= EOF){
         printf("%s %s", a, c);
         printf("\n") ;
         numberofobject++ ;

         bool flag = false ;
         string s = "" ;
         for(int i = 0 ; i < strlen(a) ; i++){
            s += a[i] ;
            /*char array is converted into string*/
         }
         for(int i = 0 ; i < avalue.size() ; i++){
            if(s == avalue[i]) {
                flag = true ;
                /*only hold the identical value of the attribute*/

            }
         }
         if(!flag)
            avalue.push_back(s) ;


         flag = false ;
         s = "" ;
         for(int i = 0 ; i < strlen(c) ; i++){
            s += c[i] ;
         }
         for(int i = 0 ; i < cvalue.size() ; i++){
            if(s == cvalue[i]) {
                flag = true ;

            }
         }
         if(!flag)
            cvalue.push_back(s) ;



    }
    printf("%d\n", numberofobject) ;
    for(int i = 0 ; i < avalue.size() ; i++){

        cout<< avalue[i] << endl ;
    }

    for(int i = 0 ; i < cvalue.size() ; i++){

        cout<< cvalue[i] << endl ;
    }

    for(int i = 0 ; i < cvalue.size() ; i++){
        for(int j = 0 ; j < avalue.size() ; j++){
            int n = findOccurance(avalue[j], cvalue[i]) ;
            int m = findOccurance2(cvalue[i]) ;
            cout << cvalue[i] << (1.00*m) / numberofobject << endl ;
            /*Write the Prior knowledge into prior.txt*/
            double prob = (1.00*n) / m ;
            cout << avalue[j] << "|" << cvalue[i] << " = "<< prob << endl ;
            /*write the likelihood knowledge in likelihood.txt*/

        }
    }

    fclose(fptr);

    return 0;
}

