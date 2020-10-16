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
ll cost[1000001];
// ll dp[1000001];



int main() {

#ifndef ONLINE_JUDGE
	freopen("chapter_1_input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;
	for (ll tc = 1; tc <= t; tc++)
	{

		// memset(dp, -1, sizeof(dp));

		ll n, m;
		cin >> n >> m;

		REW(i, 1, n) cin >> cost[i];

		if (m >= (n - 1)) cout << "Case " << "#" << tc << ": " << "0" << endl;
		else {
			priority_queue < pair<int, int>, vector<pair<ll, ll> > , greater<pair<ll, ll>>   > s;




			for (ll i = 2; i <= (m + 1); i++)
			{
				if (cost[i] != 0)
				{
					//cout << cost[i] << " " << i << endl;
					s.push({cost[i], i});

					// dp[i] = 0;
				}

			}
			ll flag = 0;

			ll ans = 0;



			for (ll i = m + 2; i <= n; i++)
			{
				while ( !s.empty() && (i - s.top().S) > m)
				{
					s.pop();
				}

				if (s.empty())
				{
					flag = 1;
					break;
				}

				//cout << s.top().F << " " << s.top().S << endl;

				ans = s.top().F;



				if (cost[i] != 0)
				{

					s.push({ans + cost[i], i});

				}










			}

			if (flag != 1) cout << "Case " << "#" << tc << ": " << ans << endl;
			else cout << "Case " << "#" << tc << ": " << "-1" << endl;
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