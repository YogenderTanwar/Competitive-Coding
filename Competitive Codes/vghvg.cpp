// Striver_79
// Youtube: takeUforward
// Practice is the only shortcut to improve

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << endl;}
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x) { int lo = 1, hi = min(2000000ll, x); while (hi - lo > 1) {int mid = (lo + hi) / 2; if (mid * mid * mid < x) {lo = mid;} else hi = mid;} if (hi * hi * hi <= x) return hi; else return lo;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N =  (int)(1 * 1e6 + 10);
// bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
//     if (p1.fi > p2.first) return true;
//         else if (p1.se == p2.se) {
//             if (p1.se.fi < p2.se.fi) return true;
//         }
//         return false;
// }

int n, k;
string s;
int dp[N][3];

int func(int ind, int flag) {

	if (ind >= n) {
		return 0;
	}

	if (dp[ind][flag] != -1) return dp[ind][flag];

	//cout << s << endl;;


	int cnt = 1e10;
	if (flag == 1)
	{
		if (s[ind] == '0') {
			if (ind - k >= 0 && s[ind - k] == '1') {
				s[ind] = '1';
				cnt = min(cnt, 1 + func(ind + 1, 1));
				s[ind] = '0';

				cnt = min(cnt, func(ind + 1, 2));
			}
			else {
				cnt = min(cnt, func(ind + 1, 1));
			}
		}
		else {
			if (ind - k >= 0 && s[ind - k] == '1') {
				cnt = min(cnt, func(ind + 1, 1));
			}
			else {
				s[ind] = '0';
				cnt = min(cnt, 1 + func(ind + 1, 1));
				s[ind] = '1';
			}
		}
	}
	else if (flag == 0)
	{
		if (s[ind] == '1')
		{
			s[ind] = '0';
			cnt = min(cnt, 1 + func(ind + 1, 0));
			s[ind] = '1';

			cnt = min(cnt, func(ind + 1, 1));
		}
		else
		{
			s[ind] = '1';
			cnt = min(cnt, 1 + func(ind + 1, 1));
			s[ind] = '0';

			cnt = min(cnt, func(ind + 1, 0));
		}
	}
	else if (flag == 2) {
		if (s[ind] == '1') {
			s[ind] = '0';
			cnt = min(cnt, 1 + func(ind + 1, 2));
			s[ind] = '1';
		}
		else
		{
			cnt = min(cnt, func(ind + 1, 2));
		}
	}

	return dp[ind][flag] = cnt;
}


signed main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	fio;
	//srand(time(NULL));
	int T = 1;
	cin >> T;

	while (T--) {

		cin >> n >> k;
		// for0(i, n) {
		//     for0(j, 3) {
		//         dp[i][j] = -1;
		//     }
		// }

		cin >> s;

		// prl(func(0, 0));

		int pre[n];
		ini(pre, 0);
		for0(i, n) {
			if (i == 0) pre[i] = s[i] - '0';
			else pre[i] += pre[i - 1] + (s[i] - '0');
		}

		int sum[n];
		ini(sum, 0);
		bloop(i, n - 1, 0)
		{
			int xr = (s[i] - '0') ^ 1;
			if (i + k - 1 < n) {
				xr += pre[i + k - 1] - pre[i];
			}
			else {
				xr += pre[n - 1] - pre[i];
			}
			if (i + k < n) {
				xr += sum[i + k];
			}
			int r = pre[n - 1] - pre[i] + (s[i] - '0');
			sum[i] = min(r, xr);
		}
		int cnt = 1e15;
		for0(i, n) {
			int s = sum[i];
			if (i) s += pre[i - 1];

			cnt = min(cnt, s);
		}
		prl(cnt);
	}
}





 