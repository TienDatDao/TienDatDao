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
#define MAXN 1000005
int n,k;
int a[MAXN];
deque<int> d;

int main() {
    faster
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        FOR(i,1,n)cin>>a[i];
        d.clear();
        FOR(i,1,n){
            while(!d.empty() && a[d.back()]>=a[i]) d.pop_back();   
            d.push_back(i);
            while(!d.empty() && d.front()<i-k+1) d.pop_front();
            if(i>=k) cout<<a[d.front()]<<" ";
        }
        cout<<endl;
    }
}
