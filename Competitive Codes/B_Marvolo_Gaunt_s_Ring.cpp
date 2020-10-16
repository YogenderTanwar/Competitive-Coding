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
ll dp[100005][4];


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,p,q,r;
        cin>>n>>p>>q>>r;
      
        
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        a[0]=0;
        // 1 p
        // 2 q
        // 3 r


        dp[1][1]=p*a[1];
        dp[1][2]=dp[1][1]+q*a[1];
        dp[1][3]=dp[1][2]+r*a[1];

        for(ll i=2;i<=n;i++)
        {
             dp[i][1]=max(dp[i-1][1],p*a[i]);
             dp[i][2]=max(dp[i-1][2],dp[i][1] + q*a[i]);
             dp[i][3]=max(dp[i-1][3],dp[i][2]+r*a[i]);

          //   cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;

        }

        cout<<dp[n][3]<<endl;


        
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
 