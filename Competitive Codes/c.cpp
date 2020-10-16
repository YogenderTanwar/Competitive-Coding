#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);
ll s[10001];

ll arr[1000001];
void seive()
{
	REW(i, 2, 10000) s[i] = 1;


	for (ll i = 2; i * i <= 10000; i++)
	{
		if (s[i] == 1)
		{

			for (ll j = i * i; j <= 10000; j += i)
			{
				s[j] = 0;
			}
		}
	}
}
vector<ll > prime;

void segmented(ll l, ll r)
{
	for (ll i = 0; i < (r - l + 1); i++) arr[i] = 1;

	for (ll i = 0; i < prime.size(); i++)
	{
		ll val = (l / prime[i]) * prime[i];
		//cout << val << " " << prime[i] << endl;

		val += prime[i];
		//cout << prime[i] << " " << endl;
		for (ll j = val ; j <= r ; j += prime[i])
		{
			//cout << j << endl;
			arr[j - l] = 0;
		}

		if (val == prime[i]) arr[val - l] = 1;
	}

	//cout << l << " " << r << endl;

	// REW(i, 0, (r - l )) cout << arr[i] << " ";
	// cout << endl;

}







int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	cin >> t;
	seive();

	while (t--)
	{
		ll l, r;
		cin >> l >> r;

		for (ll i = 2; i * i <= r; i++)
		{
			if (s[i] == 1) prime.push_back(i);
		}

		segmented(l, r);


		REP(i, r - l + 1)  if (arr[i] && (i + l != 1)) cout << i + l << endl;
		cout << endl;





		prime.clear();










	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}