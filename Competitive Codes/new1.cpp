#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
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
ll power1(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll x, n;
		cin >> x >> n;

		vector<ll> p;



		for (ll j = 2; j * j <= x; j++)
		{
			ll count = 0;

			while (x % j == 0) count++, x = x / j;

			if (count > 0 ) p.push_back(j);







		}

		if (x > 0) p.push_back(x);


		ll ans = 1;

		for (ll i = 0; i < p.size(); i++)
		{

			double  val = double(p[i]);

			ll count = 0;


			while (1)
			{
				//dbg(val);
				ll times = floor(n / val);

				if (times == 0) break;
				//	dbg(times);


				count += times;

				val *= p[i];

				dbg(val);

				if (val > n) break;





			}

			//cout << 1e18 - val;

			//dbg(count);











			ans = (ans % MOD * int(fmod(pow(p[i], count) , MOD)) ) % MOD;



		}



		cout << ans << endl;








	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = (res % MOD * a % MOD) % MOD;
		else b = b / 2 , a = (a % MOD * a % MOD) % MOD;
		//	cout << b << " ";

	}

	//cout << res << " ";

	return res % MOD;
}