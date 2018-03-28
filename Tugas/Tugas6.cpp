
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int iterasi,i=1;
    double ra,rb,pembagi,fxa,fxb,fx,fdx,error,x0,x[20],y[20];
    cout<<"\t   Metode Newton Raphson Dengan Modifikasi Tabel\n";
    cout<<"f(x)=x*e^-x+cos(2*x)\nf'(x)=(1-x)*e^-x-2*sin(2*x)\n";
    cout<<"Cari akar menggunakan metode newton raphson dengan modifikasi tabel\n";
    cout<<"Batas bawah\nbawah : ";
    cin>>rb;
    fxb=rb*pow(1/2.718,rb)+cos((2*rb)*3.1415/180.0);
    cout<<"Batas Atas\natas : ";
    cin>>ra;
    fxa=ra*pow(1/2.718,ra)+cos((2*ra)*3.1415/180.0);
    cout<<"Masukkan toleransi galat : ";
    cin>>error;
    cout<<"Masukkan iterasi maksimal : ";
    cin>>iterasi;
    pembagi = (ra-rb)/iterasi;
    for(i=0; i<=iterasi; i++)
    {
        x[i]=rb+i*pembagi;
        y[i]=x[i]*pow(1/2.718,x[i])+cos(2*x[i]);
    }
    for(i=0; i<=iterasi; i++)
    {
        if(y[i]==0)
        {
            x0=x[i];
            cout<<"Titik pendekatan awal x0 = "<<x0<<"\n";
        }
        if(y[i]*y[i+1]<0)
        {
            if(abs(y[i])<abs(y[i+1]))
            {
                x0=x[i];
                cout<<"Titik pendekatan awal x0 = "<<x0<<"\n";
            }
            else
            {
                x0=x[i+1];
                cout<<"Titik pendekatan awal x0 = "<<x0<<"\n";
            }
        }
    }
    cout<<"Diperoleh x0 dari metode tabel : "<<x0<<"\n";
    fx = x0*pow(1/2.718,x0)+cos(2*x0);
    fdx = (1-x0)*pow(1/2.718,x0)-2*sin(2*x0);
    cout<<"Iterasi\tx\t\t\t\tf(x)\t\t\t\tf'(x)\n";
    cout<<"-------------------------------------"
        <<"----------------------------------------\n";
    for(i=1; i<=iterasi,abs(fx)>=error; i++)
    {
        cout<<i<<"\t"<<x0<<"\t\t\t"<<fx<<"\t\t\t"<<fdx<<"\n";
        x0=x0-(fx/fdx);
        fx=x0*pow(1/2.718,x0)+cos(2*x0);
        fdx=(1-x0)*pow(1/2.718,x0)-2*sin(2*x0);
    }
    cout<<i<<"\t"<<x0<<"\t\t\t"<<fx<<"\t\t\t"<<fdx<<endl;
    return 0;
}
