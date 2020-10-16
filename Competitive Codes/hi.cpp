#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define M 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"

ll sum(ll n) {
	ll b = (n * (n + 1)) / 2;
	return b;
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t, i;
	cin >> t;
	while (t--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll ans = 0;
		ll left = b;
		ll num = 0;
		for (ll i = c; i <= d; i++)
		{

			while ((i - left + 1) > b && left <= c) left++;
			if (left > c) break;

			num = (i - left + 1);
			if (num < a) num = a;

			ll midrem = (c - left);
			ll cnt = (num - a);
			if (left + cnt <= c)
			{
				ll l = (b - num + 1);
				ll r = l + cnt;

				ans += sum(r) - sum(l - 1);


				ll extra = (midrem - r);
				ans += (extra * (b - a + 1));


			}
			else {

				ll l = (b - num + 1);
				ll r = l + cnt;

				ans += sum(r) - sum(l - 1);

			}


		}


		cout << ans << endl;




	}








	return 0;
}