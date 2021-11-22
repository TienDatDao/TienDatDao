#include <bits/stdc++.h>
using namespace std;
 
int n,l,sum, a[21], d[21], x[101], dem;
 
void print(){
	if(dem == 1000) return;
	dem++;
	for(int i = 1; i <=l;i++) cout<<x[i]<<" ";
	cout<<endl;
}
 
void duyet(int i, int tong){
	if(dem == 1000) return;
	if(i>l){
		if(tong==sum){
			print();
		}
		return;
	}
	//TH1: k bán nhà thứ i
	//i ko phải nhà đầu tiên
	//số chỗ cần điền <= số chỗ trống còn lại
	if(i > 1 && sum-tong <= l-i && dem < 1000){
		duyet(i+1, tong);
	}
	//TH2: bán dãy nhà từ vị trí i->i+a[j]-1 cho người thứ j
	for(int j = 1; j<=n;j++)
		if(d[j]==0 && dem < 1000){
			for(int k = i; k <= i+a[j]-1; k++) x[k] = j;
			d[j] = 1;
			duyet(i+a[j], tong+a[j]);
			d[j] = 0;
			for(int k = i; k <= i+a[j]-1; k++) x[k] = 0;
		}
}
 
int main() {
	cin>>l>>n;
	sum = 0;
	for(int i = 1; i <=n; i++){
		cin>>a[i];
		sum+=a[i];
	} 
	duyet(1,0);
	return 0;
}
