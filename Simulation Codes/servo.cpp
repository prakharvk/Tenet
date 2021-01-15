#include <bits/stdc++.h>
using namespace std;
int main()
{
    // h is time step, n is no of steps. y1, y2 initial values
    double t = 0;
    double y1 = 1;
    double y2 = 0;
    double h = 0.001;
    int n = 5000;
    int k = 1;
    for(int i=1;i<=n;++i)
    {
        k = k-1;
        if(k == 0)
        {
            // print once in 100 steps
            cout<<t<<" "<<y1<<" "<<y2<<endl;
            k = 100;
        }
        // caclulate the runge-kutta terms
        double u11 = h*y2;
        double u12 = h*(0.1*(1-y1*y1)*y2 - y1);
        double u21 = h*(y2 + 0.5*u12);
        double u22 = h*(0.1*(1-(y1+0.5*u11)*(y1 + 0.5*u11))*(y2+0.5*u12) - (y1+0.5*u11));
        double u31 = h*(y2 + 0.5*u22);
        double u32 = h*(0.1*(1-(y1+0.5*u21)*(y1+0.5*u21))*(y2+0.5*u22)-(y1+0.5*u21));
        double u41 = h*(y2+u32);
        double u42 = h*(0.1*(1-(y1+u31)*(y1+u31))*(y2+u32)-(y1+u31));
        // calculate y1 and y2
        y1 += (u11 + 2*u21 + 2*u31 + u41)/6;
        y2 += (u12 + 2*u22 + 2*u32 + u42)/6;
        t += h;
        //random comment added x2

    }
    cout<<t<<" "<<y1<<" "<<y2<<endl;
}