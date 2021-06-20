#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
 
using namespace std;
 
const ll maxn=1005;
ll n,k,a[maxn],f[maxn][maxn],x,y;
 
ll sub(int i, int j)
{
    int tmp;
    tmp=i-j;
    if (tmp<0) tmp+=k;
    return tmp;
}
 
void solve()
{
    int tmp;
    cin >> n >> k;
    fo(i,1,n)
    {
        cin >> tmp;
        a[i]=tmp%k;
    }
    fo(i,1,k-1) f[0][i]=-n-1;
    f[0][0]=0;
    x=0;y=1;
    fo(i,1,n)
    {
        fo(j,0,k-1)
            f[y][j]=max(f[x][j],f[x][sub(j,a[i])]+1);
        x=1-x;y=1-y;
    }
    cout << f[x][0];
}
 
int main()
{
    solve();
}