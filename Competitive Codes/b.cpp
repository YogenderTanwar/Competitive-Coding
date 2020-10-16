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
ll parent[100001];

map<ll, ll > ma;



ll find(ll a)
{
	if (parent[a] == a) return a;
	else return find(parent[a]);

}
void Union(ll a, ll b)
{
	a = find(a) , b = find(b);

	if (a == b) return ;
	else parent[b] = a; // connecting two set and making parent as a;

}





int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	ll t = 1, i;
	//cin >> t;
	while (t--)
	{

		ll n, m;
		cin >> n >> m;

		REW(i, 1, n) parent[i] = i;

		REW(i, 1, m)
		{
			ll u, v;
			cin >> u >> v;
			Union(u, v);

		}


		REW(i, 1, n) ma[parent[i]]++, cout << parent[i] << " ";


		ll ans = 1;

		for (auto x : ma)
		{
			ans = (ans * x.S) % MOD;
		}
		cout << ans;




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