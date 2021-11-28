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

umap<int,int> s;
int a[100000];
ll ans;
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int m,n,k,x;
    cin >> m >> n >> k;
    FOR(i,1,n*m){
        cin >> x;
        s[x]++;
    }
    int i = 0;
    for(auto y:s){
        i++;
        a[i]=y.se;
    }
    sort(a+1,a+1+i);
    FOD(j,i,i-k+1){

       ans+=a[j];
    }
    cout << ans;
}
