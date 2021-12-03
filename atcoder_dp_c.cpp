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
int n, k, x,y,z;
int f[100005];
int a[100005][4];
int main() {
    cin>>n;
    FOR(i,1,n){
        cin>>x>>y>>z;
        a[i][1]=max(a[i-1][2], a[i-1][3])+x;
        a[i][2]=max(a[i-1][1], a[i-1][3])+y;
        a[i][3]=max(a[i-1][1], a[i-1][2])+z;
    }
    cout<<max({a[n][1], a[n][2], a[n][3]});

}
