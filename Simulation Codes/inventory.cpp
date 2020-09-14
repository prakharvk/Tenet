#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ud - units due
    // dd - due date
    // dem - demand
    // s - stocks
    // p & q are variables
    
    int p,q,s,es,ud,dd,dem;
    cin>>p>>q;
    double cost = 0.0;
    s = 115;
    ud = dd = 0;
    for(int i=1;i<=180;++i) // simulating for 180 days
    {
        if(dd == i) // if due date is current date
        {
            s = s + q;
            ud = 0;
        }
        dem = rand()%100; // any random number between 0 and 100
        if(dem <= s) // if demand is less than equal to s
        {
            s = s-dem;
            cost += (float(s)*.75);
        }
        else
        {
            // add shortage cost to the total cost, reset stock to zero
            cost += ((float(dem) - float(s)))*18.0;
            s = 0;
        }
        es = s+ud;
        if(es <= p)
        {
            ud = q;
            dd = i+3;
            cost += 75;
        }
    
    }
    cout<<p<<" "<<q<<" "<<cost<<endl;

}