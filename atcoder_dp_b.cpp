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

ll a[100005];
ll f[100005];

int main() {
    int n,k;
    cin >> n >> k;
    FOR(i,1,n)cin >> a[i];
    f[0] = 0;
    f[1] = 0;
    FOR(i,2,n){
        f[i] = 1e18;
        FOR(j,1,k){
            if(i>j)f[i] = min(f[i],f[i-j]+abs(a[i]-a[i-j]));
        }
    }
    cout << f[n];
}
