n = int(input())
m = int(input())
j = 1
ans = 1;
for i in range (1,m*n):
	j = j * 2
	ans = ans + j

print(ans)
