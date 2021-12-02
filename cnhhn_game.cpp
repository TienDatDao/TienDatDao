#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define umap unordered_map
#define fi first
#define se second
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll a[200005];
ll b[200005];

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int n;
    cin >> n;
    FOR(i,0,n-1)cin >> a[i];
    FOR(i,0,n-1){cin >> b[i];b[i] = -b[i];}
    ll ans=1e18;
    sort(a,a+n);
    sort(b,b+n);
    b[n] = 1e18;
    FOR(i,0,n-1){
        int pos = upper_bound(b,b+n+1,a[i])-b;
        if(pos>0)ans = min(ans,abs(a[i]-b[pos-1]));
        ans = min(ans,abs(a[i]-b[pos]));
    }
    cout << ans;
    return 0;
}
