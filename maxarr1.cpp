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
    f[0] = 0;
    f[1] = 1;
    a[0] = 0;
    a[1] = 1;
    FOR(i,2,100000){
        if(i%2==0)f[i] = f[i/2];
        else f[i] = f[i/2]+f[i/2+1];
        a[i] = max(a[i-1],f[i]);
    }
    cin >> n;
    FOR(i,1,n){
        cin >> f[i];
    }
    FOR(i,1,n){
        cout << a[f[i]] << endl;
    }
}
