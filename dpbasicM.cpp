#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define X first
#define Y second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n,m;
int a[1005];
int dp[105][1005];
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++)cin >> a[i];
    for(int i = 1;i<=n;i++){
        dp[1][i] = 0;
        dp[0][i] = 0;
        for(int j = 1;j<i;j++){
            dp[1][i] += abs(a[i]-a[j]);
        }
    }
    for(int i = 2;i<=m;i++){     // hòm thư thứ i
        for(int j = i;j<=n;j++){     // đặt hòm thư thứ i ở vị trí j
            dp[i][j] = 1e9;
            for(int t = i-1;t<j;t++){    // đặt hòm thư thứ i - 1 ở vị trí t
                int p = dp[i-1][t];
                for(int u = t+1;u<j;u++){     // tỉnh tổng phí trên đường từ hòm thư thứ i-1 đến i
                    p += min(abs(a[u]-a[j]),abs(a[u]-a[t]));
                }
                dp[i][j] = min(dp[i][j],p);
 
            }
            //cout << dp[i][j] << " " << i << " " << j << endl;
        }
    }
    int ans = 1e9;
    for(int i = m;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            dp[m][i] += abs(a[j]-a[i]);
        }
        ans = min(ans,dp[m][i]);
    }
    cout << ans;
	return 0;
}
//https://codeforces.com/group/8Tw3vQnae2/contest/364165/problem/M
