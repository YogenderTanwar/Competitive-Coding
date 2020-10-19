
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
ll a[1003][1003];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
   for(ll tt=1;tt<=t;tt++)
    {
        ll n,  k;

        cin>>n>>k;

        vector<ll> a(n);
        map<ll,ll> m;

        ll sz=0,val=0;



        for(ll i=0;i<n;i++) {
            cin>>a[i], m[a[i]]++;
            if(m[a[i]]>sz)
            {
                sz=m[a[i]];
                val=a[i];
            }
        }

        vector<ll> b;

        for(auto x: m) 
        {
            if(x.S==sz) b.push_back(x.F);
        }

        vector<ll> c;
        c.push_back(b[0]);
        c.push_back(b.back());
        c.push_back(b[b.size()/2]);
        ll ans=inf;

        for(auto i: c)
        {
            ll tmp=0;
            for(ll j=0;j<n;j++)
            {
                 tmp+=min(abs(i-a[j]),k-abs(i-a[j]));
            }
           // cout<<i<<" "<<tmp<<endl;

            ans=min(ans,tmp);
        }   

    cout<<"Case #"<<tt<<": "<<ans<<endl;

        
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
 