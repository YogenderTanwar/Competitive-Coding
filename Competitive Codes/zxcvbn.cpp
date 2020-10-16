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

ll p_pow[1000001];
ll h[1000001];


void compute(string s )
{
	ll n = s.size();
	h[n] = 0;
	p_pow[0] = 1;


	for (ll i = n - 1; i >= 0; i--)
	{
		h[i] = (h[i + 1] * p + (s[i] - 'a' + 1)) % m;
		p_pow[n - i] = p_pow[n - i - 1] * p % m;
		//cout << h[i] << " ";

	}
	p_pow[n] = p_pow[n - 1] * p % m;


}

ll get_Hash(ll l, ll r)
{
	return (m - (h[r + 1] * p_pow[r - l + 1]) % m + h[l]) % m;
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
		string s;
		cin >> s;
		ll N = s.size();

		ll count = 0;
		compute(s);



		for (i = 2; i <= s.size() - 2; i += 2)
		{
			int l1 = 0, r1 = i / 2 - 1; //Part-1
			int l2 = r1 + 1, r2 = i - 1; //Part-2
			int l3 = i, r3 = (i + N) / 2 - 1; //Part-3
			int l4 = r3 + 1, r4 = N - 1; //Part-4


			//cout << get_Hash(l1, r1) << " " << get_Hash(l2, r2) << endl;


			bool C1 = get_Hash(l1, r1) == get_Hash(l2, r2);
			bool C2 = get_Hash(l3, r3) == get_Hash(l4, r4);

			if (C1 && C2) count++;
		}

		cout << count << endl;



	}








	return 0;
}