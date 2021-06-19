def initialize(L,R,n,a):
    S=[]
    for i in range(n+1):
        L[i]=i
        while len(S) != 0 and S[-1] > i - a[i]:
            L[i]=min(L[i],L[S[-1]],S.pop())
        S.append(i)
    S=[]
    temp = n
    while temp >= 1 :
        R[temp]=temp
        while len(S) != 0 and S[-1] < temp + a[temp]:
            R[temp]=max(R[temp],R[S[-1]],S[-1])
            S.pop()
        S.append(temp)
        temp = temp -1

def solve(L,R,n,cache,trace) :
    for i in range(n+1):
        cache[i]=i
        trace[i]=-i
    S=[]
    for i in range(n+1):
        if cache[i] > cache[L[i]-1] +1 :
            cache[i]=cache[L[i]-1]+1
            trace[i]=-(L[i])
        while len(S)!=0 and R[S[-1]] < i :
            S.pop()
        if len(S) != 0 and cache[i] > cache[S[-1] - 1] + 1 :
            cache[i] = cache[S[-1] - 1] + 1
            trace[i] = S[-1]
        if len(S)==0 or (cache[S[-1] - 1] > cache[i - 1]) :
            S.append(i)
    print(cache[n])
    temp = n
    s=''
    while temp!=0:
        if trace[temp] < 0 :
            s=s+str(-temp)+' '
        else:
            s=s+str(trace[temp])+' '
        temp=abs(trace[temp])-1
    print(s)


n = int(input())
input_string = input()
List=input_string.split()
List1=[0]*3950041
for i in range(1,len(List)+1):
    List1[i] = int(List[i-1])%1000000007
L = [0]*3950041
R = [0]*3950041
cache = [0]*3950041
trace = [0]*3950041
initialize(L,R,n,List1)
solve(L,R,n,cache,trace)