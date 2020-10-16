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
char arr[51][51];

char a[51], b[51];




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;
	for (ll tc = 1; tc <= t; tc++)
	{
		// ll x,y;
		ll n;
		cin >> n;

		REW(i, 1, n) cin >> a[i];
		REW(i, 1, n) cin >> b[i];

		REW(i, 1, n)
		{
			REW(j, 1, n) {
				if (i == j) arr[i][j] = 'Y';
				else arr[i][j] = 'N';
			}

		}

		for (ll j = 1; j <= n; j++)
		{

			if (b[j] == 'N') continue;



			ll l = j, r = j, flagl = 0, flagr = 0;


			for (ll k = 1; k <= n; k++)
			{
				if (flagl == 0 && l - k >= 1)
				{
					if (a[l - k] == 'N' || b[l - k + 1] == 'N') {
						flagl = 1;

					}
					else arr[j][l - k] = 'Y';

				}
				if (flagr == 0 && r + k <= n)
				{
					if (a[r + k] == 'N' || b[r + k - 1] == 'N')
					{
						flagr = 1;

					}
					else arr[j][r + k] = 'Y';

				}
				if (flagl && flagr) break;

			}



		}
		cout << "Case " << "#" << tc << ":" << endl;

		REW(i, 1, n)
		{
			REW(j, 1, n) cout << arr[i][j];
			cout << endl;
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