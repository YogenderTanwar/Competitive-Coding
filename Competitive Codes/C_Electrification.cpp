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
ll a[200001];

int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=1;i<=n;i++) cin>>a[i];

        ll ans=inf, id=inf;
       // dbg(k);


        for(ll i=1;i<=(n-k);i++)
        {
             ll val=(a[i+k]-a[i]);
             //dbg(val);

             if(val<ans)
             {
                 ans=val;
                 id=(a[i]+a[i+k])/2;


             }
        }

        cout<<id<<endl;


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
 