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
ll n,m,k;
vector<ll> arr[1005];
ll vis[1005];
ll check[1005];
ll flag=0;
ll cnt=0;
int dfs(int a) {
	assert(!vis[a]);
	vis[a] = true;
    if(check[a]) flag=1;
	int s = 1;
	for(int b : arr[a]) if(!vis[b]) s += dfs(b);
	return s;
}





int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        cin>>n>>m>>k;
          for(ll i=1;i<=k;i++)
        {
            ll ele;
            cin>>ele;
            check[ele]=1;

        }

        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(v);

        }

      

        vector<ll> gov,nongov;
        ll val=n-1;
        ll ans=0;
       // dbg(ans);



        for(ll i=1;i<=n;i++)
        {
            if(vis[i]) continue;
           ll val= dfs(i);
            if(flag==1)
            {
                 // gov;
                 gov.push_back(val);

            }
            else {
                // non gov
                nongov.push_back(val);
            }
            flag=0;
            cnt=0;

             
        }

        sort(all(gov),greater<ll> ());
         sort(all(nongov),greater<ll> ());

        //  ll sum=gov[0];
        // // dbg(sum);



        //  for(ll i=1;i<gov.size();i++)
        //  {
        //       ans-=(gov[i]*(sum));
        //       sum+=gov[i];
        //  }
        // // dbg(ans);

         ll sum1=0;
          for(ll i=0;i<nongov.size();i++)
         {
             sum1+=nongov[i];
         }

         gov[0]+=sum1;

         for(ll i=0;i<gov.size();i++)
         {
            // dbg(gov[i]);
             gov[i]--;


              ans+=(gov[i]*(gov[i]+1))/2;
         }

         cout<<ans-m<<endl;


         

         







        
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
 