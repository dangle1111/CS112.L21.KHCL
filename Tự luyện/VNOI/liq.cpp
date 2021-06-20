#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int l[maxn],a[maxn],i,j,n,lmax,leng;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    l[1]=1;
    for(i=2;i<=n;i++)
    {
        lmax=0;
        for(j=1;j<=i;j++)
        {
            if (a[i]>a[j])
             if (l[j]>lmax) lmax=l[j];
        }
        l[i]=lmax+1;
    }
    leng=0;
    for(i=1;i<=n;i++)
        if (l[i]>leng) leng=l[i];
    cout<<leng;
}
