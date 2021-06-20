#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fo1(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
long long t,a,b;
long long calc(long long a) {return (a)/12+(a)/30-((a)/60)*2;}
int main()
{
	cin>>t;
	fo(i,1,t)
	{
		cin>>a>>b;
		cout<<calc(b)-calc(a-1)<<endl;
	}
	return 0;
}
s