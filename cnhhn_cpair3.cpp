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
    int n;
    cin >> n;
    int a[n+2];
    int b[n+2];
    int c[n+2];
    a[0]=-1e9;
    c[0]=-1e9;
    a[n+1]=1e9;
    c[n+1]=1e9;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    FOR(i,1,n) cin >> c[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    FOR(i,1,n){
        int it = lower_bound(a+1,a+1+n,b[i])-a-1;
        int it2 = upper_bound(c+1,c+1+n,b[i])-c;
        //cout << it << " " << n-it2+1<<endl;
        ans+= (it)*(n-it2+1);
    }
    cout << ans;
}
