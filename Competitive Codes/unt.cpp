#include <bits/stdc++.h>
#define ll long long int
#define P 31
using namespace std;
ll power[100005] ;
void calculate() {
	power[0] = 1;
	for (int i = 1; i < 100005; i++)
		power[i] = (power[i - 1] * P);
}
void hashroll(string s, ll hash[]) {

	hash[0] = 0 ;
	ll n = s.size() ;

	for (int i = 1; i <= n; i++)
		hash[i] = (hash[i - 1]) * P + s[i - 1];

}


ll get_hash(ll l, ll r, ll hash[]) {

	return hash[r] - ( hash[l] * ( power[r - l] ) ) ;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	calculate() ;
	while (t--) {
		string s ;
		cin >> s ;
		ll n = s.size() ;

		ll hash[n + 5] ;

		hashroll(s, hash) ;

		ll ans = 0 ;

		for (ll i = 2; i < n; i += 2) {

			ll l1 = 0 , r1 = i / 2 ;

			ll l2 = r1, r2 = i ;

			ll l3 = r2 , r3 = l3 +  ( n - i ) / 2 ;

			ll l4 = r3 , r4 = n ;

			cout << l1 << " " << r1 << " " << " " << l2 << " " << r2 << endl;

			ll hash1 = get_hash(l1, r1, hash);
			ll hash2 = get_hash(l2, r2, hash);
			ll hash3 = get_hash(l3, r3, hash);
			ll hash4 = get_hash(l4, r4, hash);

			cout << hash1 << " " << hash2 << endl;

			if (hash4 == hash3 && hash2 == hash1)ans++;

		}

		cout << ans << "\n" ;

	}
	return 0;
}