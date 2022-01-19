#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define ldb long double
#define fi first
#define se second
#define pb push_back
#define sz size
#define endl "\n"
#define sp setprecision
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define vecll vector<long long>


struct Node {
    ll lazy; // giá trị T trong phân tích trên
    ll val; // giá trị lớn nhất.
} nodes[MAXN * 6];

void down(ll id) {
    ll t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        // Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
        // giá trị lazy propagation. Như vậy sẽ tránh sai sót.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    ll mid = (l + r) / 2;

    down(id); // đẩy giá trị lazy propagation xuống các con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

void tao(ll id, ll l, ll r, ll i, ll val){
    if(i<l||i>r)return;
    else if(l==r){
        nodes[id].val = val;
    }
    else{
        ll mid = (l+r)/2;
        tao(id*2,l,mid,i,val);
        tao(id*2+1,mid+1,r,i,val);
        nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
    }
}
ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l || r < u) {
        return -1000000000;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    ll mid = (l + r) / 2;
    down(id); // đẩy giá trị lazy propagation xuống các con

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
    // Trong các bài toán tổng quát, giá trị ở nút id có thể bị thay đổi (do ta đẩy lazy propagation
    // xuống các con). Khi đó, ta cần cập nhật lại thông tin của nút id dựa trên thông tin của các con.
}
int main() {
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    ll a[100005];
    FOR(i,1,n){
        cin >> a[i];
        tao(1,1,n,i,a[i]);
    }
    ll f[100005];
    f[1] = a[1];
    if(f[1]<0)f[1]=0;
    tao(1,1,n,1,f[1]);
    FOR(i,2,n){
        ll x = i-k;
        if(x<1)x = 1;
        f[i] = get(1,1,n,x,i-1)+a[i];
        if(f[i]<0)f[i]=0;
        tao(1,1,n,i,f[i]);
    }
    cout << get(1,1,n,1,n);
	return 0;
}
