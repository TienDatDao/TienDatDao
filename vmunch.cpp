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

char a[1005][1005];
bool b[1005][1005];
queue <pair<int,int>> s;
int L[1005][1005];
void dfs(int i, int j){
    s.pop();
    if(a[i][j]=='C'){
        cout << L[i][j];
        exit(0);
    }
    if(b[i][j+1]){s.push({i,j+1});
    L[i][j+1]=L[i][j]+1;
    b[i][j+1]=false;
    }
    if(b[i+1][j]){s.push({i+1,j});
    L[i+1][j]=L[i][j]+1;
    b[i+1][j]=false;
    }
    if(b[i][j-1]){s.push({i,j-1});
    L[i][j-1]=L[i][j]+1;
    b[i][j-1]=false;
    }
    if(b[i-1][j]){s.push({i-1,j});
    L[i-1][j]=L[i][j]+1;
    b[i-1][j]=false;
    }
    int a1 = s.front().fi;
    int a2 = s.front().se;
    b[a1][a2]=false;
    dfs(a1,a2);
}

int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n+1)FOR(j,0,n+1){a[i][j]='*';b[i][j]=false;}
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> a[i][j];
            if(a[i][j]=='.'||a[i][j]=='C')b[i][j]=true;
        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
            if(a[i][j]=='B'){
                b[i][j]=false;
                s.push({i,j});
                dfs(i,j);
            }
        }
    }
	return 0;
}
