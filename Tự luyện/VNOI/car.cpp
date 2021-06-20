#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fo1(i,a,b) for(int i=a;i>=b;--i)
//=====================================================
typedef long long ll;
using namespace std;
const int N=10005;
typedef struct {int a,b,i;float x;}car;
bool cmp( const car & a, const car &b) {return a.x<b.x;}
car v[N];
ll n,money=0,d=0;
//=====================================================
void file()
{
    //freopen("CAR.INP","r",stdin);
    //freopen("CAR.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
//=====================================================
void read()
{
    cin>>n;
	fo(i,1,n) cin>>v[i].a;
	fo(i,1,n)
    {
		cin>>v[i].b;
		v[i].x=(float)v[i].a/v[i].b;
		v[i].i=i;
	}
	sort(v+1,v+n+1,cmp);
}
//=====================================================
void solve()
{
	fo1(i,n,1) d+=v[i].b,money+=d*v[i].a;
	cout<<money<<endl;
	fo1(i,n,1) cout<<v[i].i<<" ";
}
//=====================================================
int main()
{
    file();
    read();
    solve();
}
//=====================================================
