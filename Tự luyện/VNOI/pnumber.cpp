#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b,m;
	cin >> a >> b;
	for(int i=a;i<=b;i++)
	{
		m=0;
		for(int j=2;j<=sqrt(i);j++)
			if(i%j==0) m++;
		if (m==0&&i>1) cout << i << endl;
	}
}
