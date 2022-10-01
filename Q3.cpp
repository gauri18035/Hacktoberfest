//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <stack>
#include <deque>
#include <iterator>
#include <tuple>
#include <iomanip>
#include <valarray>
#include <limits>
#include <sstream>
#include <fstream>
#include <cassert>
#include <functional>
#include <numeric>
#define in insert
#define pb push_back
#define mp make_pair
#define int long long
#define ll long long
#define fi first
#define double long double
#define se second
#define endl '\n'
#define pii pair<int,int>
#define pdd pair<double,double>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define MAXN  100005
#define all(v) v.begin(),v.end()
using namespace std;
const double pi=3.141592653589793238;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int spf[MAXN];
int fac[MAXN];
int inv[MAXN];
int pp[MAXN];
int dis[MAXN];
void sieve()//sieve
{
   spf[1] = 1;
   for (int i=2; i<MAXN; i++)
       spf[i] = i;
   for (int i=4; i<MAXN; i+=2)
       spf[i] = 2;
   for (int i=3; i*i<MAXN; i+=2)
   {
       if (spf[i]==i)
       {
           for (int j=i*i; j<MAXN; j+=i)
               if (spf[j]==j)
                   spf[j]=i;
       }
   }
}//sieve ends
map<int,int> getfactor(int a)//factor prime
{
   map<int,int> m;
   while(a>1)
   {
       m[spf[a]]++;
       a/=spf[a];
   }
   return m;
}//prime factor ends
int power(int x,int y,int p)
{
   int res = 1;
   if (x == 0||y < 0)
       return 0;
    x = x%p;
   while (y > 0)
   {
       if (y & 1)
           res = (res*x)% p;
       y = y>>1;
       x = (x*x)%p;
   }
   return res;
}
int gcd(int a, int b)
{
   if (a == 0)
       return b;
   return gcd(b % a, a);
}
int inverse(int a, int p)
{
   return power(a, p-2, p);
}
void getfac()
{
    fac[0]=1;
    inv[0]=inverse(fac[0],mod);
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        inv[i]=inverse(fac[i],mod);
    }
}
int ncr(int n, int r, int p)
{
   if(r>n)
       return 0;
   return (fac[n]*inv[r] % p *
           inv[n-r] % p) % p;
}
long long phi[100000+1];
void computeTotient(int n)
{
    // Create and initialize an array to store
    // phi or totient values
    for (int i=1; i<=n; i++)
        phi[i] = i; // indicates not evaluated yet
                    // and initializes for product
                    // formula.
    // Compute other Phi values
    for (int p=2; p<=n; p++)
    {
        // If phi[p] is not computed already,
        // then number p is prime
        if (phi[p] == p)
        {
            // Phi of a prime number p is
            // always equal to p-1.
            phi[p] = p-1;
  
            // Update phi values of all
            // multiples of p
            for (int i = 2*p; i<=n; i += p)
            {
            // Add contribution of p to its
            // multiple i by multiplying with
            // (1 - 1/p)
            phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
    phi[1]=0;
}
vector<vector<int> >v;

signed main()
{
    fast
    int test=1;
    sieve();
    v.resize(100001);
    computeTotient(100000);
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            v[j].pb(i);
    //cin>>test;
    while(test--)
    {
        solve();
    }
}
