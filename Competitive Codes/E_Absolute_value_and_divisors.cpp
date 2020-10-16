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


int main()
{
	fast
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		map<ll, ll> m;
		for (ll i = 1; i <= n; i++)
		{
			ll ele;
			cin >> ele;
			//dbg(ele);
			m[ele]++;

		}
		set<ll> s;

		for (ll i = 1; i * i <= k; i++)
		{
			if (k % i == 0)
			{
				s.insert(i);
				s.insert(k / i);
			}
		}

		ll ans = 0;
		set<pair<ll, ll> > res;

		for (auto x : m)
		{
			ll val = x.F;
			if (m[val] > 0)
			{
				for (auto it : s)
				{


					if (m[val - it] > 0) res.insert({val, val - it});
					if (m[val + it] > 0) res.insert({val, val + it});

				}

			}

			//dbg(val);



		}

		// for (auto x : res)
		// {
		// 	cout << x.F << " " << x.S << endl;

		// }

		cout << res.size() << endl;




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
