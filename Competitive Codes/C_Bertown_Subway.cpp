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
ll vis[100005];
ll cnt=0;
void dfs(ll node)
{
     vis[node]=1;
     cnt++;
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
        ll n;
        cin>>n;

        for(ll i=1;i<=n;i++)
        {
             ll u;
             cin>>u;
             arr[i].push_back(u);
        }
        vector<ll> ans;

        for(ll i=1;i<=n;i++)
        {
             if(vis[i]) continue;
             dfs(i);
             ans.push_back(cnt);
             cnt=0;

        }

        sort(all(ans),greater<ll> ());

        ll res=0;
        if(ans.size()==1) cout<<ans[0]*ans[0];
        else{
             res=(ans[0]+ans[1])*(ans[0]+ans[1]);
             for(ll i=2;i<ans.size();i++) res+=(ans[i]*ans[i]);
             cout<<res<<endl;

             
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
 