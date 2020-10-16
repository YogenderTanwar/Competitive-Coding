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
vector<ll> arr[100005];
ll vis[100005];
vector<ll> ans;
ll c[100005];
 ll root;

void dfs(ll node)
{
     vis[node]=1;
     ll cnt=0;
   //  dbg(node);


     for(auto x: arr[node])
     {
         if(vis[x]) continue;
         if(c[x]==1) cnt++;
         dfs(x);



     }

     if(c[node]==1 && cnt==(arr[node].size()-1)) 
     {
         ans.push_back(node);
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
             ll p;
             cin>>p>>c[i];
             if(p==-1)
             {
                 root=i;
                 continue;
             }
             arr[p].push_back(i);
             arr[i].push_back(p);
             



        }

        dfs(root);

        sort(all(ans));
        if(ans.empty()) cout<<"-1";
        else 
        for(auto x: ans) cout<<x<<" ";




        
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
 