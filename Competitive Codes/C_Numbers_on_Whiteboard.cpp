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
vector<pair<ll,ll> > a;


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        a.clear();
        a.push_back({n-1,n});
        

        ll val=(n+n)/2;
        ll ans=0;


        for(ll i=n-2;i>=1;i--)
        {
             a.push_back({val,i});
            val=(val+1ll+i)/2;


        }

        cout<<val<<endl;
        for(auto x: a) 
        {
             cout<<x.F<<" "<<x.S<<endl;

        }


        
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
 