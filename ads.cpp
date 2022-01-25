#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define fi first
#define se second
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>
int n,m;
vector<int> a[2005];
bool Free[2005];

void DFS(int u){
    Free[u] = false;
    int c = a[u].size();
    for(int i = 0;i<=c-1;i++){
        int v = a[u][i];
        if(Free[v]){
            DFS(v);
        }
    }
}

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i = 1;i<=n;i++)Free[i]=true;
    int j = 0;
    for(int i = 1;i<=n;i++){
        if(Free[i]){
            DFS(i);
            j++;
        }
    }
    cout << m-n+j;
	return 0;
}
