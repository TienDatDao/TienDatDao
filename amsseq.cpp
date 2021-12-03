#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define ldb long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>
const int N = 150000;
const int mod = 14062008;
int n, k, a[N], f[N], x;

int main() {
    cin >> n >> k;
    FOR(i,1,n)cin >> a[i];
    f[0] = 0;
    int ans = -1e9;
    FOR(i,1,n){
        f[i] = -1e9;
        FOR(j,1,k){
            if(i>=j)f[i] = max(f[i],f[i-j]+a[i]);
        }
        ans = max(ans,f[i]);
    }
    cout << ans;
}
