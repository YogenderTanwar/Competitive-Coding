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

ll solve(ll n, ll k)
{
	ll ans = 1;

	REW(i, 1, k)
	{
		ans *= n - i + 1;
		ans /= i;
	}
	return ans;

}



int main() {


	jaldi_chal
	ll t = 1, i;
	cin >> t;
	while (t--)
	{
		ll a, h, l1, l2, m, c;
		cin >> a >> h >> l1 >> l2 >> m >> c;

		ll val = (h - (a * m));
		dbg(val);

		if (val <= 0) cout << "1/1" << endl;

		else if (val > (m * c)) cout << "RIP" << endl ;

		else {

			ll times = (val / c);
			// dbg(val);

			if (val % c != 0) times++;

			ll p2 = (power(l2, m));
			ll p1 = 0;
			// dbg(times);


			for (ll i = times; i <= m; i++)
			{
				// ways
				ll z = solve(m, i);


				z *= power(l1, i);
				z *= power((l2 - l1), m - i);

				p1 += z;


			}
			// dbg(p1);
			// dbg(p2);


			ll d = __gcd(p1, p2);
			p1 /= d;
			p2 /= d;

			cout << p1 << "/" << p2 << endl ;





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