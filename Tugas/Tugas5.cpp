#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int iterasi,i=1;
    double x0=1,fdx,fx=0,error;
    cout<<"\tMetode Newton Raphson\n";
    cout<<"f(x)m-e^-x+x\n"<<"f'(x)m-(-e)^-x+1\n";
    cout<<"Cari akar menggunakan metode newton raphson\n";
    while(fx==0){
        cout<<"Pendekatan awal:\nx0= ";
        cin>>x0;
        fx = -pow(1/2.718,x0)+x0;
        fdx = -(-pow(1/2.718,x0))+1;
        if(fx==0)
            cout<<"Masukkan lagi\n";
    }
    cout<<"Masukkan toleransi galat: ";
    cin>>error;
    cout<<"Masukkan iterasi maksimal : ";
    cin>>iterasi;
    cout<<"Iterasi\t    x\t\t\tf(x)\t\t\tf'(x)\n";
    cout<<"-------------------------------------"
    <<"--------------------------------------\n";
    for(i=1;i<=iterasi,abs(fx)>=error;i++){
        cout<<i<<"\t"<<x0<<"\t\t"<<fx<<"\t\t"<<fdx<<"\n";
        x0=x0-(fx/fdx);
        fx=-pow(1/2.718,x0)+x0;
        fdx=-(-pow(1/2.718,x0))+1;
    }
    cout<<"-------------------------------------"
    <<"--------------------------------------\n"
    <<"Akarnya = "<<x0<<"\n";
    return 0;
}
