#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<double> a(52), b(52), c(52);
    double k1,k2;
    a[0] = 100;
    b[0] = 50;
    c[0] = 0;
    float delta = 0.1; // delta t
    double t = 0;
    k1 = 0.008;
    k2 = 0.002;
    for(int i=0;i<51;++i)
    {
        cout<<t<<"\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<c[i]<<endl;
        a[i+1] = a[i] + (k2*c[i] - k1*a[i]*b[i])*delta;
        b[i+1] = b[i] + (k2*c[i] - k1*a[i]*b[i])*delta;
        c[i+1] = c[i] + 2*(k1*a[i]*b[i] - k2*c[i])*delta;
        t = t+delta;
    }
    
}