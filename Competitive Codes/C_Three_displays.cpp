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


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll a[n+1],c[n+1];
        ll dp[n+1];

        for(ll i=1;i<=n;i++) cin>>a[i],dp[i]=inf;

        for(ll i=1;i<=n;i++) cin>>c[i];
        ll ans=inf;


        for(ll i=1;i<=n-1;i++)
        {
             for(ll j=i+1;j<=n;j++)
             {
                 if(a[j]>a[i]) 
                 {
                     dp[j]=min(dp[j],c[i]+c[j]);
                 }
                  
             }
        }


        for(ll i=2;i<n;i++)
        {
            if(dp[i]==inf) continue;

            for(ll j=i+1;j<=n;j++)
            {
                 if(a[j]>a[i]) 
                 {
                     ans=min(ans,dp[i]+c[j]);
                 }
            } 
             
        }

        if(ans==inf) cout<<"-1";
        else cout<<ans<<endl;

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
 