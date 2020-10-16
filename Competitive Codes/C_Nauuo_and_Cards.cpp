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
        ll index[n+1];
       for(ll i=1;i<=n;i++) 
       {
            ll ele;
            cin>>ele;
            index[ele]=0;


       }
        for(ll i=1;i<=n;i++) 
       {
            ll ele;
            cin>>ele;
            index[ele]=i;
            

       }

       if(index[1])
       {
           ll i;
           for( i=2;index[i]==index[i-1]+1;i++);
           if(index[i-1]==n)
           {
               ll j;
                for( j=i;j<=n && index[j]<=j-i;j++);
                if(j>n) 
                {
                     cout<<n-i+1<<endl;
                     return 0;
                }
                
           }

       }

       ll ans=0;
       for(ll i=1;i<=n;i++)
       {
            ans=max(ans,index[i]-i+1+n);

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
 