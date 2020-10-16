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
      ll r,n;
      cin>>r>>n;
      ll t[n+1],x[n+1],y[n+5];
      ll ans[n+1],suff[n+1];
      for(ll i=1;i<=n;i++)
      {
        cin>>t[i]>>x[i]>>y[i];
        ans[i]=1;

      }
      t[0]=0;
      x[0]=1;
      y[0]=1;
      ans[0]=1;


      suff[n]=1;
      suff[n+1]=0;


      

      for(ll i=n-1;i>=0;i--)
      {
        ll j;

          for( j=i+1;j<=n;j++)
          {
             if(abs(t[i]-t[j])>(2*r)) break;
             if(abs(t[i]-t[j])>=(abs(x[i]-x[j]) + abs(y[i]-y[j])))
             {
                ans[i]=max(ans[i],1+ans[j]);

             }
            
          }
          ans[i]=max(ans[i],suff[j]+1);


          suff[i]=max(ans[i],suff[i+1]);

          
      }

      cout<<ans[0]-1<<endl;



        
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
 