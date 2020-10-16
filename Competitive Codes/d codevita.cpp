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
ll a[52];
ll dp[52][10001];

ll  solve(ll n)
{


	ll sum = 0;
	REW(i, 0, n - 1) sum += a[i];



	dp[0][0] = 1;
	REP(i, n + 1) dp[i][0] = 1;

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (a[i - 1] <= j)
			{
				dp[i][j] |= dp[i - 1][j - a[i - 1]];
			}
			//cout << dp[i][j] << " ";

		}
		//cout << endl;
	}

	ll ans = inf;

	for (ll j = sum / 2; j >= 0; j--)
	{
		if (dp[n][j] == 1)
		{
			ll val = max(j, sum - j);
			ans = min(ans, val);

		}
	}

	return ans;






}



int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	jaldi_chal
	ll t;

	ll i = 0;

	while (cin >> t)
	{

		a[i++] = t;

	}
	ll n = i ;

	// REW(i, 1, n) cout << a[i] << " ";

	cout << solve(n);




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