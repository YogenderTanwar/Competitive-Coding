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
set<ll> s;


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        s.clear();


        for(ll i=1;i<=n;i++)
        {
             ll ele;
             cin>>ele;

             s.insert(ele);
        }
        ll val=s.size();


        if(k==1)
        {
             if(val==1) cout<<"1"<<endl;
             else cout<<"-1"<<endl;
        }
        else {
           // dbg(val);
          //  dbg(k);

          //  cout<<((val-1+k-2)/(k-1))<<endl;


             
            ll ans=max(1ll,((val-1+k-2)/(k-1)));
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
 