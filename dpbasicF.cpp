#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define ldb long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>
ll n,w;
pair<ll,ll> a[105];
ll f[105][100005];
 
int main() {
    cin >> n >> w;
    FOR(i,1,n){
        cin >> a[i].fi;
    }
    FOR(i,1,n){
        cin >> a[i].se;
    }
    sort(a+1,a+1+n);
    FOR(i,0,w)f[0][i]=0;
    FOR(i,0,n)f[i][0]=0;
    int t;
    FOR(i,1,n){
        FOR(j,1,w){
            if(j>=a[i].fi)f[i][j] =  max(f[i-1][j],f[i-1][j-a[i].fi]+a[i].se);
            else f[i][j] = f[i-1][j];
        }
    }
    //FOR(i,1,n){
        //FOR(j,1,w){
          //  cout << f[i][j] << " ";
        //}
      //  cout << endl;
    //}
    cout << f[n][w];
	return 0;
}
//https://codeforces.com/group/8Tw3vQnae2/contest/364165/problem/F
