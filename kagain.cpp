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
deque <int> dmin;

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l[30005];
        int r[30005];
        int a[30005];
        //int a[30005];
        FOR(i,1,n)cin >> a[i];
        dmin.clear();
        FOR(i,1,n){
            while(!dmin.empty()&&a[dmin.back()]>=a[i])dmin.pop_back();
            if(dmin.empty())l[i]=1;
            else l[i] = dmin.back()+1;
            dmin.push_back(i);
        }
        dmin.clear();
        FOD(i,n,1){
            while(!dmin.empty()&&a[dmin.back()]>=a[i])dmin.pop_back();
            if(dmin.empty())r[i]=n;
            else r[i] = dmin.back()-1;
            dmin.push_back(i);
        }
        int ans = 0;
        int a1 = 1e9,a2;
        FOR(i,1,n){
            if(ans<=(r[i]-l[i]+1)*a[i]){
                if(ans == (r[i]-l[i]+1)*a[i]){
                    if(a1>l[i]){
                        a1=l[i];
                        a2=r[i];
                    }
                }else{
                    ans = (r[i]-l[i]+1)*a[i];
                    a1=l[i];
                    a2=r[i];
                }
            }
        }
        cout << ans << " " << a1 << " "<< a2<<endl;
        /*FOR(i,1,n){
            cout << l[i] << " ";
        }
        cout << endl;
        FOR(i,1,n){
            cout << r[i] << " ";
        }
        cout << endl;*/
    }
}
