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
#define M 10001
set<ll> s[200001];
ll ans[200001];
 
 
vector<ll> arr[200001];
 
void dfs(ll node,ll par)
{
    ll mx=0,id=0;
    ll val=*s[node].begin();
 
     for(auto x: arr[node])
     {
         if(x==par) continue;
         dfs(x,node);
         if(s[x].size()>mx) mx=s[x].size(), id=x;
          
     }
     if (!id) {ans[node] = 1; return;}
     swap(s[node],s[id]);
 
     for(auto x: arr[node])
     {
          if(x==par || x==id)  continue;
          
              for(auto z: s[x]) s[node].insert(z);
            //  s[x].clear();
 
 
          
     }
 
     s[node].insert(val);
     ans[node]=s[node].size();
 
 
 
 
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
       for(ll i=1;i<=n;i++)
       {
            ll ele;
            cin>>ele;
          s[i].insert(ele);
 
       }
 
       for(ll i=1;i<n;i++)
       {
           ll u,v;
           cin>>u>>v;
           arr[u].push_back(v), arr[v].push_back(u);
       }
 
        dfs(1,0);
 
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