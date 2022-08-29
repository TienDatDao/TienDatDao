int bit[2505][2505];

void update(int x, int y, int val) {
	for (; x <= N1; x += (x & (-x))) {
		for (int i = y; i <= M1; i += (i & (-i))) {
			bit[x][i] = max(bit[x][i],val);
		}
	}
}
 
int getmax(int x,int y)
{
    int ans = -1e9;
    for(;x;x -= (x & (-x))){
        for(int i = y;i > 0; i -= (i & (-i))){
            ans = max(ans,bit[x][i]);
        }
    }
    return ans;
}
