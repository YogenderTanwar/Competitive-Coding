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
#define N 200005
vector<ll> arr[N];
ll vis[N];
 ll flag=0;
 void  dfs(ll node)
 {
      vis[node]=1;
      if(arr[node].size()!=2) flag=1;
      for(auto x: arr[node])
      {
           if(vis[x]) continue;
           dfs(x);
      }
 }


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
             
        }

        ll ans=0;
       


        for(ll i=1;i<=n;i++)
        {
             if(vis[i]) continue;
             dfs(i);
             if(flag==0) ans++;

             flag=0;

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
 