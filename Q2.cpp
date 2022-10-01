#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return ((b == 0) ? (a) : gcd(b, a % b));}
ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
ll f (ll n) {
  ll ans = n;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> p(n + 1, 0);
    for (ll i = 2; i <= n; ++i) p[i] = f(i);
    ll ans = 0, mod = 1e9 + 7;
    for (ll c = 1; c < n - 1; ++c) {
        for (ll d = 1; d * d <= n - c; ++d) {
            if ((n - c) % d) continue;
            if (p[(n - c) / d] > 0) ans += (p[(n - c) / d] - 0) * lcm(c, d);
            if (d * d != n - c && p[d] > 0) ans += (p[d] - 0) * lcm(c, (n - c) / d);
            ans %= mod;
        }
    }
    cout << ans;
}
