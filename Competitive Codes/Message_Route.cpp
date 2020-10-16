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
ll vis[100004];
ll choice[100004];
ll dis[100004];
void bfs(ll n)
{
    queue<ll> q;
    q.push(1);
    vis[1]=1;
    choice[1]=-1;

    
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        vis[node]=1;


        for(auto x: arr[node])
        {
             if(vis[x]) continue;
             dis[x]=dis[node]+1;
             choice[x]=node;
              vis[x]=1;


             q.push(x);

        }

         
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

        bfs(n);

        if(dis[n]==0) 
        {
            cout<<"IMPOSSIBLE";
        }
        else {
            cout<<dis[n]+1<<endl;
             vector<ll> ans;
             ll i=n;
             ans.push_back(n);


             while(choice[i]!=-1) 
             {
                 ans.push_back(choice[i]);
                 i=choice[i];
             }
             reverse(all(ans));
             for(auto x : ans) cout<<x<<" ";

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
 