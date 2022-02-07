#include <bits/stdc++.h>

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
const int N = 150000;
const int mod = 14062008;
int n, m, a[N], F[N], x,L[N],s;
queue <int> q;
vector<pair<int,int>> e;
vector<int> adj[N];
void BFS(){
    FOR(i,1,n) L[i] = -1;
    q.push(s);
    L[s]=0;
    F[s] = 1;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
			if(L[v] == -1){
                q.push(v);
                L[v] = L[u]+1;
                F[v] = F[u];
            }else if(L[v] == L[u]+1){
            	F[v] = 2;
            }
        }
    }
}

int main() {
    ll u,v;
    cin>>n>>m>>s;
    FOR(i,0,m-1){
        cin>>u>>v;
        e.push_back({u,v});
    }
    sort(e.begin(), e.end());

    FOR(i,0,m-1)
    if(i==0 || e[i] != e[i-1]){
        adj[e[i].fi].push_back(e[i].se);
    }

    BFS();
   ll dem=0;
    FOR(i,1,n){
    	if (F[i]>=2) dem++;

    }
    cout<<dem;

}
