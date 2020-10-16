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
ll cnta[26], cntb[26];


int main() {
//
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	jaldi_chal
	ll t, i;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		cout << a.size() << " " << b.size() << endl;

		memset(cnta, 0, sizeof(cnta));
		memset(cntb, 0, sizeof(cntb));

		for (ll i = 0; i < a.size(); i++) cnta[a[i] - 'a']++;

		for (ll i = 0; i < b.size(); i++) cntb[b[i] - 'a']++;
		ll count = 0;


		for (ll i = 0; i < 26; i++) {

			//cout << cnta[i] << " " << cntb[i] << endl;
			if (cnta[i] > 0 && cntb[i] > 0) count += cnta[i] + cntb[i];

		}


		ll len = (a.size() + b.size() - count+5);
		cout<<len<<endl;
		//cout << len << " ";




		string z = "FLAME";

		swap(z[1], z[(len - 1+5)%5]);

		cout << z << endl;











	}








	return 0;

}
