#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 2000000000000000000LL;

int n,q,Block_Size;
int c[1005];
int a[1005][10005];  //a[thu tu block][k]

void SqrtDecomposition(){
    for(int i = 0;i<n;i++){
        cin >> c[i];
        a[i/Block_Size][c[i]]++;
    }
}

int query(int l,int r,int k){
    int blockL,blockR;
    blockL = l/Block_Size+1;
    blockR = r/Block_Size;
    if(blockL>=blockR){
        int ans = 0;
        for(int i = l-1;i<r;i++){
            if(c[i]==k)ans++;
        }
        return ans;
    }
    int ans = 0;
    for(int i = l-1;i<blockL*Block_Size;i++){
        if(c[i]==k)ans++;
    }
    for(int i = blockR*Block_Size;i<r;i++){
        if(c[i]==k)ans++;
    }
    for(int i = blockL;i<blockR;i++){
        ans+=a[i][k];
    }
    return ans;
}


int main(){
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin >> n;
    Block_Size = sqrt(n);
    cout << "Block_Size = " << Block_Size << endl;
    SqrtDecomposition();
    cin >> q;
    while(q--){
        int a1,a2,a3;
        cin >> a1 >> a2 >> a3;
        cout << query(a1,a2,a3) << endl;
    }
	return 0;
}
