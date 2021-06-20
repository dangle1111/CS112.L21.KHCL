#include <bits/stdc++.h>
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fo1(i,a,b) for(ll i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const ll maxn=1E6+5;
ll n,res;
ll a[maxn];
//================================================
void file()
{
	freopen("INSUL.INP","r",stdin);
	freopen("INSUL.OUT","w",stdout);
}
//================================================
void read()
{
    cin >> n;
    fo(i,1,n)
    {
        cin >> a[i];
        res+=a[i];
    }
}
//================================================
void solve()
{
    sort(a+1,a+n+1);
    fo(i,1,n/2) res+=a[n-i+1]-a[i];
    cout << res << endl;
}
//================================================
int main()
{
	//file();
	read();
	solve();
}