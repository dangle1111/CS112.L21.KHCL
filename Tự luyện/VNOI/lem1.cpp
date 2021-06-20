#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fo1(i,a,b) for(int i=a;i>=b;--i)
#define pi 3.1415926535898
#define eps 0.0000001
using namespace std;
typedef double dd;
typedef long long ll;
const int N=10005;
const int oo=1000000000;
int n,a[N];
//========================================================================
dd tonggoc(dd t)
{
    dd sum=0;
    fo(i,1,n)
        sum=sum+acos(1-2*a[i]*a[i+1]/((a[i]+t)*(a[i+1]+t)));
    return sum;
}
//========================================================================
void solve()
{
    dd l=eps,r=oo;
    while(r-l>eps)
    {
        dd mid=(l+r)/2;
        if(tonggoc(mid)<2*pi) r=mid;
        else l=mid;
    }
    printf("%.3f",l);
}
//========================================================================
void read()
{
    cin>>n;
    fo(i,1,n) cin>>a[i];
    a[n+1]=a[1];
}
//========================================================================
int main()
{
    //freopen("COINS.INP","r",stdin);
    //freopen("COINS.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    read();
    solve();
}