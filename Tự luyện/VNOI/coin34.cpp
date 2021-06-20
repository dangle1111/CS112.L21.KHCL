#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
//================================================
using namespace std;
const int maxn=1E6+5;
int n,mx=-1,dem=0,t;
int f[maxn];
int a[maxn],b[maxn];
//================================================
void file()
{
	freopen("COIN34.INP","r",stdin);
	freopen("COIN34.OUT","w",stdout);
}
//================================================
struct mang
{
    int val,sl;
}fa[maxn],fb[maxn];
//================================================
bool cmp(mang X,mang Y)
{
    if(X.val==Y.val) return (X.sl<Y.sl);
    else return (X.val<Y.val);
}
//================================================
void read()
{
    scanf("%d",&t);
    a[1]=2;a[2]=3;a[3]=5;
    fo(i,4,20)
        a[i]=a[i-1]+a[i-2]+a[i-3];
    b[1]=a[18];b[2]=a[19];b[3]=a[20];
    fo(i,4,17)
        b[i]=b[i-1]+b[i-2]+b[i-3];
}
//================================================
void pr()
{
    dem++;
    fo(i,1,17)
    {
        fa[dem].val+=a[i]*f[i];
        fa[dem].sl+=f[i];
        fb[dem].val+=b[i]*f[i];
        fb[dem].sl+=f[i];
    }
}
//================================================
void dnp(int x)
{
    fo(i,0,1)
    {
        f[x]=i;
        if(x==17) pr();
        if(x<17) dnp(x+1);
    }
}
//================================================
int getx(int sct,int dau,int cuoi)
{
    int mid,res=-1;
    while(dau<=cuoi)
    {
        mid=(dau+cuoi)/2;
        if(fa[mid].val<=sct)
        {
            if(fa[mid].val==sct) res=mid;
            dau=mid+1;
        }
        else cuoi=mid-1;
    }
    if(res==-1) return -1;
    return fa[res].sl;
}
//================================================
void solve()
{
    dnp(1);
    sort(fa+1,fa+dem+1,cmp);
    sort(fb+1,fb+dem+1,cmp);
    fo(i,1,t)
    {
        scanf("%d",&n);
        mx=-1;
        fo(i,1,dem)
        if(fb[i].val<=n)
        {
            int k=getx(n-fb[i].val,1,dem);
            if(k!=-1) mx=max(mx,fb[i].sl+k);
        }
        else break;
        printf("Case #%d: %d\n",i,mx);
    }
}
//================================================
int main()
{
    //file();
	read();
	solve();
}
