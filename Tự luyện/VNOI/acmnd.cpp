#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
 
#define FOR(i,n) for(int i=0;i<n;++i)
#define FORI(i,n) for(int i=1;i<=n;++i)
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define REPD(i,a,b) for(int i=a; i>=b;--i)
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int n;
ii a[800010];
 
bool compare(ii i,ii j) {return i.X-i.Y < j.X - j.Y;}
int main(void)
{
    scanf("%d",&n);
    REP(i,1,2*n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+1+2*n,compare);
    int ans = 0;
    REP(i,1,n) ans += a[i].X;
    REP(i,n+1,2*n) ans += a[i].Y;
    cout << ans;
	return 0;
}
