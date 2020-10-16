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
ll deg[105];





int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        vector<ll> a(n);

        for(ll i=0;i<n;i++) cin>>a[i];
        clr(deg);



       vector<ll> in;
        ll tot=0;


     for(ll i=0;i<a.size();i++)
     {
         for(ll j=0;j<i;j++) if(a[j]>a[i]) deg[i]++;
         for(ll j=i+1;j<n;j++) if(a[j]<a[i]) deg[i]++;
         
     }
     ll sum=0;

     for(ll i=0;i<n;i++) sum+=deg[i];
     


     ll dp[n+1][sum+5]; 
     clr(dp);
     //dbg(sum);


     for(ll i=0;i<n;i++) dp[i][0]=1;

     dp[0][deg[0]]=1;

     for(ll i=1;i<n;i++) 
     {
          for(ll j=1;j<=sum;j++) 
          {
              dp[i][j]=dp[i-1][j];
              if(j<deg[i]) continue;
            //  cout<<i<<" "<<j<<endl;

              dp[i][j]=dp[i][j]|dp[i-1][j-deg[i]];
               
          }
     }
     

     if(dp[n-1][sum/2]) cout<<"YES"<<endl;
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
 