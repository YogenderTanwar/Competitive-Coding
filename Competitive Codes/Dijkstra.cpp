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
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);
vector<pair<ll, ll> > arr[100001];
ll vis[100001];
set<pair<ll, ll> > s;

ll dis[100001];




int main() {


	jaldi_chal
	ll t = 1, i;




	// cin >> t;
	while (t--)
	{

		ll n, m;
		cin >> n >> m;
		for (ll i = 1; i <= n; i++) dis[i] = inf;

		for (ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;

			arr[u].push_back({v, 0});

			s.insert({u, v});
		}



		for (auto x : s)
		{
			ll u = x.F, v = x.S;

			if (s.count({v, u})) continue;

			s.insert({v, u});

			arr[v].push_back({u, 1});




		}


		dis[1] = 0;


		deque<ll> q;


		while (!q.empty())
		{
			ll v = q.front();

			for (auto x : arr[v])
			{
				ll u = x.F;
				ll w = x.S;



				if (dis[v] + w < dis[u])
				{
					if (w == 1)
					{
						q.push_back(u);

					}
					else {
						q.push_front(v);
					}
				}
			}
		}



		if (dis[n] == inf) cout << "-1" << endl;
		else cout << dis[n] << endl;


















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