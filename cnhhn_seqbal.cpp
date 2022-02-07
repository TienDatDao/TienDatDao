#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ll long long 
#define fi first
#define se second
#define endl "\n"
#define MAXN 200005
#define INF 1e15
using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
map<int,int> mp;
typedef unordered_map<int,int> ump;

int f[MAXN], a[MAXN];
int n, ans = 0;
int res = 1e5 + 1;

int main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
    memset(f, -1, sizeof(f));
    f[res] = 0;
    for(int i = 1; i <= n; i++) {
    	if(a[i] == 1) res++;
    	else res--;
    	if(f[res] != -1) ans = max(ans, i - f[res]);
    	if(f[res] == -1) f[res] = i;
	}
    cout << ans;
    return 0;
}
