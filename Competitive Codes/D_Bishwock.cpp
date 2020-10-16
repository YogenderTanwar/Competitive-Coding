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



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
        string a,b;
        cin>>a>>b;
        ll n=a.size();

      ll ans=0;
	  ll prev=0;


	  for(ll i=0;i<n;i++)
	  {
		  ll curr=(a[i]=='0')+(b[i]=='0');
		  if(curr==0) prev=0;
		  else if(curr==1)
		  {
			  if(prev==2) ans++, prev=0;
			  else prev=1;

			   
		  }
		  else if(curr==2)
		  {
			   if(prev>0)
			   {
				    if(prev==2)
					{
						ans++;
						prev=1;
					}
					else ans++, prev=0;
			   }
			   else prev=2;
		  }
		   
	  }

	  cout<<ans<<endl;
	  







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