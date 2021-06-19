n=int(input())
a=list(map(int,input().split()))
a.insert(0,0)
L=[-1]*(n+1)
R=[-1]*(n+1)
dp=[0]
trace=[0]

def init():
    S=[]
    for i in range(1,n+1):
        L[i]=i
        
        while (len(S)!=0) and (S[-1] >i-a[i]):
            L[i]=min(L[i],L[S[-1]])
            S.pop(-1)
        S.append(i)
    
    
    S=[]
    for i in range(n,0,-1):
        R[i]=i
        
        while (len(S)!=0) and (S[-1] <i+a[i]):
            R[i]=max(R[i],R[S[-1]])
            S.pop(-1)
        S.append(i)
        
    

def solve():
    for i in range(1,n+1):
        dp.append(i)
        trace.append(-i)
    S=[]
    for i in range(1,n+1):
        if dp[i]>dp[L[i]-1]+1:
            dp[i]=dp[L[i]-1]+1
            trace[i]=-(L[i])
        while len(S)!=0 and R[S[-1]]<i:
            S.pop(-1)
        if len(S)!=0 and dp[i]>dp[S[-1]-1]+1:
            dp[i]=dp[S[-1]-1]+1
            trace[i]=S[-1]
        if len(S)==0 or dp[S[-1]-1]> dp[i-1]:
            S.append(i)
    print(dp[n])
   
    j=n
    while j:
        if trace[j]<0:
            print(-(j),end=" ")
        else: 
            print(trace[j],end=" ")
        j=abs(trace[j])-1


init()
solve()