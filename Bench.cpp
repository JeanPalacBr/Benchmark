/* 
 * File:   main.cpp
 * Author: JPBX
 *
 * Created on 6 de marzo de 2020, 02:09 PM
 */

#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <math.h>
#include <string.h>

using namespace std;

  void primos(int inicial, int final){
    int divcon = 0;
    for(int i = inicial; i<= final; i++){
        for(int j = 1; j<=(i/2);j++){
            if((i%j)==0){
                divcon++;
            }
        }
        if(divcon==0){
         cout<<i<<" Es primo"<<endl;
        }
        divcon=0;
    };
    
}
 void digpi(){
     double a = 1;
     double b = 1/sqrt(2);
     double t = 0.25;
     double p = 1;
     double x = 0;
     double y = 0;
     
     long double pii = 0;
     int dig=100;
     for(int i = 0; i<=dig;i++){
         pii = (pow((a+b),2))/(4*t);
         x = (a+b)/2;
         y = sqrt(a*b);
         t = t - p*(pow((a-x),2));
         a = x;
         b = y;
         p = 2*p;
         cout<<pii<<endl;
     }
     cout<<pii<<endl;
 };
 void digiipii(){
     int dig=10;
     double pii = 0;
     double digit = 0;
     string pi,pifinal = "";
     
     double a,b,c,d,e = 0;
     
     //int[] array = new int[250000];
     for(double k = 0; k<=dig;k++){
         a= (1/(pow(16,k)));
         b=(4/((8*k)+1));
         c= (2/((8*k)+4));
         d=(1/((8*k)+5));
         e=(1/((8*k)+6));
         
         digit = (a)*((b)-(c)-(d)-(e));
         pii = pii + digit;
         pi = to_string(pii).substr(k,1);
         if(k<=1){
         pii = pii - atof(to_string(pii).substr(k,1).c_str());
         }else{
         //pi = to_string(pii).substr(k,1);  
         pii = pii - atof(to_string(pii).substr(0,k).c_str());
         }
         
         pifinal = pifinal.append(pi);
         
     }
 };
 
int main(){
    void ();
    int op = 0;
    cout << "Ingrese el numero de la operación deseada "<<endl;
    cout << "1. Analizar CPU"<<endl;
    cout << "2. Analizar HDD"<<endl;
    cout<< "3. Analizar RAM"<<endl;
    cout<< "4. Analizar TODO lo anterior"<<endl;
    op=1;
            switch(op){
                case 1:
                    digiipii();
                      digpi();           
                   primos(1,50);
                   break;
                case 2:
                    break;
                case 3: 
                    break;
            }
    return 0;
    system("pause");
}



