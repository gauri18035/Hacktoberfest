#include <bits/stdc++.h>
#ifdef LOCAL
#include "txm/debug.h"
#endif
using namespace std;
using ll=long long;
const int N=100005,mod=1e9+7;
int n,k;
ll fac[N]={1};
ll qpow(ll x,ll y)
{
	ll s=1;
	while(y)
	{
		if(y&1) s=s*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return s;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	if(k>=n) cout<<qpow(2,n);
	else
	{
		ll ans=0;
		for(int i=0;i<=k;i++) ans=(ans+C(n,i))%mod;
		cout<<ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}