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


	jaldi_chal
	ll t, i;
	cin >> t;
	while (t--)
	{
		ll h, c, t;
		cin >> h >> c >> t;

		double prev = h;
		ll count = 1;
		double factor = 1;
		ll chance = 1;
		ll x=10;
		while (x--)
		{


			double curr = 0;
			if (chance % 2 == 1) curr = (prev + factor * (c)) / ( 2 * factor) , prev = +(factor * c);
			else {
				curr = (prev + factor * (h)) / ( 2 * factor), prev = +(factor * h);

			}



			factor *= 2;

			cout << curr << endl;
			chance++;
			if (abs(t - curr) >= abs(t - prev)) break;

			prev = curr;

			count++;
		}


		cout << count << endl;


	}








	return 0;
}
