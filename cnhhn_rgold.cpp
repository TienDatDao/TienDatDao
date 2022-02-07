#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define fi first
#define se second
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>
int n,t;
pair<int,int> a[30005];
int f[3005][3005];
int ans = 0;
int main() {
	cin >>n>>t;
	FOR(i,1,n) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1);
	FOR(i,1,n){
		FOR(j,1,t) {
		    f[i][j] = 0;
			f[i][j] = max(f[i][j],f[i-1][j]);
			if (j>a[i].fi)f[i][j]= max(f[i][j],f[i-1][j-a[i].fi] + a[i].se);
 		}
	}
	FOR(i,1,n) {
		ans = max(ans,f[i-1][t] + a[i].se);
	}
	cout << ans;
	return 0;
}
