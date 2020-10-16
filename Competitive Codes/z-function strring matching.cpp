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
ll z[100001];

void zfunction(string s)
{
	ll n = s.size();
	z[0] = 0;

	for (ll i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;

	}
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	//ll t, i;


	string p, t;
	cin >> p >> t;

	string x = p + '&' + t;

	zfunction(x);
	ll count = 0;


	for (ll i = p.size() + 1; i <= x.size() - 1; i++)
	{
		if (z[i] == p.size()) count++;

	}

	cout << count;












	return 0;
}