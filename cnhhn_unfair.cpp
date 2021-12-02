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
    int n,i=0,j=0;
    cin >> n;
    int a[n],b[n];
    FOR(i,0,n-1)cin >> a[i];
    FOR(i,0,n-1)cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int ans = 0;
    while(i<n&&j<n){
        if(b[j]>a[i]){
            ans++;
            i++;
        }
        j++;

    }
    cout << ans;
    return 0;
}
