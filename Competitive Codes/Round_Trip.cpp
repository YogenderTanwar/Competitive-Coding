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
vector<ll> arr[100004];
ll color[100004];
ll parent[100004];

int cycle_start,cycle_end;

bool dfs(ll node,ll par)
{
  
    parent[node]=par;
    color[node]=1;


    for(auto x: arr[node])
    {
         if(x==par) continue;
         if(color[x]==0)
         {
             parent[x]=node;

             if(dfs(x,node)) return true;


         }
         else {
             cycle_start=x;
             cycle_end=node;
             return true;
             
         }

    }
    color[node]=2;
    return false;
    



}



int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        memset(parent,-1,sizeof parent);
        cycle_start=-1;


        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=m;i++)
        {
             ll u,v;
             cin>>u>>v;
             arr[u].push_back(v);
             arr[v].push_back(u);

        }

        for(ll i=1;i<=n;i++)
        { 
            if(color[i]==0 && dfs(i,parent[i])) break;
        }
    

        if(cycle_start==-1)
        {
             cout<<"IMPOSSIBLE";
        }
        else {
          


            vector<ll> ans;

            ans.push_back(cycle_start);
            ll temp=cycle_start;

           for (int v = cycle_end; v != cycle_start; v = parent[v])
            ans.push_back(v);
             ans.push_back(temp);
             cout<<ans.size()<<endl;


              for(auto x: ans) cout<<x<<" ";

              


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
 