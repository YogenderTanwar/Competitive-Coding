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
vector<ll> arr[205];
ll color[205];
ll vis[205];
void dfs(ll node, ll col)
{
     vis[node]=1;
     color[node]=col;

     for(auto x: arr[node])
     {
          if(vis[x]) continue;
          dfs(x,col^1);
     }
}

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
             arr[i].clear();
             color[i]=0;
             vis[i]=0;

        }

        for(ll i=1;i<=n-1;i++)
        {
             ll u,v;
             cin>>u>>v;
             arr[u].push_back(v);
             arr[v].push_back(u);
        }

        dfs(1,1);

        for(ll i=1;i<=n;i++) 
        {
            if(color[i]==0) cout<<"2"<<" ";
            else cout<<"1"<<" ";

            
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
 