#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
#define MAX 1000005
int l1,l2,l3,c1,c2,c3,n;
int S,F;
int a[MAX],f[MAX];
signed main(){
	faster
	cin>> l1>> l2>> l3>> c1>> c2>> c3;
	cin>>n;
	cin>>S>>F;
if(S>F) swap(S,F);
	for(int i=2;i<=n;i++){
		cin>> a[i];
	}
	f[S]=0;
	for(int i=S+1;i<=F;i++){
		f[i]= 1e18;
		for(int j=i-1;j>=S;j--){
			if(a[i]-a[j]>l3) break;
			int cp;
			if(a[i]-a[j]>0 && a[i]-a[j]<=l1) cp= c1;
			if(a[i]-a[j]>l1&& a[i]-a[j]<=l2) cp= c2;
			if(a[i]-a[j]>l2&& a[i]-a[j]<=l3) cp= c3;
			f[i]= min(f[i],f[j]+ cp);
		}
	}
	cout<< f[F];
    return 0;
}
//https://codeforces.com/group/8Tw3vQnae2/contest/364165/problem/A
