#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const int maxn=1E3+5;
int m,n,res;
char a[maxn][maxn];
//================================================
void file()
{
	freopen("VBGRASS.INP","r",stdin);
	freopen("VBGRASS.OUT","w",stdout);
}
//================================================
void read()
{
    cin >> m >> n;
    fo(i,1,m)
    fo(j,1,n) cin >> a[i][j];
}
//================================================
void solve()
{
    res=0;
    fo(i,1,m)
    fo(j,1,n)
    if(a[i][j]=='#')
    {
        if(a[i-1][j]=='#'||a[i][j-1]=='#') continue;
        else res++;
    }
    cout << res << endl;
}
//================================================
int main()
{
	//file();
	read();
	solve();
}
