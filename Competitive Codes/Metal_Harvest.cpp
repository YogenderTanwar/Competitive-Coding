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
     ll tt = 1; 
    cin>>tt;

      for(ll t=1;t<=tt;t++)
    {
        ll n,k;
        cin>>n>>k;

        for(ll i=1;i<=n;i++) 
        {
             ll u,v;
             cin>>u>>v;
             a.push_back({u,v});

            
        }

        sort(all(a));

       ll ans=1;
       ll reach=(a[0].F+k);

       for(ll i=0;i<n;i++)
       {
          // cout<<a[i].F<<" "<<a[i].S<<endl;

            ll val=a[i].S;
            if(reach>=val) continue;
            if(reach>=a[i].F)
            {
                 
                ll times=(val-(reach) + k-1)/(k);   
                ans+=times;
                reach+=k*times;

            }
            else{
                reach=a[i].F;

                 ll times=(val-(reach) + k-1)/(k);
                  ans+=times;
                reach+=k*times;
               
            }
          //  dbg(reach);


       }
      // dbg(reach);


       cout<<"Case "<<"#"<<t<<": "<<ans<<endl;


        a.clear();



        
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
 