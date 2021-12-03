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

int a[100005];
int f[100005];

int main() {
    int n;
    cin >> n;
    FOR(i,1,n)cin >> a[i];
    f[0] = 0;
    f[1] = 0;
    f[2] = abs(a[2]-a[1])+f[1];
    FOR(i,3,n){
        f[i] = min(abs(a[i]-a[i-2])+f[i-2],abs(a[i]-a[i-1])+f[i-1]);
    }
    cout << f[n];
}
