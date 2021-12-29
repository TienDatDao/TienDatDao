#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define MAXN 100005

int n, p;
int id[MAXN];
deque<int> dmin, dmax;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>p;
    for(int i = 1; i <=n; i++) cin>>id[i];
    int maxlen = 1, pos = 0;
    for(int i = 1; i <= n; i++){
        while(!dmin.empty() && id[dmin.back()]>id[i]) dmin.pop_back();  
        dmin.push_back(i);
        while(!dmax.empty() && id[dmax.back()]<id[i]) dmax.pop_back();
        dmax.push_back(i);
        while(!dmin.empty() && !dmax.empty()){
            if(id[dmax.front()] - id[dmin.front()]<=p){
                maxlen = max(maxlen, i-pos);
                break;
            }
            if (dmin.front() > dmax.front()){
                pos = dmax.front();
                dmax.pop_front();
            }else{
                pos = dmin.front();
                dmin.pop_front();
            }
        }
    }

    cout<<maxlen;
    return 0;
}
