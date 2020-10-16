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
		string s;
		cin >> s;
		if (s[0] == '0') cout << "NO" << endl;
		else {
			ll flag = 1;
			for (ll i = 0; i < s.size() && flag == 1; i++)
			{

				cout << s[i] - '0' << endl;
				if (!isdigit(s[i])) cout << "NO" << endl, flag = 0;

			}
			if (flag) cout << "YES" << endl;
		}


	}








	return 0;
}