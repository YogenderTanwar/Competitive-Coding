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
vector<ll> arr[200004];
ll ans[200004];
ll sz[200004];
ll re[200004];
 ll n;
void dfs(ll node,ll par)
{
    sz[node]=1;

     for(auto x: arr[node])
     {
         if(x==par) continue;
         re[node]+=1;
         dfs(x,node);
         sz[node]+=sz[x];
         re[node]+=re[x];


     }
}

void dfs2(ll node, ll par)
{
     for(auto  x: arr[node])
     {
          if(x==par) continue;
           ans[x]=(ans[node])+(n-2*sz[x]);
          dfs2(x,node);

         

     }
}


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
       
        cin>>n;
        for(ll i=1;i<n;i++)
        {
            ll u,v;

             cin>>u>>v;
             arr[u].push_back(v);
             arr[v].push_back(u);
        
        }

        dfs(1,0);
        for(ll i=1;i<=n;i++)
        {
            ans[1]+=re[i];
        }
        dfs2(1,0);

        for(ll i=1;i<=n;i++) 
        {
             cout<<ans[i]<<" ";


        }
        
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
 