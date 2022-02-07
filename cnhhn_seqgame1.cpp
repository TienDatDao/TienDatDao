#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define fi first
#define se second
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecull vector<long long>
ll n,d,ans=0;
ll a[1005];

int main() {
    cin >> n >> d;
    FOR(i,1,n)cin >> a[i];
    FOR(i,2,n){
        a[i]-=d*(i-1);
    }
    sort(a+1,a+n+1);
    ll k = a[(n+1)/2];
    FOR(i,1,n){
        ans+=abs(k-a[i]);
    }
    cout << ans;
	return 0;
}
