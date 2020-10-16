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

	string s1, s2;
	cin >> s1 >> s2;

	ll h1 = (s1[0] - '0' * 10 + s1[1] - '0');
	ll m1 = (s1[3] - '0' * 10 + s1[4] - '0');

	ll h2 = (s2[0] - '0' * 10 + s2[1] - '0');
	ll m2 = (s2[3] - '0' * 10 + s2[4] - '0');

	ll min = (h2 - h1) * 60 + (m2 - m1);

	min = min / 2;

	while (min < 60)
	{
		h1++;
		min -= 60;

	}

	ll 	extra = (min + m1);

	if (extra > 60)
	{
		h1++;
		m1 = extra - 60;
	}
	else {
		m1 = min + m1;
	}

	cout << h1 << ":" << m1 << endl;















	return 0;
}