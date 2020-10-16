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
ll a[300005];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll q;
        cin>>q;

        for(ll i=1;i<=n;i++) cin>>a[i];

       

        ll flag=1; // up 

         ll mx_best=-1, mn_best=inf;
         ll ans=0;

         mx_best=a[n];
        // dbg(mx_best);



         for(ll i=n-1;i>=1;i--)
         {
              if(flag==1)
              {
                   if(a[i]>=a[i+1]) mx_best=max(mx_best,a[i]);
                   else {
                       ans+=mx_best;
                       mx_best=-1;
                       flag=0;
                       mn_best=a[i];

                   }
              }
              else{

                  if(a[i]<=a[i+1]) mn_best=min(mn_best,a[i]);
                  else {
                  // cout<<mn_best<<endl;

                      ans-=mn_best;
                      mn_best=inf;
                      flag=1;
                      mx_best=a[i];

                  }


              }

           //   dbg(ans);


              
         }

         if(mx_best!=-1) ans+=mx_best;

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
 