#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf = 1e18;
ll power(ll a, ll b);
vector<ll> a;


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        a.clear();

        for(ll i=0;i<n;i++)
        {
            ll ele;
            cin>>ele;
            a.push_back(ele);
        }

        if(n==1)
        {
             cout<<"0"<<endl;
             continue;
             
        }

        sort(all(a));
        ll ans=a[n-1];

        for(ll i=n-2;i>=0 && k>0 ;i-- ,k--)
        {
         ans+=a[i];

        }

        cout<<ans<<endl;

        
    }
return 0;
}

ll power(ll a, ll b)
 { 
  ll res = 1; 
   while (b) 
   { 
    if (b % 2) b-- , res = res * a; 
   else b = b / 2 , a *= a; 
    } 
  return res; 
 } 
 