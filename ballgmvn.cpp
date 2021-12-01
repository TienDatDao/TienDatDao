// Socola đây UwU
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


int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    int r;
    while (b > 0) r=a%b, a=b, b=r;
    return a;
}

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int n,x,y,p,q;
    cin >> n;
    pair<int,int> a[2005];
    FOR(i,1,2*n)cin >> a[i].fi >> a[i].se;
    FOR(i,1,n){
    map <pair<int,int>,vector<int>> mp;
        FOR(j,i+1,n){
            x = a[i].fi - a[j].fi;
            y = a[i].se - a[j].se;
            if(x*y!=0){
                p = x;
                q = y;
                x /= gcd(q,p);
                y /= gcd(p,q);
            }
            if(x<0){
                x = -x;
                y = -y;
            }
            mp[{x,y}].pb(j);
            //cout << i << " " << j << " " << x << " " << y << endl;
        }
        FOR(t,n+1,2*n){
            x = a[i].fi - a[t].fi;
            y = a[i].se - a[t].se;
            if(x<0){
                x = -x;
                y = -y;
            }
            if(x*y!=0){
                p = x;
                q = y;
                x /= gcd(q,p);
                y /= gcd(p,q);
            }
            else if(x==0)y=1;
            else if(y==0)x=1;
            mp[{x,y}].pb(t);
            //cout << i << " " << t << " " << x << " " << y << endl;
            if(mp[{x,y}].size()>=2){
                cout << i << " "<<mp[{x,y}][0]<<" "<<t;
                exit(0);
            }
        }
    }
    cout << -1;
    return 0;
}
