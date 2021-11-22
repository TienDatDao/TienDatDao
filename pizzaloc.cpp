#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <string>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")-
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int k,r,m,n;
pii a[25];
int d[105];
pair<pair<int,int>,int> b[105];
vector<int> List[25];
int sum;
 
bool check(int x1, int y1, int x2, int y2, int r){
    double q = x1-x2;
    double p = y1-y2;
    double ans = sqrt(q*q+p*p);
    if(ans <= r) return true;
    else return false;
}
 
void duyet(int i,int k,int ans,int dem,int m){
    if(dem>=k||i>m){
        sum = max(sum,ans);
        return;
    }
    // chọn
    for(auto x:List[i]){
        if(d[x]==0){
            ans+=b[x].se;
        }
        d[x]++;
    }
    duyet(i+1,k,ans,dem+1,m);
    // không chọn
    for(auto x:List[i]){
        d[x]--;
        if(d[x]==0) ans-= b[x].se;
    }
    duyet(i+1,k,ans,dem,m);
}
 
int main() {
    cin >> k >> r;
    cin >> m;
    FOR(i,1,m) cin >> a[i].fi >> a[i].se;
    cin >> n;
    FOR(i,1,n) cin >> b[i].fi.fi>>b[i].fi.se>>b[i].se;
    FOR(i,1,m){
        FOR(j,1,n){
            if(check(a[i].fi,a[i].se,b[j].fi.fi,b[j].fi.se,r)){
                List[i].pb(j);
            }
        }
    }
    duyet(1,k,0,0,m);
    //FOR(i,1,m){
    //    for(auto x : List[i]) cout << x << " ";
    //   cout << endl;
    //}
    cout << sum;
    return 0;
}
