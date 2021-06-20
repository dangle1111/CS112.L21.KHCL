#include <iostream>
using namespace std;
long long d,m,n;
int main() {
  	cin >> n >> m;
  	d=m*n;
  	while (d>n)
    	d+=(d-n-1)/(m-1)-n;
  	cout << d << endl;
}
