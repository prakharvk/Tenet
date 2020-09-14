#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a11,a21,a22,b1,b2,n1,n2,hs,hl,e1;
    cin>>a11>>a21>>a22>>b1>>b2>>n1>>n2>>hs>>hl>>e1;
    double t = 0;
    double v1 = 0;
    double v2 = 0;
    auto h = hs;
    auto n = n1+n2;
    for(int i=1;i<=n;++i)
    {
        if(i>n1) h = hl;
        
        // evaluate runge-kutta terms- 4 for each equation
        auto u11 = h*((a11*v1) + e1);
        auto u12 = h*((a21*v1) + (a22*v2) + b2);
        auto u21 = h*(a11*(v1+(0.5*u11))+b1);
        auto u22 = h*(a21*(v1+(0.5*u11)) + a22*(v2+(0.5*u12)) + b2);
        auto u31 = h*(a11*(v1+(0.5)*u21) + b1);
        auto u32 = h*(a21*(v1+(0.5)*u21) + a22*(v2+(0.5)*u22)+b2);
        auto u41 = h*(a11*(v1+u31)+b1);
        auto u42 = h*(a21*(v1+u31) + a22*(v2+u32) + b2);

        // evaluate voltages
        v1 += (u11+2*u21+2*u31+u41)/6;
        v2 += (u12+2*u22+2*u32+u42)/6;
        t = t+h;
        cout<<i<<"\t\t"<<t<<"\t\t"<<v1<<"\t\t"<<v2<<endl;    
    
    }
}