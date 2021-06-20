#include <bits/stdc++.h>
using namespace std;
int n, tong;
string dad,mom,child;
vector<char> exstr[20];
void dp(int x)
{
    for(int i=0;i<exstr[x].size();i++)
    {
        child[x]=exstr[x][i];
        if(x+1<n) dp(x+1);
        if(x+1==n) cout<<child<<endl;
    }
}
int main()
{
    cin>>n;
    cin>>dad>>mom;
    for(int i=1;i<=n;i++) child+="*";
    for(int i=0;i<n;i++)
    if(dad[i]==mom[i]) exstr[i].push_back(char(dad[i]));
    else exstr[i].push_back(char(min(dad[i],mom[i]))),exstr[i].push_back(char(max(dad[i],mom[i])));
    tong=1;
    for(int i=0;i<n;i++) tong*=exstr[i].size();
    cout<<tong<<endl;
    dp(0);
}