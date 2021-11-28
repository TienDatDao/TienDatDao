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
    /*vector<int> a;
    FOR(i,1,10) a.pb(i);
    a.erase(a.begin()+1);
    int pos = upper_bound(a.begin(),a.end(),-1)-a.begin();
    cout << a[pos];*/
    ll n,x,k;
    cin >> n >> k;
    vector<ll> b;
    vector<ll> a;
    FOR(i,1,n){
        cin >> x;
        a.pb(x);
    }
    n--;
    ll ans;
    sort(a.begin(),a.end());
    while(a.size()>0){
        b.pb(a[a.size()-1]);
        ll pos = upper_bound(a.begin(),a.end(),a[a.size()-1]-k)-a.begin();
        if(pos == 0){
                a.pop_back();
                continue;
            }
        ll l = a[pos-1];
        a.erase(a.begin()+pos-1);
        while(l-k>=a[0]){
            pos = upper_bound(a.begin(),a.end(),l-k)-a.begin();
            if(pos == 0){
                break;
            }
            l = a[pos-1];
            a.erase(a.begin()+pos-1);
        }
        a.pop_back();
    }
    FOR(i,0,b.size()-1){
        ans+= b[i];
    }
    cout << ans;
    return 0;
}
