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
#define  MX 71
ll a[MX][MX];

ll dp[MX][MX][MX/2+1][MX];
ll n,m,k;

ll solve(ll r,ll c,ll cnt, ll rem)
{
    
     if(r>=n)
     {
          if(rem==0) return 0;
          else return -inf;

     }

     if(c>=m)
     {
          return solve(r+1,0,0,rem);

     }

     if(dp[r][c][cnt][rem]!=-1) return dp[r][c][cnt][rem];

     dp[r][c][cnt][rem]=solve(r,c+1,cnt,rem);

     if(cnt<m/2)
     {
         dp[r][c][cnt][rem]=max(dp[r][c][cnt][rem],solve(r,c+1,cnt+1,(rem+a[r][c])%k)+a[r][c]);
     }
    // cout<<r<<" "<<c<<" "<<cnt<<" "<<rem<<" "<<dp[r][c][cnt][rem]<<endl;


     return dp[r][c][cnt][rem];



}




int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>n>>m>>k;

        for(ll i=0;i<n;i++)
        {
             for(ll j=0;j<m;j++)
             {
                  cin>>a[i][j];

             }
        }

        cout<<solve(0,0,0,0)<<endl;



        
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
 