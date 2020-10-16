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
ll dp[5005][4];


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        string s;
        cin>>s;

        ll n=s.size();

        ll ans=1;
        if(s[0]=='a') 
        {
            dp[0][1]=1;
            dp[0][3]=1;
             
        }
        else {
            dp[0][2]=1;
        }


        for(ll i=1;i<n;i++)
        {
            ll val1=0,val2=0,val3=0;
              if(s[i]=='a') 
        {
           val1=1;
           val3=1;
             
        }
        else {
            val2=1;
        }
            
            
                dp[i][1]=max(dp[i][1],dp[i-1][1]+val1);
                dp[i][2]=max(dp[i][2],max(dp[i-1][1],dp[i-1][2])+val2);
                dp[i][3]=max(dp[i][3],max(dp[i-1][3],dp[i-1][2])+val3);
                ans=max(ans,max(dp[i][1],max(dp[i][2],dp[i][3])));
                 
            

          //  cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
             
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
    if (b % 2) b-- , res = res * a; 
   else b = b / 2 , a *= a; 
    } 
  return res; 
 } 
 