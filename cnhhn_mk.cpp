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
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")-
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
map <string,int> dem;
long long ans = 0;
int t;
string s[20005];
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    cin >> t;
    FOR(i,1,t){
        cin >> s[i];
        dem[s[i]]++;
    }
    FOR(x,1,t){
        map<string,int> mp;
        FOR(i,0,s[x].size()-1){
            FOR(j,0,s[x].size()-i+1){
                string m = s[x].substr(i,j);
                if(!mp[m]){
                    if(m==s[x]) ans+= dem[m]-1;
                    else ans += dem[m];
                    mp[m] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
