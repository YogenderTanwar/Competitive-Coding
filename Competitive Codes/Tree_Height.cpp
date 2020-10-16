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
vector<pair<ll,ll> > arr[300004]; // node, weight
ll sub[300004];
ll val[300004];

ll dp[300004];
 ll n;

void  dfs(ll node, ll par)
{
    
    sub[node]=1;

    
     for(auto x: arr[node])
     {
         if(x.F==par) continue;
        ll child=x.F;
        ll w=x.S;
        val[child]+=val[node]+w;
        dfs(child, node);
        sub[node]+=sub[child];
     }

    

}

void dfs2(ll node, ll par )
{

   for(auto x: arr[node])
     {
         if(x.F==par) continue;
        ll child=x.F;
        ll w=x.S;
       dp[child]=dp[node]+(n-2*sub[child])*w;
       dfs2(child,node);
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

        for(ll i=1;i<=n-1;i++)
        { 
                 ll u,v,weight;
                 cin>>u>>v>>weight;
                 arr[u].push_back({v,weight});
                 arr[v].push_back({u,weight});

        }

        dfs(1,0);
        for(ll i=1;i<=n;i++) 
        {
             dp[1]+=val[i];
        }
        dfs2(1,-1);


        for(ll i=1;i<=n;i++) {
          // cout<<val[i]<<" "<<sub[i]<<endl;

          cout<<dp[i]<<" ";
          


          
        }
        cout<<endl;



        
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
 