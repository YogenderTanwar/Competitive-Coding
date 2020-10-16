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
ll a[105],b[105],c[105];
 ll n;

 ll ans[105];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
       
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
         for(ll i=1;i<=n;i++) cin>>b[i];
          for(ll i=1;i<=n;i++) cin>>c[i];

          ll prev=a[1];

          ans[1]=a[1];

          for(ll i=2;i<=n;i++)
          {
               if(i<n)
               {
                   if(a[i]!=prev)
                   {
                        ans[i]=a[i];
                        prev=a[i];
                   }
                   else if(b[i]!=prev)
                   {
                        ans[i]=b[i];
                        prev=b[i];
                   }
                   else {
                       ans[i]=c[i];
                       prev=c[i];
                   }
                    
               }
               else {
                    if(a[i]!=prev && a[i]!=ans[1])
                   {
                        ans[i]=a[i];
                        prev=a[i];
                   }
                   else if(b[i]!=prev && b[i]!=ans[1])
                   {
                        ans[i]=b[i];
                        prev=b[i];
                   }
                   else {
                       ans[i]=c[i];
                       prev=c[i];
                   }


               }
          }

          for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
          cout<<endl;





        
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
 