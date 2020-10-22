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
vector<pair<ll,ll> > arr[100005];
ll cnt[100005];



int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        vector<ll> ans;

        for(ll i=1;i<=m;i++)
        {
             ll u,v,w;
             cin>>u>>v>>w;
             arr[u].push_back({v,w});


        }

        priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll>>  > p;

        p.push({0,1});

        while(!p.empty() && cnt[n]<k)
        {
            ll val=p.top().F;
            ll node=p.top().S;
            p.pop();

            if(node==n) 
            {
                ans.push_back(val);
            }
            cnt[node]++;
            if(cnt[node]<=k)
            {
                 for(auto x: arr[node])
                 {
                      p.push({val+x.S,x.F});

                 }
            }

            


        }

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
 