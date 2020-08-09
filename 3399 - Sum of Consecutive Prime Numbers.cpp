#include<bits/stdc++.h>
using namespace std;
int prime[10001],fin[10001];
vector<int> v,sum;
void sieve()
{
    int p,i,j,n=10001;
    prime[0]=1;
    prime[1]=1;
    for(i=2; i*i<n; i++)
    {
        if(prime[i]==1)
            continue;
        for(j=i+i; j<n; j+=i)
            prime[j]=1;
    }
    p=0;
    for(i=0; i<n; i++)
    {
        if(prime[i]==0)
        {
            p=p+i;
            v.push_back(i);
            sum.push_back(p);
        }
    }
  /*  for(i=0;i<=10;i++)
        cout<<sum[i]<<' ';
    cout<<endl;*/
}
int main()
{
    int i,l,p,q,j,n,x;
    sieve();
    l=v.size();
    for(i=1; i<=l; i++)
    {
        for(j=0; j<l; j++)
        {
            p=j-1;
            q=j+i-1;

            if(p==-1 && q<l && sum[q]<10001){
                x=sum[q];
                fin[x]++;
            }
            else if(p>=0 && q<l && (sum[q]-sum[p])<10001){
                fin[(sum[q]-sum[p])]++;
            }
        }
    }
    while(cin>>n && n!=0)
    {
        cout<<fin[n]<<endl;
    }
    return 0;
}
