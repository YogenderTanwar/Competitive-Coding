#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()

{

	ll n;
	cin >> n;

	ll sum = 0;

	vector<ll> cost;

	for (ll i = 0; i < n; i++)
	{
		ll s;
		cin >> s;

		for (ll j = 1; j <= s; j++)
		{
			ll ele;
			cin >> ele;
			sum += ele;
			cost.push_back(ele);
		}
	}

	sort(cost.begin(), cost.end());

	for (auto x : cost) cout << x << " " << endl;


	ll val = sum / n;





	return 0;

}