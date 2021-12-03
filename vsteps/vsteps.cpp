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
    FOR(i,1,k){
        cin >> x;
        a[x]=1;
    }
    f[1] = 1;
    FOR(i,2,n){
        if(a[i]==0){
            f[i] = (f[i-1]+f[i-2])%mod;
        }
    }
    cout << f[n];
}
