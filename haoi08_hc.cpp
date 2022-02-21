#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 2000000000000000000LL;
const long long mod = 1000000007;

//🏅 🤡
int n, m;
long long a[205][205];
long long D[205][205];
bool P[205][205];
long long ans = INF;

void solve(){
    for(int t = 1; t <= n; t++){

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                P[i][j] = false;
                D[i][j] = INF;
            }
        }

        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>> >, greater<pair<long long,pair<int,int>> >> H;
        H.push({a[t][1] ,{t,1}});

        while(!H.empty()){

            int d = H.top().fi;
            int i = H.top().se.fi;
            int j = H.top().se.se;

            H.pop();

            if(P[i][j]) continue;

            D[i][j] = d;
            P[i][j] = true;

            if(j-1 >= 1){
                if(D[i][j-1] > D[i][j] + a[i][j-1]){
                    D[i][j-1] = D[i][j] + a[i][j-1];
                    H.push({D[i][j] + a[i][j-1],{i,j-1}});
                }
            }

            if(j+1 <= m){
                if(D[i][j+1] > D[i][j] + a[i][j+1]){
                    D[i][j+1] = D[i][j] + a[i][j+1];
                    H.push({D[i][j] + a[i][j+1],{i,j+1}});
                }
            }

            if(i-1 >= 1){
                if(D[i-1][j] > D[i][j] + a[i-1][j]){
                    D[i-1][j] = D[i][j] + a[i-1][j];
                    H.push({D[i][j] + a[i-1][j],{i-1,j}});
                }
            }

            if(i+1 <= n){
                if(D[i+1][j] > D[i][j] + a[i+1][j]){
                    D[i+1][j] = D[i][j] + a[i+1][j];
                    H.push({D[i][j] + a[i+1][j],{i+1,j}});
                }
            }

        }

        for(int i = 1; i <= n; i++){
            ans = min(ans, D[i][m]);
        }

    }
}


int main(){
    faster
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    solve();
    cout << ans;
    return 0;
}

