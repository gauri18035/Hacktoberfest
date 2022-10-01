#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
const int MAXN = 1000020;
const int MOD = 1299709;
 
ll qpow(ll a, ll b){
    ll tmp=a, res=1;
    while(b>0){
        if(b&1) res=res*tmp%MOD;
        tmp=tmp*tmp%MOD;
        b>>=1;
    }
    return res;
}
 

 
 
 
int main() {
    int t; cin>>t;
    while(t--) {
        vector<int> a,b;
        int n,x; cin>>n;
        for(int i=1;i<=n;i++) cin>>x, a.push_back(x);
        for(int i=1;i<=n;i++) cin>>x, b.push_back(x);
        int ans=1, constraint=0;
        for(int i=0;i<n;i++) {
            int j=(i+1)%n;
            if(b[i]<a[i]) ans=0;
            else if(b[i]>a[i]&&b[i]-b[j]>1) ans=0;
            else if(b[i]==a[i]||b[i]>a[i]&&b[i]-b[j]<=0) ;
//          else if(b[i]>a[i]&&b[i]-b[j]==1) constraint++;
        }
        if(constraint==n) ans=0;
        if(ans) cout<<"yes\n";
        else cout<<"no\n";
    }
} 