#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
//================================================
using namespace std;
priority_queue <int, vector<int>, less_equal<int> > heap;
typedef long long ll;
//================================================
const int maxn=1E6+5;
vector<int> res;
//================================================
void file()
{
	freopen("QBHEAP.INP","r",stdin);
	freopen("QBHEAP.OUT","w",stdout);
}
//================================================
void solve()
{
    char k;int x;
    while(cin >> k)
    {
        if(k=='+')
        {
            cin >> x;
            if(heap.size()<15000) heap.push(x);
        }
        else
        {
            if(!heap.empty())
            {
                x=heap.top();
                while(!heap.empty()&&heap.top()==x)
                    heap.pop();
            }
        }
    }
    while (!heap.empty())
    {
        x=heap.top();
        while (!heap.empty()&&heap.top()==x)
            heap.pop();
        res.push_back(x);
    }
    cout << res.size() << endl;
    fo(i,0,res.size()-1) cout << res[i] << endl;
}
//================================================
int main()
{
	//file();
	solve();
}
