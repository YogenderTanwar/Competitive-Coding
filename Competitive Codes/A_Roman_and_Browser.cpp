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
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n+1);
      ll count_1=0,count_n=0;


        for(ll i=1;i<=n;i++) 
        {
             cin>>a[i];
             if(a[i]==1) count_1++;
             else count_n++;




        }
        ll ans=0;

     for(ll i=1;i<=k;i++)
     {
       ll temp1=0,tempn=0;

       for(ll j=i;j<=n;j+=k) 
       {
         a[j]==1? temp1++: tempn++;
         

       }

       ans=max(ans,abs((count_1-temp1)-(count_n-tempn)));


        
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
 