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
        ll n,k,a,b;
        cin>>n>>k>>a>>b;

        if(k==1) 
        {
             cout<<(n-1)*a<<endl;
             return 0;
             
        }

        ll ans=0;

        while(n>1)
        {
             if(n%k!=0) 
             {
                 if(n>k)
                  ans+=(n%k)*a;
                  else ans+=(n-1)*a;

                  n-=(n%k);

             }
             else   {
                 ll val=(n-(n/k))*a;
                 if(b<=val) 
                 {
                    ans+=b;

                 }
                 else ans+=val;

                 n=(n/k);

             }
            
           //  dbg(n);


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
 