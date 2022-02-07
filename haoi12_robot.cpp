#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define X first
#define Y second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n,m;
bool check[105][105];
pair<int,int> start,finish;
pair<pair<int,int>,int> trace[105][105];
queue <pair<int,int>> q;
vector<pair<int,int>> ans;
void bfs(){
    while(!q.empty()){
        pair<int,int> u = q.front();
        if(check[u.X+1][u.Y]){
            q.push({u.X+1,u.Y});
            check[u.X+1][u.Y] = false;
            trace[u.X+1][u.Y] = {{u.X,u.Y},trace[u.X][u.Y].Y+1};
        }
        if(check[u.X-1][u.Y]){
            q.push({u.X-1,u.Y});
            check[u.X-1][u.Y] = false;
            trace[u.X-1][u.Y] = {{u.X,u.Y},trace[u.X][u.Y].Y+1};
        }
        if(check[u.X][u.Y+1]){
            q.push({u.X,u.Y+1});
            check[u.X][u.Y+1] = false;
            trace[u.X][u.Y+1] = {{u.X,u.Y},trace[u.X][u.Y].Y+1};
        }
        if(check[u.X][u.Y-1]){
            q.push({u.X,u.Y-1});
            check[u.X][u.Y-1] = false;
            trace[u.X][u.Y-1] = {{u.X,u.Y},trace[u.X][u.Y].Y+1};
        }
        q.pop();
    }
}

void out(int x,int y){
    cout << trace[x][y].Y+1 << endl << start.X << " " << start.Y << endl;
    pair<int,int> f;
    f.X = x;
    f.Y = y;
    while(f.X != start.X || f.Y!=start.Y){
        ans.push_back(f);
        int c = f.X;
        int d = f.Y;
        f.X = trace[c][d].X.X;
        f.Y = trace[c][d].X.Y;
    }
    for(int i = ans.size()-1;i>=0;i--){
        cout << ans[i].X << " " << ans[i].Y << endl;
    }
}

int main(){
    faster
    cin >> n >> m;
    for(int i = 0;i<=n+1;i++)for(int j = 0;j<=m+1;j++)check[i][j]=false;
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)check[i][j]=true;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int x;
            cin >> x;
            if(x==1)check[i][j]=false;
            if(x==2)start = {i,j};
            if(x==3)finish = {i,j};
        }
    }
    q.push(start);
    bfs();
    out(finish.X,finish.Y);
	return 0;
}
