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
const ll N = 200001;
vector<ll> arr[N];
ll  vis[N] ;
ll maxN = log2(N);
ll lca[N][20]; // check this always
ll level[N];


void dfs(ll node, ll par, ll d)
{
	lca[node][0] = par;
	level[node] = d;
	for (auto x : arr[node])
	{
		if (x == par) continue;
		dfs(x, node, d + 1);
	}
}



void build(ll n) // table for lca
{
	dfs(1, -1, 0); // par;

	for (ll j = 1; j <= maxN; j++)
	{
		for (ll i = 1; i <= n; i++)
		{
			if (lca[i][j - 1] != -1)
			{
				ll val = lca[i][j - 1];
				lca[i][j] = lca[val][j - 1];
			}

		}
	}


}

ll getLCA(ll a, ll b)
{
	if (level[a] > level[b]) swap(a, b);

	ll d = level[b] - level[a];

	while (d > 0)
	{
		ll i = log2(d);
		b = lca[b][i];
		d -= (1ll << i);
	}

	if (a == b) return a;

	for (ll i = maxN; i >= 0; i--)
	{
		if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
		{
			a = lca[a][i] , b = lca[b][i];
		}
	}

	return lca[a][0];

}

ll getdis(ll a, ll b)
{
	ll val = getLCA(a, b);

	return level[a] + level[b] - 2 * level[val];
}





int main() {


	jaldi_chal
	ll t = 1, i;
	//cin >> t;
	while (t--)
	{
		ll n;



		cin >> n ;
		ll q;
		cin >> q;



		maxN = log2(n);



		REW(i, 1, n)
		{
			REW(j, 0, maxN) lca[i][j] = -1;

		}



		for (ll i = 2; i <= n; i++)
		{
			ll ele;
			cin >> ele;
			arr[ele].push_back(i);
			// arr[i].push_back(ele);


		}

		build(n);



		while (q--)
		{
			ll node, node2;
			cin >> node >> node2;
			ll flag = 0;



			cout << getLCA(node, node2) << endl;

		}






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