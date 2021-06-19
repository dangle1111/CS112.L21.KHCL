from collections import deque

a = []
L = []
R = []
dp = []
trace = []

n = int(input())
a = [int(x) for x in input().split()]
a = [0] + a
L = [i for i in range(n+1)]
R = [i for i in range(n+1)]
dp = [i for i in range(n+1)]
trace = [-i for i in range(n+1)]
S = deque()

for i in range(1, n+1):
	L[i] = i
	while len(S) > 0 and S[-1] > i - a[i]:
		L[i] = min(L[i], L[S[-1]])
		S.pop()
	S.append(i)
S.clear()

for i in range(n, 0, -1):
	R[i] = i
	while len(S) > 0 and S[-1] < i + a[i]:
		R[i] = max(R[i], R[S[-1]])
		S.pop()
	S.append(i)
S.clear()

for i in range(1, n+1):
	if dp[i] > dp[L[i] - 1] + 1:
		dp[i] = dp[L[i] - 1] + 1
		trace[i] = -L[i]

	while len(S) > 0 and R[S[-1]] < i:
		S.pop()

	if len(S) > 0 and dp[i] > dp[S[-1] - 1] + 1:
		dp[i] = dp[S[-1] - 1] + 1
		trace[i] = S[-1]

	if len(S) == 0 or dp[S[-1] -1] > dp[i-1]:
		S.append(i)

print(dp[n])
i = n
while i > 0:
	if trace[i] < 0:
		print(-i, end=' ')
	else:
		print(trace[i], end=' ')
	i = abs(trace[i]) - 1