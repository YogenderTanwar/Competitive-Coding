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
ll dis[505][505];

void floyd(ll n)
{

    for(ll i=1;i<=n;i++)
    {
         for(ll s=1;s<=n;s++)
         {
              for(ll e=1;e<=n;e++)
              {
                   if(dis[s][i]+dis[i][e]<dis[s][e])
                   {
                       dis[s][e]=dis[s][i]+dis[i][e];
                   }
              }
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
        ll n,m,q;
        cin>>n>>m>>q;
        //dbg(inf);

       

        for(ll i=1;i<=n;i++) 
        {
             for(ll j=1;j<=n;j++) {
                 dis[i][j]=inf;
                 if(i==j) dis[i][j]=0;

             }

        }
        for(ll i=1;i<=m;i++) 
        {
             ll u,v,w;

             cin>>u>>v>>w;

             dis[u][v]=min(dis[u][v],w);
             dis[v][u]=min(dis[v][u],w);


        }

        floyd( n);

        while(q--)
        {
            ll u,v;
            cin>>u>>v;
            if(dis[u][v]==inf) cout<<"-1"<<endl;

           else  cout<<dis[u][v]<<endl;

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
 