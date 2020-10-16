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


ll n, k;

ll a[200001];


bool check (ll key)
{

	ll val = 0;


	for (ll i = (n + 1) / 2; i <= n; i++)
		val += max (0ll, key - a[i]);

	return val <= k;


}



int
main ()
{


// #ifndef ONLINE_JUDGE
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);
// #endif
	jaldi_chal
	ll t;




	cin >> n >> k;



	for (ll i = 1; i <= n; i++)
		cin >> a[i];

	if (n == 1) {
		cout << a[1] + k;
		return 0;
	}


	sort (a + 1, a + n + 1);


	ll l = 1, r = 1e9;

	ll ans = 0;


	while (r >= l)

	{
		//   cout<<l<<" "<<r<<endl;
		ll mid = (r + l) / 2;


		if (check (mid))
			ans = mid, 	l = mid + 1;

		else r = mid - 1;




	}



	cout << ans;
























	return 0;

}
