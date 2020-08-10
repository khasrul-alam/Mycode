#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod(ll x,ll y,ll n)
{
    ll p;
    if(y==0)
        return 1;
    else if(y%2==0)
    {
        p=mod(x,y/2,n);
        return ( (p%n) * (p%n) )%n;
    }
    else{
        p=mod(x,y-1,n);
        return ( (p%n) * (x%n) )%n;
    }
}
int main()
{
    ll t,x,y,n;
    cin>>t;
    while(t--)
    {
    cin>>x>>y>>n;
    cout<<(mod(x,y,n))<<endl;
    }
    cin>>t;
    return 0;
}
