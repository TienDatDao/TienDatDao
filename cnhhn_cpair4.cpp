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
//#define mp make_pair
#define ep emplace_back
#define EL printf("\n")-
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int a[10005];
map <int,int> mp;
int res;
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    ll n;
    cin >> n;
    FOR(i,1,n)cin >> a[i];
    FOR(i,1,n){
        FOR(j,i+1,n)mp[a[i] + a[j]]++;
    }
    FOR(i,1,n) {
        FOR(j,i+1,n) mp[a[i] + a[j]]--;
        FOR(j,1,i-1){
            res += mp[a[i]+ a[j]];
        }
    }
    cout << res;
    return 0;
}
