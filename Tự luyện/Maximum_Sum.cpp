#include <bits/stdc++.h>
#define maxn 1000001
#define x first
#define y second
using namespace std;
typedef pair < int , int > II;
II it[maxn];
int n,a[maxn];
void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void khoitao(int r,int k,int l)
{
    if(k==l)
    {
        it[r]=II(a[k],k);
        return;
    }
    int g=(k+l)/2;
    khoitao(2*r,k,g);
    khoitao(2*r+1,g+1,l);
    it[r]=max(it[2*r],it[2*r+1]);
}
void update(int r,int k,int l,int u,int v,int val)
{
    if(v<k||l<u) return;
    if(u<=k&&l<=v) {it[r].x=val;return;}
    int g=(k+l)/2;
    update(2*r,k,g,u,v,val);
    update(2*r+1,g+1,l,u,v,val);
    it[r]=max(it[2*r],it[2*r+1]);
}
II get(int r,int k,int l,int u,int v)
{
    if(v<k||l<u) return II(0,0);
    if(u<=k&&l<=v) return II(it[r].x,it[r].y);
    int g=(k+l)/2;
    II t1=get(2*r,k,g,u,v);
    II t2=get(2*r+1,g+1,l,u,v);
    return max(t1,t2);
}
void tinh()
{
    int Q;
    khoitao(1,1,n);
    cin>>Q;
    while(Q--)
    {
        char ch;
        int u,v;
        cin>>ch>>u>>v;
        if(ch=='U') update(1,1,n,u,u,v);
        else
        {
            II t=get(1,1,n,u,v);
            int l=t.y;
            II t1=get(1,1,n,u,l-1);
            II t2=get(1,1,n,l+1,v);
            cout<<t.x+max(t1.x,t2.x)<<endl;
        }
    }
}
int main()
{
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    doc();
    tinh();
}