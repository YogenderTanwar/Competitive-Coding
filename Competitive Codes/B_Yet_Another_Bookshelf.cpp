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
ll a[100];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll l=-1,r=-1;

        for(ll i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(a[i]==1)
            {
                 if(l==-1) l=i;
                 else r=i;

            }

        }

        if(r==-1) cout<<"0"<<endl;
        else {
      ll ans=0;

            for(ll i=l;i<=r;i++) 
            {
                if(a[i]==0) ans++;

            }
            cout<<ans<<endl;
            
        }
        
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
 