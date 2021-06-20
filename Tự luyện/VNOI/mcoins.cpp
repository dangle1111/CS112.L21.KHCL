#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int     n[100], m, k, l, f[1000001], maxn;
 
int main()
{
    scanf("%d%d%d",&k,&l,&m);
 
    for (int i=1;i<=m;i++) {
        scanf("%d",&n[i]);
        maxn = max(n[i],maxn);
    }
 
    for (int i=1;i<=maxn;i++) {
        if (i-1 >= 0 and f[i-1] == 0) f[i] = 1;
        if (i-k >= 0 and f[i-k] == 0) f[i] = 1;
        if (i-l >= 0 and f[i-l] == 0) f[i] = 1;
    }
 
    for (int i=1;i<=m;i++)
        if (f[n[i]] == 1)
            printf("A");
        else
            printf("B");
 
    return 0;
}
