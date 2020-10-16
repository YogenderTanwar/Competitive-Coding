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

        ll cnt=0;

        ll a[n+1];

        for(ll i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]==1) cnt++;
        }
        if(cnt>0) 
        {
            cout<<n-cnt<<endl;
            return 0;
        }

        ll len=inf;

        for(ll i=1;i<=n-1;i++)
        {
            ll g=a[i];
             for(ll j=i+1;j<=n;j++)
             {
                 g=__gcd(g,a[j]);
                 if(g==1)
                 {
                      len=min(len,j-i);
                 }
                  
             }
        }
      //  dbg(len);


        if(len==inf) cout<<"-1";
        else cout<<len+n-1<<endl;




        
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
 
