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
const int p = 31;
const int m = 1e9 + 9;
const int p1 = 53;
const int m1 = 1e9 + 7;
ll p_pow[100001];
ll h[100001];
ll h1[100001];
ll p_pow1[100001];






int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal


	p_pow[0] = 1;
	p_pow1[0] = 1;

	REW(i, 1, 100000)
	{
		p_pow[i] = (p_pow[i - 1] * p) % m;
		p_pow1[i] = (p_pow1[i - 1] * p1) % m1;


	}
	ll t;
	cin >> t;

	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		string a;
		cin >> a;

		//	kmp(b);

		ll lena = a.size();

		h[0] = 0;


		for (ll i = 0; i < lena; i++)
		{
			h[i + 1] = (h[i] + (a[i] - 'a' + 1) * p_pow[i]) % m;

		}
		for (ll i = 0; i < lena; i++)
		{
			h1[i + 1] = (h1[i] + (a[i] - 'a' + 1) * p_pow1[i]) % m1;

		}

		ll hs = 0;



		set<pair<ll, ll> > s;


		for (ll i = 0; i <= lena - k; i++)
		{
			ll curr = (h[i + k] + m - h[i]) * p_pow[n - i - 1] % m;
			ll curr1 = (h1[i + k] + m1 - h1[i]) * p_pow1[n - i - 1] % m1;

			//cout << curr << " " << curr1 << endl;
			s.insert({curr, curr1});



		}


		cout << s.size() << endl;












	}








	return 0;
}