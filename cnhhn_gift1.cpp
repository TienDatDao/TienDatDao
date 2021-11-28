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

umap<int,pair<int,int>> s;
ll ans;
int dem0;
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int n,x;
    cin >> n;
    FOR(i,1,n){
        cin >> x;
        if(x>0){
            s[x].fi++;
        }else if(x<0){
            s[-x].se++;
        } else dem0++;
    }
    ans = dem0*(dem0-1)/2;
    for(auto y:s){
        ans += s[y.fi].se*s[y.fi].fi;
    }
    cout << ans;
}
