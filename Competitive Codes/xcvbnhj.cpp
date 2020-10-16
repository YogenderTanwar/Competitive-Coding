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

bool check(set<ll> s, ll val)
{
	set<ll> m;
	m = s;
	for (auto x : s) {
		ll z = x ^ val;
		if (m.count(z) == 0) return false;
		m.erase(z);

	}
	return true;

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
		ll n;
		//cin>>n;
		for (ll i = 1; i < 20; i++) {
			ll val = (i ^ i - 1);
			cout << __builtin_popcount(val) << " ";



		}



	}








	return 0;
}