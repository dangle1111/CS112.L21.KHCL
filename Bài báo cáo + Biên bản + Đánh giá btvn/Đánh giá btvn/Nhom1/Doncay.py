n=int(input())
hh=list(map(int,input().split()))
l=[0]*(n+1)
r=[0]*(n+1)
h=[0]*(n+1)
for i in range(1,n+1):
  h[i]=hh[i-1]
def repair():
  s=[]
  for i in range(1,n+1):
    l[i]=i
    while (len(s)!=0) and (s[len(s)-1]>i-h[i]):
      l[i]= min(l[i],l[s[len(s)-1]])
      s.pop()
    s.append(i)
  s.clear()
  for i in reversed(list(range(1,n+1))):
    r[i]=i
    while (len(s)!=0) and (s[len(s)-1]<i+h[i]):
      r[i]= max(r[i],r[s[len(s)-1]])
      s.pop()
    s.append(i)
def solve():
  res=[0]*(n+1)
  trace=[0]*(n+1)
  for i in range(1,n+1):
    res[i]=i
    trace[i]=-i
  s=[]
  for i in range(1,n+1):
    if (res[i]>res[l[i]-1]+1):
      res[i]=res[l[i]-1]+1
      trace[i]=-(l[i])
    while (len(s)!=0) and (r[s[len(s)-1]]<i):
      s.pop()
    if (len(s)!=0) and (res[i]>res[s[len(s)-1]-1]+1):
      res[i]=res[s[len(s)-1]-1]+1
      trace[i]=s[len(s)-1]
    if (len(s)==0) or (res[s[len(s)-1]-1]>res[i-1]):
      s.append(i)
  print(res[n])
  j=n
  for i in range(res[n]):
    if (trace[j]<0):
      print(-j,end=' ')
    else:
      print(trace[j],end=' ')
    j=abs(trace[j])-1
repair()
solve()