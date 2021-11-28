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
#define ep emplace_back
#define EL printf("\n")-
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll ans;
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int n;
    cin >> n;
    double a[n];
    double b[n];
    FOR(i,0,n-1){
        cin >> a[i];
        b[i] = 0.9*a[i];
    }
    sort(b,b+n);
    sort(a,a+n);
    //FOR(i,0,n-1) cout << a[i]<<" ";
    //cout<< endl;
    //FOR(i,0,n-1) cout << b[i]<<" ";
    //cout<< endl;
    FOR(i,0,n-1){
        int pos = upper_bound(b,b+n,a[i])-b;
        //cout << pos-i-1 << endl;
        ans+=(pos-i-1);
    }
    cout << ans;
    return 0;
}
