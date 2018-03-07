#include <iostream>
#include "math.h"
#define Maks 1000
#include <stdio.h>
using namespace std;
float a,b,n;
int i,j;
double h,x[Maks],y[Maks];

void input() {
    cout<<"\nMasukkan batas bawah : ";
    cin>>a;
    cout<<"\nMasukkan batas atas : ";
    cin>>b;
    cout<<"\nMasukkan jumlah pembagi 'N' : ";
    cin>>n;
    h = (b-a)/n;
}
double f(double x) {
    return exp(-x)-x;
}
void table() {
    cout<<"x\tf(x)\n";
    for(i=0; i<n; i++) {
        x[i] = a+(i+1)*h;
        y[i] = f(x[i]);
        printf("%.3f\t%f\n",x[i],y[i]);
    }
    cout<<"\n";
}
void akar() {
    for(j=0; j<n; j++) {
        if(y[j]*y[j+1]<0) {
            cout<<"Akar diantara "<<y[i]<<" dan "<<y[i+1]<<"\n";
            break;
        }
        if(fabs(y[j])<fabs(y[j+1])) {
            cout<<"Akar yang lebih dekat = "<<x[j]<<"\n";
            cout<<"Error = "<<fabs(y[j])<<"\n";
        } else {
            cout<<"Akar yang lebih dekat = "<<x[j+1]<<"\n";
            cout<<"Error = "<<fabs(y[j+1])<<"\n";
        }
    }

}
int main() {
    char answer;
    do{
        input();
        table();
        akar();
        fflush(stdin);
        cout<<"\nMenghitung lagi ?";
        cin>>answer;
    }while(answer == 'Y'||answer == 'y');
}
