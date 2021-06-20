#include <bits/stdc++.h>
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fo1(i,a,b) for(ll i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const ll maxn=1E3+5;
ll n,t,x,y,u,v;
ll f[maxn][maxn],a[maxn][maxn];
//================================================
void file()
{
	freopen("VBOARD.INP","r",stdin);
	freopen("VBOARD.OUT","w",stdout);
}
//================================================
void read()
{
    cin >> n;
    fo(i,1,n)
    fo(j,1,n)
    {
        cin >> a[i][j];
        if((i+j)%2==0)
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
        else
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]-a[i][j];
    }
}
//================================================
void solve()
{
    cin >> t;
    fo(i,1,t)
    {
        cin >> x >> y >> u >> v;
        ll res=f[u][v]-f[u][y-1]-f[x-1][v]+f[x-1][y-1];
        cout << abs(res) << endl;
    }
}
//================================================
int main()
{
	//file();
	read();
	solve();
}