#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e18
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);


ll vis[100001];
vector<pair<ll,pair<ll,ll> >  > edges;

 vector<pair<ll, ll> > arr[100001];

ll a[100001];
ll b[100001];



void solve(ll start,ll dis[])
{
    dis[start] = 0;


		priority_queue<pair<ll,ll> ,vector< pair<ll,ll> > , greater<pair<ll,ll> > > q;

		q.push({0,start});



		while (!q.empty())
		{
			ll node = q.top().S;
            ll d=q.top().F;
        
			q.pop();
            vis[node]=1;
            if(dis[node] < d) continue;

			for(auto x: arr[node])
			{
				ll child=x.F;
				ll weight=x.S;
                


				if(vis[child]==0 &&dis[child]>(weight+dis[node]))
				{
                     dis[child]=dis[node]+weight;
					 q.push({dis[child], child});
					

				}
				
			}

			
		}


}




int main() {


	jaldi_chal
	ll t = 1, i;




	// cin >> t;
	while (t--)
	{

		ll n, m;
		cin >> n >> m;
       
          // vector<pair<ll,ll> > rev[100001];
		for (ll i = 1; i <= n; i++) a[i] = 1e18, b[i]=1e18;


		for (ll i = 1; i <= m; i++)
		{
			ll u, v,w;

			cin >> u >> v>>w;
            edges.push_back({u,{v,w}});



			arr[u].push_back({v, w});
           // rev[v].push_back({u,w});


			
		}

         solve(1,a);
        clr(vis);

        for(ll i=1;i<=n;i++) arr[i].clear();


        for(auto x: edges)
        {
            arr[x.S.F].push_back({x.F,x.S.S});

             
        }

         solve(n,b);

        ll ans=inf;

        for(auto x: edges)
        {
             if(a[x.F]==1e18 || b[x.S.F]==1e18) continue;
             ans=min(ans,a[x.F]+b[x.S.F]+(x.S.S)/2);
        }

        cout<<ans<<endl;

	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}