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

ll solve(ll n)
{
	vector<ll> a;
	for (ll i = n; i > 0; i = i / 10)
	{
		a.push_back(i % 10);
	}
	sort(all(a));

	ll x = a[0], y = a[2];

	ll val = (y * 11 + x * 7);

	ll ans = 0;

	ans += (val % 10);

	val /= 10;
	ans += (val % 10) * 10;

	return ans;




}



int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		map<ll, ll> odd, even;


		REW(i, 1, n)
		{
			ll ele;
			cin >> ele;


			ll val = solve(ele);
			// dbg(val);
			if (i % 2 == 0) {

				ll z = (val) / 10;
				even[z]++;

			}
			else {
				ll z = (val) / 10;
				odd[z]++;

			}

		}


		set<ll> s;
		ll ans = 0;


		for (auto x : odd)
		{
			if (s.count(x.F)) continue;
			ll val = max(x.S, even[x.F]);
			if (val == 2) ans++;
			else if (val > 2) ans += 2;
			s.insert(x.F);

		}

		for (auto x : even)
		{
			if (s.count(x.F)) continue;
			ll val = max(x.S, odd[x.F]);
			if (val == 2) ans++;
			else if (val > 2) ans += 2;
			s.insert(x.F);

		}

		cout << ans << endl;









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