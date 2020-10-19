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
char a[205][205];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        for(ll i=1;i<=n;i++) 
        {
             for(ll j=1;j<=n;j++) cin>>a[i][j];
        }

        vector<pair<ll,ll> > ans;

        if(a[1][2]==a[2][1]) 
        {
            if(a[n-1][n]==a[1][2]) ans.push_back({n-1,n});
             if(a[n][n-1]==a[1][2]) ans.push_back({n,n-1});


        }
        else if(a[n-1][n]==a[n][n-1])
        {
            if(a[n-1][n]==a[1][2]) ans.push_back({1,2});
             if(a[n][n-1]==a[2][1]) ans.push_back({2,1});

        }
        else {
            // 1 
            if(a[1][2]=='0') ans.push_back({1,2});
             if(a[2][1]=='0') ans.push_back({2,1});

             // 0
              if(a[n][n-1]=='1') ans.push_back({n,n-1});
             if(a[n-1][n]=='1') ans.push_back({n-1,n});
        }

        cout<<ans.size()<<endl;
        for(auto x: ans ) cout<<x.F<<" "<<x.S<<endl;



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
 