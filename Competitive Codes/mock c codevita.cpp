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

ll cnt = 0;

void   solve(ll a, ll b)
{
	//cout << a << " " << b << endl;
	// if (a == b && a != 0) {
	// 	cnt++;
	// 	return;

	// }

	if (a == 0 || b == 0)
	{
		return ;

	}
	else if (a > b)
	{
		cnt++;
		solve(a - b, b);


	}
	else if (b >= a)
	{
		cnt++;
		solve(a, b - a);

	}

}


int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll p, q, r, s;
		cin >> p >> q >> r >> s;
		ll ans = 0;
		map<pair<ll, ll> , ll> m;

		// solve(3 ,  7 );
		// dbg(cnt);



		REW(i, p, q)
		{
			REW(j, r, s)
			{


				if (m.count({i, j}))
				{

					ans += m[ {i, j}];
					continue;

				}
				solve(i, j);
				m[ {i, j}] = cnt;
				m[ {j, i}] = cnt;


				ans += cnt;

				//cout << i << " " << j << " " << cnt << endl;



				cnt = 0;


			}
		}

		cout << ans;







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