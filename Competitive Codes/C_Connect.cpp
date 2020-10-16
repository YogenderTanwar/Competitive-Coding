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
char  a[51][51];

ll vis[51][51];

vector<pair<ll,ll> > one,two;



ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
 ll n;

bool check(ll x1,ll y1)
{
     if(x1<1 || x1>n || y1<1 || y1>n) return 0;
     else if(vis[x1][y1] || a[x1][y1]=='1') return 0;
     else return 1;
}


void dfs(ll x1,ll y1,ll val)
{
     for(ll i=0;i<4;i++)
     {
         if(check(x1+dx[i],y1+dy[i]))
         {
                 vis[x1+dx[i]][y1+dy[i]]=1;
                 dfs(x1+dx[i],y1+dy[i],val);
                 if(val==1) one.push_back({x1+dx[i],y1+dy[i]});
                 else two.push_back({x1+dx[i],y1+dy[i]});

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
       
        cin>>n;
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        for(ll i=1;i<=n;i++)
        {
             for(ll j=1;j<=n;j++)
             {
                  cin>>a[i][j];
             }
        }
        
        one.push_back({x1,y1});

        dfs(x1,y1,1);
        clr(vis);
   
    two.push_back({x2,y2});
    

        dfs(x2,y2,2);

        ll ans=inf;



        for(auto x: one) 
        {
            for(auto it: two)
            {
                 ll val=(x.F-it.F)*(x.F-it.F)+(x.S-it.S)*(x.S-it.S);
                 ans=min(ans,val);
                 if(ans==0) break;
            }

        }

        cout<<ans<<endl;




      
        



        
        
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
 