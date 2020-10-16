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
ll n, k;
ll a[100001];


bool check(ll key)
{

	ll start = 1, end = n;
	ll count = 0;
	while (start > end)
	{
		if (a[start] + a[end] <= key) {
			count++, start++ , end--;
		}
		else {
			end-- , count++;
		}


	}

	if (count <= k) return true;
	else false;



}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	jaldi_chal
	cin >> n >> k;

	REW(i, 1, n) cin >> a[i];

	ll l = a[n], r = 2 * 1000000;
	ll ans;
	while (r >= l)
	{
		ll mid = (l + r) / 2;
		if (check(mid))  ans = mid , r = mid - 1;
		else l = mid + 1;

	}

	cout << ans;









	return 0;
}