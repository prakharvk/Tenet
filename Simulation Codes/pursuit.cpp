#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<float> xf(12),yf(12),xb(12), yb(12);
    float vf;
    printf("Enter Target path, xb[t] & yb[t]:");
    for(int i=0;i<12;i++) cin>>xb[i]>>yb[i];
    
    
    printf("Enter Fighter's Initial path, xf[0] & yf[0]:");
    cin>>xf[0]>>yf[0];
    printf("Enter Fighter velocity, vf:");
    cin>>vf;

    bool caught = false;
    for(int t=0;t<12;t++) {
        float d=sqrt(pow((yb[t]-yf[t]),2)+pow((xb[t]-xf[t]),2));
        if(d<10)
        {
            printf("\nCaught at %d mts and %f kms\n",t,d);
            caught = true;
            break;
        }
        else
        {
            xf[t+1]=xf[t]+(vf*(xb[t]-xf[t])/d);
            yf[t+1]=yf[t]+(vf*(yb[t]-yf[t])/d);
        }
    }
    if(!caught) printf("Target Escaped\n");
}