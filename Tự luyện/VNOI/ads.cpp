#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
//================================================
using namespace std;
const int maxn=5005;
int m,n,u,v,label;
int x[maxn];
bool ok[maxn][maxn];
//================================================
void file()
{
	freopen("ADS.INP","r",stdin);
	freopen("ADS.OUT","w",stdout);
}
//================================================
void read()
{
    cin >> n >> m;
    fo(i,1,m)
    {
        cin >> u >>v;
        ok[u][v]=true;
        ok[v][u]=true;
    }
}
//================================================
void vt(int k,int l)
{
    x[k]=l;
    fo(j,1,n)
        if(x[j]==0&&ok[k][j])   vt(j,l);
}
//================================================
void solve()
{
    memset(x,0,sizeof(x));
    fo(i,1,n)
    {
        if(x[i]==0) label++;
        vt(i,label);
    }
    cout << m-n+label;
}
//================================================
int main()
{
	//file();
	read();
	solve();
}
