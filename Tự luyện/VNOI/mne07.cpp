#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fo1(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
//================================================
using namespace std;
const int N=1E5+5;
string s,t;
int n,m;
int S[N],T[N];
//================================================
void file()
{
	//freopen("MNE07.INP","r",stdin);
	//freopen("MNE07.OUT","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
//================================================
void read()
{
    cin>>t>>s;
    s=s+s;
    n=s.length(),m=t.length();
    fo(i,1,n) S[i]=(s[i-1]-48);
    fo(i,1,m) T[i]=(t[i-1]-48);
}
//================================================
bool check(int i,int j)
{
    fo(k,1,m)
        if((S[i+k-1]|S[j+k-1])!=T[k]) return false;
    return true;
}
//================================================
void solve()
{
    fo(i,1,n)
    fo(j,1,n)
    if(check(i,j))
    {
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}
//================================================
int main()
{
	file();
	read();
	solve();
}
