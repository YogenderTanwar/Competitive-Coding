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
ll dp[300005];
#define N 300000

void solve()
{
    for(ll i=1;i<=300000;i++) dp[i]=inf;
    dp[1]=2;
    for(ll i=2;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
        {
            dp[j]=min(dp[j],i+j/i);
        }

    }

    for(ll i=1;i<=N;i++)
    {
         for(ll j=1;j*j<=i;j++)
         {
              dp[i]=min(dp[i],dp[j]+dp[i-j]);
         }
    }

}

int main()
{
    fast
    ll t = 1; 
    cin >> t;
    solve();

    while (t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;
       // cout<<dp[k]<<endl;

        if(dp[k]<=n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        
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
 