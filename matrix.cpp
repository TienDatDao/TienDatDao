#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define matrix vector<vector<long long>>
const long long INF = 2000000000000000000LL;
const long long mod = 10;

//🏅 🤡

matrix nhanmatran(matrix a,long long n, long long m,matrix b, long long q, long long p){
    matrix c(n,vector<long long>(p,0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < p; j++){
            c[i][j] = 0;
            for(ll v = 0; v < m; v++){
                c[i][j] += b[v][j]*a[i][v];
                c[i][j]%=mod;
            }
        }
    }
    return c;
}

matrix add(matrix a,matrix b,ll n){
    matrix c(n,vector<long long>(n,0));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j< n;j++){
            c[i][j] = (a[i][j] + b[i][j]) % mod;
        }
    }
    return c;
}

matrix power(matrix a, long long n, long long b){
    if(b==1) return a;
    else{
        matrix s = power(a,n,b/2);
        if(b&1) return nhanmatran(nhanmatran(s,n,n,s,n,n),n,n,a,n,n);
        else return nhanmatran(s,n,n,s,n,n);
    }
}

matrix pow(matrix a,ll n,ll b){
    if(b == 1)return a;
    else {
        matrix tmp = pow(a,n,b/2);
        if(b & 1)return add(add(tmp,nhanmatran(tmp,n,n,power(a,n,b/2),n,n),n),power(a,n,b),n);
        else return add(tmp,nhanmatran(tmp,n,n,power(a,n,b/2),n,n),n);
    }
}


signed main(void) {
    //freopen("sumlr.inp","r",stdin);
    //freopen("main.out","w",stdout);
    faster

    ll n,k;
    cin>>n>>k;
    matrix a(n,vector<long long>(n,0));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cin>>a[i][j];
        }
    }
    matrix asmr = pow(a,n,k);
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            cout<<asmr[i][j] % mod<<" ";
        }
        cout<<"\n";
    }

    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	return 0;
}
