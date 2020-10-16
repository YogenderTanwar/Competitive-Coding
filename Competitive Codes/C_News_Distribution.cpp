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
#define N 1000005
const ll inf = 1e18;
ll power(ll a, ll b);
vector<ll> arr[N];
ll color[N];
ll cc=0;
ll ans[N];
ll n,m;

ll dfs(ll x)
{
   // dbg(x);

    if(color[x])
		return 0;
	color[x] = cc;
	int ans = (x <= n ? 1 : 0);
   // dbg(ans);

	for(auto y : arr[x])
		ans += dfs(y);
      //  dbg(ans);

	return ans; 

}



int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        
        cin>>n>>m;


        for(ll i=1;i<=m;i++)
        {
             ll k;
             cin>>k;
            

             for(ll j=1;j<=k;j++)
             {
                 ll ele;
                 cin>>ele;
               
                    arr[ele].push_back(i+n);
                    arr[i+n].push_back(ele);
                   // prev=ele;

                

             }
            
        }

        for(ll i=1;i<=n;i++)
        {
             if(color[i]) 
             {
                  cout<<ans[color[i]]<<" ";
             }
             else {
               cc++;
               ans[cc]=dfs(i);
                cout<<ans[color[i]]<<" ";



             }

            

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
 