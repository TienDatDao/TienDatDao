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
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
long long ans = 0;

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    long long n,k;
    cin >> n >> k;
    if(k==1){
        cout << 1;exit(0);
    } else if(k==2){
        cout << (n-1)/2;
        exit(0);
    } else if(k==3){
        FOR(i,1,n/3){
            FOR(j,i+1,2*n/3){
                if(n-i-j>j)ans++;
            }
        }
    } else if(k==4){
        FOR(i,1,n/4){
            FOR(j,i+1,n/2){
                long long a = n-i-j;
                if(a%2==0)a = a/2-1;
                else a = a/2;
                //cout << "_"<<a<<endl;
                if(a-j>0)ans+= a-j;
            }
        }
    }
    cout << ans;
}
