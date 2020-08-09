#include<bits/stdc++.h>
using namespace std;
int main()
{
  
    int x;
    double p,res;
    while(1)
    {

        cin>>x;
        if(x==0)break;
        p=x*1.6;
        res=((x/5)*8.0);
        x=x%5;

        if(x==1)
            res+=2;
        else if(x==2)
            res+=3;
        else if(x==3)
            res+=5;
        else if(x==4)
            res+=6;
        res=abs(res-p);

        printf("%.2f\n",res);
    }
}
