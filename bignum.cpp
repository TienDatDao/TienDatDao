#include <bits/stdc++.h>
 
using namespace std;
 
#define ump unordered_map
#define MAXN 30005
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
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, r, l) for (ll i = r; i >= l; i--)
#define vecll vector<long long>
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);
#define oo 1e18
#define pii pair<ll,ll>
#define ppi pair<ll,pii>
// Hoèn thánh thiện 
string phepcong(string a,string b) {
    string c="";
    while(a.size()!=b.size()){
        if(a.size()>b.size()) b="0"+b;
        else a="0"+a;
    }
    ll mem = 0;
    for (int i = a.size()-1; i>=0; i--){
        ll sum = mem + a[i]-'0' + b[i]-'0';
        c = char(sum%10+'0') +c;
        mem = sum/10;
    }
    if(mem > 0) c="1"+c;
    return c;
}
string pheptru(string a, string b) {
	string c = "";
	while(a.size()!=b.size()){
        if(a.size()>b.size()) b="0"+b;
        else a="0"+a;
	}
	ll sum = 0;
	ll nho = 0;
	for (ll i = a.size() - 1; i >= 0; i--) {
		sum = a[i] - b[i] - nho;
		if (sum < 0) {
			sum += 10;
			nho = 1;
		}
		else nho = 0;
		c = char(sum + '0') + c;
	}
	while (c[0] == '0'&&c.size()>1) {
		c.erase(0,1);
	}
	return c;
}
string nhannho(string a, ll x){
	string s=""; int nho=0;int d;
	for(int i=a.size()-1;i>=0;i--){
		d= (a[i]-'0')*x+ nho;
		nho = d/10;
		s= char(d%10+'0')+ s;
	}
	if(nho>0){
	    s= to_string(nho) +s;
	}
	return s;
}
 
string nhansolon(string a, string b){
	string s="",tmp="";
	int m=-1;
	for(int i=b.size()-1;i>=0;i--){
		m++;
		tmp = nhannho(a,b[i]-'0');
		for(int i=1;i<=m;i++){
			tmp = tmp +'0';
		}
		s= phepcong(s,tmp);
	}
	return s;
}
string chianho(string a,int b){
    int s,nho=0;
    string c="";
    for(int i=0;i<a.size();i++){
        nho=nho*10+a[i]-48;
        s=nho/b;//s là thương trong từng đoạn
        nho=nho%b;
        c=c+char(s+48);
    }
    while(c.size()>1&&c[0]=='0') c.erase(0,1);
    return c;
 
}
 
string chianholaydu(string a,ll b){
    ll s,nho=0;
    string c="";
    for(int i=0;i<a.size();i++){
        nho=(nho*10+a[i]-48)%b;
    }
    string l =to_string(nho);
    return l;
 
}
ll power(ll a,string b, ll mod)
{
    if (b == "0") 
        return 1;
    ll t = power(a,chianho(b,2), mod);         
    t = (t*t) % mod; 
    if (chianholaydu(b,2) == "1") 
        t = (t * a) % mod;
    return t;
} 
 
ll MOD=1e9+7;
int main(){
    string b;
    ll a;
    cin>>a>>b;
    cout<<power(a,b,MOD);
}
