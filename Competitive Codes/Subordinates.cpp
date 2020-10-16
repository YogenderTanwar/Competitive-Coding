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
vector<ll> arr[200005];
ll sz[200005];

void dfs(ll node,ll par)
{
     sz[node]=1;
     for(auto x: arr[node])
     {
          if(x==par) continue;
          dfs(x,node);
          sz[node]+=sz[x];
     }
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
        for(ll i=2;i<=n;i++)
        {
             ll ele;
             cin>>ele;
             arr[ele].push_back(i);
        }

        dfs(1,-1);

        for(ll i=1;i<=n;i++) cout<<sz[i]-1<<" ";


        
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
 