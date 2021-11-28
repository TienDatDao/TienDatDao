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
ll n,m,res;
int k[10000];
int h[10000];
bool order(int i,int j){
    return i>=j;
}

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    cin >> n >> m;
    FOR(i,1,n) cin >> k[i];
    sort(k+1,k+n+1,order);
    fill(h+1,h+n+1,0);
    int dem = n;
    res = 0;
    while(dem>0){
        res++;
        int sum = 0;
        FOR(j,1,n){
            if(h[j]==0&&sum+k[j]<=m){
                sum=sum+k[j];
                h[j]=1;
                dem--;
            }
        }
    }
    cout << res;
}
