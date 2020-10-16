#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define input(i,n,arr) for(i=0;i<n;i++) cin>>j, arr.push_back(j)
#define vect_ll vector<long long>
#define vect_ll_it vector<long long>::iterator
#define pb(p) push_back(p)
#define endl "\n"
#define mod 1000000007
const ll inf = 1e15;
ll i, j, m, k, x, n, s, q;

vect_ll primeinn(ll no)
{
	vect_ll prime;
	//ll num = no;
	for (i = 2; i * i <= no; i++)
	{
		if (no % i == 0)
		{
			prime.pb(i);
			while (no % i == 0)
			{
				no /= i;
			}
		}
	}
	if (no > 1) prime.pb(no);
	return prime;

}
ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = (res % mod * a % mod) % mod;
		else b = b / 2 , a = (a % mod * a % mod) % mod;
	}
	return res % mod;
}
int main()
{
	fast
	int t = 1;
	//cin >> t;

	while (t--)
	{
		cin >> x >> n;
		vect_ll prime = primeinn(x);
		ll ans = 1;
		for (auto it : prime)
		{
			//cout << it << " ";
			if (it == 1) continue;
			ll p = it;
			//ll cnt = 0;
			while (n / p)
			{
				ll cnt = n / p;
				p = (p % mod * it % mod) % mod;
				ans = (ans % mod * power(it, cnt)) % mod;
			}

		}
		cout << ans % mod << endl;

	}


//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}