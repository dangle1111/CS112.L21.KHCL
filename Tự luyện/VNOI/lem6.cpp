#include <bits/stdc++.h>
#define SKT ""
#define maxn 1005
 
using namespace std;
long n,k,a[maxn],s[maxn];
string f[maxn][maxn/2];
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
int main()
{
 
	ios_base::sync_with_stdio(0);
    //freopen(SKT".inp", "r" , stdin );
    cin >> n >> k;
    s[0]=-1;
    for(long i=1;i<=k;++i)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i]+1;
    }
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=k;++j)
            f[i][j]="0";
    }
    f[a[1]][1]="1";
    for(long i=a[1]+1;i<=n;++i)
    {
        for(long j=1;j<=k;++j)
        {
            if(i>=s[j])
            {
            f[i][j]=add(f[i-a[j]-1][j-1],f[i-1][j]);
            }
            else
            {
                break;
            }
        }
    }
    string res="0";
    for(long i=1;i<=n;++i)
    {
        //cout << f[i][k] <<" ";
        res=add(res,f[i][k]);
    }
    cout << res;
    return 0;
}
