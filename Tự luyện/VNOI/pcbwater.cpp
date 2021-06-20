#include <bits/stdc++.h>
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define fo1(i,a,b) for(ll i=a;i>=b;--i)
typedef long long ll;
//================================================
using namespace std;
const ll N=105;
ll m,n,hmax,res;
ll h[N][N],a[N][N];
ll dx[4]={-1,0,1,0};
ll dy[4]={0,-1,0,1};
bool f[N][N];
//================================================
void file()
{
	//freopen("PBCWATER.INP","r",stdin);
	//freopen("PBCWATER.OUT","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
//================================================
void read()
{
    cin>>m>>n;
    fo(i,1,m)
    fo(j,1,n)
    {
        cin>>h[i][j];
        hmax=max(hmax,h[i][j]);
    }
}
//================================================
void dfs(ll u,ll v)
{
    f[u][v]=false;
    fo(i,0,3)
    if(f[u+dx[i]][v+dy[i]]) dfs(u+dx[i],v+dy[i]);
}
//================================================
void solve()
{
    fo(k,0,hmax)
    {
        memset(f,false,sizeof(f));
        fo(i,1,m)
        fo(j,1,n) a[i][j]=(h[i][j]>k),f[i][j]=(!a[i][j]);
        fo(i,1,n)
        {
            if(f[1][i]) dfs(1,i);
            if(f[m][i]) dfs(m,i);
        }
        fo(i,2,m-1)
        {
            if(f[i][1]) dfs(i,1);
            if(f[i][n]) dfs(i,n);
        }
        fo(i,1,m)
        fo(j,1,n) if(f[i][j]) res++;
    }
    cout<<res<<endl;
}
//================================================
int main()
{
	file();
	read();
	solve();
}