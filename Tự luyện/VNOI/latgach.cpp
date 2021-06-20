#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
//================================================
using namespace std;
const int maxn=1E3+5;
string f[maxn];
int t,n;
//================================================
void file()
{
	freopen("LATGACH.INP","r",stdin);
	freopen("LATGACH.OUT","w",stdout);
}
//================================================
int stringToNum(char c)     // chuyen char sang so
{
    return c - '0';
}
//================================================
char numToString(int n)     // chuyen so sang char
{
    return (char)(n+48);
}
//================================================
void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');    // chen vao dau cua b cac ky tu '0'
    }
    else
    {
        a.insert(0, l2-l1, '0');    // chen vao dau cua a cac ky tu '0'
    }
}
//================================================
string sum(string a, string b)  // tong 2 so
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
 
    int temp = 0;
    for (int i=l-1; i>=0; i--)   // duyet va cong
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
        s.insert(0,1,numToString(temp%10));         // gan phan don vi vao
        temp = temp/10;     // lay lai phan hang chuc
    }
    if (temp>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}
//================================================
void read()
{
    cin >> t;
}
//================================================
void solve()
{
    f[1]='1';f[2]='2';
    fo(i,3,100)
        f[i]=sum(f[i-1],f[i-2]);
    fo(i,1,t)
    {
        cin >> n;
        cout << f[n] << endl;
    }
}
//================================================
int main()
{
	//file();
	read();
	solve();
}
