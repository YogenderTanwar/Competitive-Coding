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
ll p[100001], h[100001];
ll tot[100001];
ll b[100001];

vector<ll> arr[100001];


ll dfs(ll node, ll par)
{
	ll count = 0;


	for (auto x : arr[node])
	{
		if (x == par) continue;
		count += dfs(x, node);

	}

	tot[node] += count;

	return tot[node];


}


bool check(ll node, ll par)
{
	ll count = 0;
	ll flag = 1;


	for (auto x : arr[node])
	{
		if (x == par) continue;

		if (check(x, node) == false) return false;
		else {
			count += b[x];
		}
		flag = 0;


	}

	if (flag) return true;


	if (count < b[node] - p[node]) return false;
	else return true;


}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;



	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		REW(i, 1, n) cin >> p[i], arr[i].clear(), tot[i] = p[i];


		REW(i, 1, n) cin >> h[i];


		REW(i, 1, n - 1)
		{
			ll u, v;
			cin >> u >> v;

			arr[u].push_back(v) , arr[v].push_back(u);


		}



		dfs(1, 0);

		// REW(i, 1, n) cout << tot[i] << " ";
		// cout << endl;
		ll ans = 1;


		REW(i, 1, n)
		{
			if (h[i] > tot[i] || h[i] < (-1 * tot[i]) || (tot[i] - h[i]) % 2 != 0)
			{
				ans = 0;
				break;
			}
			else {

				b[i] = (tot[i] - h[i]) / 2;

			}

		}

		if (ans == 0) cout << "NO" << endl;

		else {
			//cout << "dsf";
			// REW(i, 1, n) cout << b[i] << " ";


			if (check(1, 0))
			{

				cout << "YES" << endl;

			}
			else {
				cout << "NO" << endl;
			}
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