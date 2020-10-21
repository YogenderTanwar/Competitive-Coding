#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf = 1e18;
ll power(ll a, ll b);
ll fact(ll n)
{
     ll fact=1;

     for(ll i=2;i<=n;i++) fact=fact*i;
     return fact;

}

int main()
{
    fast
    ll t = 1; 
   // cin >> t;
    while (t--)
    {


        ll n;
        cin>>n;

      ll ans=fact(n)/(fact(n/2) * fact(n/2));
      ans=ans*(fact(n/2-1)*fact(n/2-1));

      cout<<ans/2<<endl;


        
    }
return 0;
}

ll power(ll a, ll b)
 { 
  ll res = 1; 
   while (b) 
   { 
    if (b % 2) b-- , res = res * a; 
   else b = b / 2 , a *= a; 
    } 
  return res; 
 } 
 