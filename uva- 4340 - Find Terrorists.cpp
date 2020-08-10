#include<bits/stdc++.h>
using namespace std;
int prime[10001],ara[10001];
int sieve()
{
    memset(prime,0,sizeof prime);
    int n=10001;
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i*i<n;i++)
    {
        if(prime[i]==1)continue;
        for(int j=i+i;j<n;j+=i)
            prime[j]=1;
    }
}
int main()
{
    sieve();
    int i,j;
    for(i=1;i<=10000;i++)
    {
        for(j=1;j*j<i;j++)
        {
            if(i%j==0)
                ara[i]+=2;
        }
        if((j*j)==i)
            ara[i]++;
    }
    int p,a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        p=0;
        for(i=a;i<=b;i++)
        {
            if(prime[ara[i]]==0)
            {
                if(p==1)cout<<' ';
                cout<<i;
                p=1;
            }
        }
        if(p==0)
            cout<<-1<<endl;
        else
            cout<<endl;
    }
        return 0;
}
