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
map<ll,vector<ll> > m;
ll a[100005];
ll vis[100005];

int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
         ll n;
         cin>>n;
         m.clear();
         ll val;
         cin>>val;
         memset(vis,-1,sizeof vis);

         for(ll i=1;i<=n;i++)
         {
              cin>>a[i];
              m[a[i]].push_back(i);

         }

         if(val%2==0 && m[val/2].size()>0)
         {
             ll z=m[val/2].size()/2;
             ll cnt=0;


             for(auto x: m[val/2])
             {
                 if(cnt<z) vis[x]=1;
                 else vis[x]=0;
                 cnt++;


                  
             }
              
         }

         for(ll i=1;i<=n;i++)
         {
              if(vis[i]==-1)
              {
                  vis[i]=1;

                   if(m[val-a[i]].size()>0)
                   {
                       for(auto x: m[val-a[i]]) vis[x]=0;
                        
                   }
              }
         }

         for(ll i=1;i<=n;i++) cout<<vis[i]<<" ";
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
 