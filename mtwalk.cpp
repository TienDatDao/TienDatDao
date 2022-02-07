#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
 
const int hx[4]={0,0,1,-1};
const int hy[4]={1,-1,0,0};
 
int n, a[MAXN][MAXN];
bool Free[MAXN][MAXN];
void dfs(int x, int y, int hmin, int hmax){
	// cout<<x<<" "<<y<<" "<<hmin<<" "<<hmax<<endl;
	Free[x][y] = false;
	for(int i = 0; i < 4; i++){
		int lx = x + hx[i];
		int ly = y + hy[i];
		if(1<=lx && 1<=ly && lx<=n && ly<=n && a[lx][ly]>=hmin && a[lx][ly]<=hmax && Free[lx][ly] == true){
			dfs(lx,ly,hmin,hmax);
		}
	}
}
 
bool check(int m){
	for(int h = 0; h<=110-m; h++)
	if(a[1][1] <=h+m && a[1][1]>=h){
		// cout<<h<<endl;
		memset(Free, true, sizeof(Free));
		dfs(1,1,h,h+m);
		if(Free[n][n] == false) return true;
	}
	return false;
 
}
int main() {
	cin>>n;
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
	int l=0, r=110, res;
	while(l<=r){
		int m = (l+r)/2;
		if(check(m)) {
			res = m;
			r = m-1;
		}
		else l = m+1;
	}
	cout<<res;
	return 0;
}
