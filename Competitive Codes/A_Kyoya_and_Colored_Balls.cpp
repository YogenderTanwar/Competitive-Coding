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
ll a[1005];
ll fact[1001];
ll dp[1005];


ll ncr(ll n,ll r)
{
    if(r==0) return 1;

     ll ans=1;
     ans=(fact[n]);
     //dbg(ans);

     ans=(ans%MOD * power(fact[n-r],MOD-2))%MOD;
     ans=(ans%MOD *  power(fact[r],MOD-2))%MOD;

     return ans;

}



int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        for(ll i=1;i<=n;i++) cin>>a[i];
        fact[0]=1;
        for(ll i=1;i<=1000;i++) fact[i]=(fact[i-1]*i)%MOD;

     dp[1]=1;
     ll sum=a[1];
    // cout<<ncr(5,2)<<endl;

            
            for(ll i=2;i<=n;i++)
            {
                 ll val=(sum+a[i]-1);
               

                 ll res=ncr(val , a[i]-1);
               

                 dp[i]=(dp[i-1]%MOD* res)%MOD;
                 sum+=a[i];

                 //cout<<dp[i]<<" "<<val<<" "<<res<<endl;

                 
            }

            cout<<dp[n]<<endl;











    }
return 0;
}

ll power(ll a, ll b)
 { 
  ll res = 1; 
   while (b) 
   { 
    if (b % 2) b-- , res = (res%MOD * a%MOD); 
   else b = b / 2 , a = (a%MOD * a%MOD)%MOD; 
    } 
  return res; 
 } 
 