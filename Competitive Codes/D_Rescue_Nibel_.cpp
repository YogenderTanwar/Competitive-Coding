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
#define MOD 998244353 
const ll inf = 1e18;
ll power(ll a, ll b);


ll fact[300005];
ll inverse(ll n)
{
     return power(n,MOD-2);
}

ll nCr(ll n,ll k)
{
     if(k>n) return 0;

     return (fact[n]%MOD*(inverse(fact[k]))%MOD*(inverse(fact[n-k])))%MOD;



}

int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    fact[0]=1;
    for(ll i=1;i<=300000;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
   
    }
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll> > events;

        for(ll i=1;i<=n;i++)
        {
             ll l,r;
             cin>>l>>r;
             events.push_back({l,-i});
             events.push_back({r,i});
        }

        sort(all(events));


        ll ans=0;
        ll curr=0;


        for(auto x: events)
        {
             if(x.second<0)
             {
                 curr++;

                  
             }
             else {
                 curr--;
                 //dbg(curr);
                 ans=(ans + nCr(curr,k-1))%MOD;
                // dbg(ans);

             }
        }

        cout<<ans<<endl;


       






        
    }
return 0;
}

ll power(ll a, ll b)
 { 
  ll res = 1; 
   while (b) 
   { 
    if (b % 2) b-- , res = (res%MOD * a%MOD); 
   else b = b / 2 , a =(a%MOD * a%MOD)%MOD; 
    } 
  return res; 
 } 
 