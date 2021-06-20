from collections import deque
N = 4e6 + 6
n = 0
def initialize(L,R,H):
  S = []
  for i in range(1,n+1):
    while S !=[] and S[-1] > i - H[i]:
      L[i]=min(L[i], L[S[-1]])
      S.pop()
    S.append(i)

  S = []

  for i in range(n,0,-1):
    
    while S != [] and S[-1] < i + H[i]:
      R[i]= max(R[i], R[S[-1]])
      S.pop()
    S.append(i)

def solve(L,R,H,dp, trace):
  S = []
  for i in range(1,n+1):
    if dp[i] > dp[L[i]-1] + 1:
      dp[i] = dp[L[i]-1] + 1
      trace[i] = -L[i]
    while S != [] and R[S[-1]] < i:
      S.pop()
    if S != [] and dp[i] > dp[S[-1] - 1] + 1:
      dp[i] = dp[S[-1] - 1] + 1
      trace[i] = S[-1]
    if S == [] or dp[S[-1] - 1] > dp[i-1]:
      S.append(i)
  print(dp[n-1])
  i = n
  while i:
    if trace[i] < 0:
      print(-i, end= ' ')
    else:
      print(trace[i], end=' ')
    i = abs(trace[i]) - 1

if __name__ == '__main__':
  n = int(input())
  H = list(map(int,input().split(' ')))
  H.insert(0,0)
  L = [i for i in range(n+1)]
  R = [i for i in range(n+1)]
  dp = [i for i in range(n+1)]
  trace = [-i for i in range(n+1)]
  initialize(L,R,H)
  solve(L,R,H,dp, trace)