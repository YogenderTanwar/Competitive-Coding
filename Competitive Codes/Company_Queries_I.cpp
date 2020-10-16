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
ll dp[200005][20];
ll parent[200005],depth[200005];
 ll n;
void dfs(ll node,ll par)
{
    depth[node]=depth[par]+1;
    parent[node]=par;
   // cout<<node<<" "<<par<<endl;



    for(auto x: arr[node])
    {
         if(x==par) continue;
         dfs(x,node);

    }

     
}

void build()
{
     for(ll i=1;power(2,i)<=n;i++)
     {
         for(ll j=1;j<=n;j++)
         {
              ll val=dp[j][i-1];
              if(val==-1) continue;
              val=dp[val][i-1];

              dp[j][i]=val;

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
        ll q;
       

        cin>>n;
         cin>>q;

        for(ll i=2;i<=n;i++)
        {
             ll ele;
             cin>>ele;
             arr[ele].push_back(i);
            // arr[i].push_back(ele);


        }
        depth[0]=-1;


        dfs(1,0);
        memset(dp,-1,sizeof dp);
        parent[1]=-1;


        for(ll i=1;i<=n;i++) dp[i][0]=parent[i];


        build();

       while(q--)
       {
            ll node,k;
            cin>>node>>k;
            ll flag=0;
            
            for(ll i=0;i<20;i++)
            {
                 if(k&(1<<i))
                 {
                      node=dp[node][i];
                      if(node==-1)
                      {
                          break;
                      }
                 }
            }

            cout<<node<<endl;
            
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
 