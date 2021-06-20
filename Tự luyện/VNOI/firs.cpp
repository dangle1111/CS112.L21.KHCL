#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const int maxn=1E6+5;
int n,res=0;
bool ok[maxn];
//================================================
void file()
{
	freopen("FIRS.INP","r",stdin);
	freopen("FIRS.OUT","w",stdout);
}
//================================================
struct mang
{
    int id,val;
}a[maxn];
bool cmp(mang X,mang Y)
{
    if(X.val==Y.val) return (X.id<Y.id);
    return(X.val<Y.val);
}
//================================================
void read()
{
    memset(ok,true,sizeof(ok));
    scanf("%d",&n);
    fo(i,1,n)
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
}
//================================================
void solve()
{
    sort(a+1,a+n+1,cmp);
    fo(i,1,n)
    if(ok[a[i].id])
    {
        res++;
        ok[a[i].id]=false;
        ok[a[i].id+1]=false;
        ok[a[i].id-1]=false;
    }
    printf("%d",res);
}
//================================================
int main()
{
	//file();
	read();
	solve();
}
