#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const int maxn=20;
int n;
ll c[maxn][maxn], f[maxn];
ll s[maxn][maxn];
//================================================
void file()
{
	freopen("COND.INP","r",stdin);
	freopen("COND.OUT","w",stdout);
}
//================================================
void solve()
{
    ll res=f[n]+1;
    s[0][0]=1;
    fo(k,2,n-1)
    {
        fo(i,1,n)
        fo(j,1,k) s[i][j] = s[i-1][j-1] + j*s[i-1][j];
        res+=s[n][k]*f[k];
    }
    cout << res << endl;
}
//================================================
void read()
{
    f[0]=1;
    fo(i,1,19) f[i] = f[i-1]*i;
     while (true)
    {
        cin >> n;
        if (n==-1) return;
        solve();
    }
}
//================================================
int main()
{
	//file();
	read();
}s