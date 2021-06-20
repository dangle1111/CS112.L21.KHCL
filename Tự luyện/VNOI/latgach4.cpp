#include <bits/stdc++.h>
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fo1(i,a,b) for(ll i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const ll BASE=111539786;
const ll maxn=1E6+5;
ll t,val;
//================================================
struct matrix
{
    ll p[3][3];
};
//================================================
void file()
{
	freopen("LATGACH4.INP","r",stdin);
	freopen("LATGACH4.OUT","w",stdout);
}
//================================================
matrix nhan(matrix A,matrix B)
{
    matrix C;
    fo(i,1,2)
    fo(j,1,2)
    {
        C.p[i][j]=0;
        fo(k,1,2) C.p[i][j]=(C.p[i][j]+A.p[i][k]*B.p[k][j])%BASE;
    }
    return C;
}
//================================================
matrix luy(matrix X,ll y)
{
    if(y==1) return X;
    matrix tmp=luy(X,y/2);
    tmp=nhan(tmp,tmp);
    if(y%2==1) tmp=nhan(tmp,X);
    return tmp;
}
//================================================
ll solve(ll n)
{
    matrix a,b;
    a.p[1][1]=1;a.p[1][2]=1;
    a.p[2][1]=0;a.p[2][2]=0;
    b.p[1][1]=0;b.p[1][2]=1;
    b.p[2][1]=1;b.p[2][2]=1;
 
    if(n==1) return 1;
    b=luy(b,n-1);
    a=nhan(a,b);
    return a.p[1][2];
}
//================================================
void read()
{
    cin >> t;
    fo(i,1,t)
    {
        cin >> val;
        cout << solve(val) << endl;
    }
}
//================================================
int main()
{
	//file();
	read();
}