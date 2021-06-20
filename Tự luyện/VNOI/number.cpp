#include <iostream>
#include <stdio.h>
#include <cstdio>
#define maxn 10001
 
int adj[maxn], adj2[maxn], head[maxn], head2[maxn], linker[maxn], link2[maxn], part[maxn];
bool avail[maxn], visit[maxn];
int res,n,m,t,ssc;
 
using namespace std;
 
void inputer() {
    //freopen("number.in","r",stdin);
    scanf("%d %d %d", &n, &m, &t);
    int x,y;
    for(int i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        adj[i] = y;
        linker[i] = head[x];
        head[x] = i;
        adj2[i] = x;
        link2[i] = head2[y];
        head2[y] = i;
    }
}
 
int dfser(int i) {
    avail[i] = false;
    int j = head[i];
    while (j) {
        if (avail[adj[j]]) return dfser(adj[j]);
        j = linker[j];
    }
    return i;
}
 
void dfs2(int i) {
    visit[i] = true;
    int j = head2[i];
    while (j) {
        if (!visit[adj2[j]])
            dfs2(adj2[j]);
        j = link2[j];
    }
}
 
void dfsFind(int i) {
    visit[i] = true;
    avail[part[i]] = false;
    int j = head2[i];
    while (j) {
        if (!visit[adj2[j]])
            dfsFind(adj2[j]);
        j = link2[j];
    }
}
 
void process() {
    for(int i=1; i<=n; i++)
    {
        avail[i] = true;
        visit[i] = false;
    }
    int st;
    for(int i=1; i<=n; i++) {
        if (!visit[i]) {
            st = dfser(i);
            ssc++;
            part[st] = ssc;
            dfs2(st);
        }
    }
    for(int i=1; i<=n; i++) {
            visit[i] = false;
            avail[i] = true;
    }
    dfsFind(t);
    for(int i=1; i<=ssc; i++)
        if (avail[i]) res++;
}
 
void outputer() {
    printf("%d",res);
}
 
int main()
{
    inputer();
    process();
    outputer();
    return 0;