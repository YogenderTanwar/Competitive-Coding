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
		ll n, k;
		cin >> n >> k;
		ll a[n + 1] , b[n + 1];

		REW(i, 1, n) cin >> a[i];
		REW(i, 1, n) cin >> b[i];

		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1, greater<ll> ());

		ll sum = 0;

		for (ll i = 1; i <= n; i++)
		{
			if (i <= k) sum += b[i];
			else sum += a[i];
		}

		cout << sum << endl;




	}








	return 0;
}