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


int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    ll n,x,y;
    cin >> n;
    ll a[n+1];
    ll b[n+1];
    FOR(i,1,n){
        cin >> x >> y;
        a[i] = x+y;
        b[i] = x-y;
    }
    sort(a+1,a+1+n);
    ll max1,max2;
    max1 = abs(a[n]-a[1]);
    sort(b+1,b+1+n);
    max2 = abs(b[n]-b[1]);
    cout << max(max1,max2);
}
