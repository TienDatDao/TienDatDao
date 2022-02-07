#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define X first
#define Y second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n,q,s,f,ans;
vector<pair<int,int>> a[1005];
pair<int,int> l[1005];
bool check[1005];

void DFS(int u){
    check[u]=false;
    for(int i = 0;i<a[u].size();i++){
            int v = a[u][i].X;
            int c = a[u][i].Y;
        if(check[v]){
            l[v]={u,c};
            DFS(v);
        }
    }
}

void trace(){
    ans = 0;
    while(f!=s){
        ans+=l[f].Y;
        f=l[f].X;
    }
}

int main(){
    faster
	cin >> n >> q; 
	int x,y,z;
	for(int i = 1;i<n;i++){
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
	}
	while(q--){
        for(int i = 1;i<=n;i++)check[i]=true;
        cin >> s >> f;
        DFS(s);
        trace();
        cout << ans << endl;
	}
	return 0;
}
