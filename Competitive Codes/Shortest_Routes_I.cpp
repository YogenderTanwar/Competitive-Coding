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
vector<pair<ll, ll> > arr[100001];
ll vis[100001];


ll dis[100001];




int main() {


	jaldi_chal
	ll t = 1, i;




	// cin >> t;
	while (t--)
	{

		ll n, m;
		cin >> n >> m;
		for (ll i = 1; i <= n; i++) dis[i] = 1e18;

		for (ll i = 1; i <= m; i++)
		{
			ll u, v,w;

			cin >> u >> v>>w;


			arr[u].push_back({v, w});

			
		}





		dis[1] = 0;


		priority_queue<pair<ll,ll> ,vector< pair<ll,ll> > , greater<pair<ll,ll> > > q;

		q.push({0,1});



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



		for(ll i=1;i<=n;i++) cout<<dis[i]<<" ";
		cout<<endl;



















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