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
ll width[1000001];



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

		REW(i, 1, k) cin >> width[i];

		ll aw, bw , cw, dw;

		cin >> aw >> bw >> cw >> dw;



		REW(i, 1, k) cin >> height[i];

		ll ah, bh, ch, dh;

		cin >> ah >>  bh >>  ch >>  dh;


		REW(i, k + 1, n)
		{
			l[i] = ((al * (l[i - 2])) % dl + (bl * (l[i - 1])) % dl + cl % dl) % dl + 1 ;
			height[i] = ((ah * (height[i - 2])) % dh + (bh * (height[i - 1]) + ch % dh) % dh) % dh + 1 ;
			width[i] = ((aw * (width[i - 2])) % dw + (bw * (width[i - 1])) % dw + cw % dw) % dw + 1;

			//cout << height[i] << " ";

		}


		ll ans = 2 * (w[1] + height[1]) % MOD;

		set<pair<ll, ll>> s;


		ll left = l[1];

		ll right = l[1] + w[1];

		s.insert({left, right});



		ll prev = ans;



		REW(i, 2, n)
		{


			ll a = l[i];
			ll b = l[i] + w[i];











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
