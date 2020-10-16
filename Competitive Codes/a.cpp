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

ll a[200005];
ll dp[200005][3][3];



int main() {


	jaldi_chal
	ll t = 1, i;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		for (ll i = 1; i <= n; i++) cin >> a[i];

		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= 2; j++)
			{
				for (ll k = 0; k <= 2; k++) dp[i][j][k] = inf;
			}
		}

		ll ans = 0;

		ll flag = 1;




		if (a[1] == 1) ans++;

		dp[1][1][1] = ans;


		ll count = 1;

		for (ll i = 2; i <= n; i++)
		{

			dp[i][1][1] = min(dp[i - 1][2][1], dp[i - 1][2][2]);
			if (a[i] == 1) dp[i][1][1]++;

			dp[i][1][2] =  dp[i - 1][1][1];
			if (a[i] == 1) dp[i][1][2]++;

			dp[i][2][1] = min(dp[i - 1][1][1], dp[i - 1][1][2]);

			dp[i][2][2] =  dp[i - 1][2][1];



		}

		//cout << dp[7][2][2] << endl;



		cout << min(min(dp[n][1][1], dp[n][1][2]), min(dp[n][2][1], dp[n][2][2])) << endl;







		//cout << ans << endl;
















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