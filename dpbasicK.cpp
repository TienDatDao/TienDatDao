#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define ldb long double
#define X first
#define Y second
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>
void read(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
ll n,m,x,y;
pair<pair<ll,ll>,ll> pad[100005];    //pad[i].X.Y là tọa độ cạnh thứ nhất
ll dp[10005][2];                   //pad[i].X.X là tọa độ y
                                //pad[i].Y là tọa độ cạnh thứ 2
                                // 0 là trái, 1 là phải
bool check(ll x,ll HPI,ll LPJ,ll RPJ,ll HPJ){
    if(x<=RPJ&&x>=LPJ&&HPI-HPJ<=m&&HPI-HPJ>=0){
        return true;
    }else return false;
}
 
 
int main(){
    read();
    ll LPI,LPJ,RPI,RPJ,HPI,HPJ,sum;
    cin >> n >> x >> y >> m;
    FOR(i,1,n){
        cin >> pad[i].X.Y >> pad[i].Y >> pad[i].X.X;
    }
    sort(pad+1,pad+1+n);
    FOR(i,1,n){
        LPI = pad[i].X.Y;
        RPI = pad[i].Y;
        HPI = pad[i].X.X;
        // đầu bên phải
        sum = 0;
        FOD(j,i-1,0){
            LPJ = pad[j].X.Y;
            RPJ = pad[j].Y;
            HPJ = pad[j].X.X;
            if(j==0){
                if(HPI<=m){
                    dp[i][1] = HPI;
                }else{
                    dp[i][1] = 1e9;
                }
            }
            else{
                if(check(RPI,HPI,LPJ,RPJ,HPJ)){
                    dp[i][1] = min(dp[j][0]+RPI-LPJ,dp[j][1]+RPJ-RPI)+HPI-HPJ;
                    break;
                }
            }
        }
        // đầu bên trái
        FOD(j,i-1,0){
            LPJ = pad[j].X.Y;
            RPJ = pad[j].Y;
            HPJ = pad[j].X.X;
            if(j==0){
                if(HPI<=m){
                    dp[i][0] = HPI;
                }else{
                    dp[i][0] = 1e9;
                }
            }
            else{
                if(check(LPI,HPI,LPJ,RPJ,HPJ)){
                    dp[i][0] = min(dp[j][0]+LPI-LPJ,dp[j][1]+RPJ-LPI)+HPI-HPJ;
                    break;
                }
            }
        }
    }
    //FOR(i,1,n){
    //    cout << dp[i][0] << " " << dp[i][1] << endl;
    //}
    FOD(j,n,1){
        LPJ = pad[j].X.Y;
        RPJ = pad[j].Y;
        HPJ = pad[j].X.X;
        if(check(x,y,LPJ,RPJ,HPJ)){
            cout << min(dp[j][0]+x-LPJ,dp[j][1]+RPJ-x)+y-HPJ;
            exit(0);
        }
    }
    return 0;
}
//https://codeforces.com/group/8Tw3vQnae2/contest/364165/problem/K
