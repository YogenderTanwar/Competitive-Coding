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


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        if(n==1) 
        {
             cout<<"1"<<endl;
             cout<<"1 1"<<endl;
             return 0;
        }
    
        ll ans=(n+2)/2;
        ll j=1;
        cout<<ans<<endl;
        cout<<"1 1"<<endl;
        ll cnt=n-1;
        ll x=2;

        while(cnt>0)
        {
            cout<<x<<" "<<j<<endl;
            cnt--;
          j++;

            if(cnt>0) cout<<x<<" "<<j<<endl;
            x++;
            
            cnt--;



             
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
 