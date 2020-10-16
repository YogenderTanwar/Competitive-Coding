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
ll l[1000001];
ll height[1000001];

unordered_map<ll, ll> m;








int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;
	for (ll tt = 1; tt <= t; tt++)
	{
		ll n, k, w;

		cin >> n >> k >> w;



		REW(i, 1, k) cin >> l[i];

		ll al, bl, cl, dl;

		cin >> al >> bl >> cl >> dl;

		REW(i, 1, k) cin >> height[i];

		ll ah, bh, ch, dh;

		cin >> ah >>  bh >>  ch >>  dh;


		REW(i, k + 1, n)
		{
			l[i] = ((al * (l[i - 2])) % dl + (bl * (l[i - 1])) % dl + cl % dl) % dl + 1 ;
			height[i] = ((ah * (height[i - 2])) % dh + (bh * (height[i - 1]) + ch % dh) % dh) % dh + 1 ;

			//cout << height[i] << " ";

		}


		ll ans = 2 * (w + height[1]) % MOD;

		REW(j, 0, w)
		{
			m[l[1] + j] = height[1];
		}
		//cout << m[5] << endl;




		ll prev = ans;

		//cout << prev << endl;


		REW(i, 2, n)
		{
			ll curr = prev;



			if (l[i - 1] + w < l[i])
			{
				curr = (curr % MOD + 2 * (w + height[i]) % MOD) % MOD;
			}
			else {

				//cout << l[i] << " " << height[i] << " " << m[l[i]] << endl;

				if (m[l[i]] >= height[i])
				{
					curr = (curr % MOD + 2 * (l[i] - l[i - 1]) % MOD) % MOD;
				}
				else {

					curr = (curr % MOD + 2 * (l[i] - l[i - 1]) % MOD + 2 * (height[i] - m[l[i]]) % MOD) % MOD;
				}


			}

			//dbg(curr);

			prev = curr;
			REW(j, 0, w)
			{


				m[l[i] + j] = max(height[i], m[l[i] + j]);
			}


			ans = (ans % MOD * curr % MOD) % MOD;


		}

		cout << "Case #" << tt << ": " << ans << endl;


		m.clear();























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
