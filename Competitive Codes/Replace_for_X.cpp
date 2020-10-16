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
vector<ll> a;


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,x,p,k;
        cin>>n>>x>>p>>k;
        p--;
        k--;

        a.resize(n);

        for(ll i=0;i<n;i++) cin>>a[i];

        sort(all(a));


        if(p==k) 
        {
            if(x>=a[p])
            {
                 ll cnt=0;
                ll flag=0;

                for(ll i=p;i<=n-1;i++)
                {
                     if(a[i]>=x)
                     {
                         if(a[i]==x) flag=1;
                         break;
                     }
                     cnt++;
                }
               
                cout<<cnt<<endl;

            }
            else {
                  ll cnt=0;
                ll flag=0;

                for(ll i=p;i>=0;i--)
                {
                     if(a[i]<=x)
                     {
                         if(a[i]==x) flag=1;
                         break;
                     }
                     cnt++;
                }
              
                cout<<cnt<<endl;

            }
        }
        else if(p<k) // can only decrease the value
        {
            if(x>a[p]) cout<<"-1"<<endl;
            else {

                ll cnt=0;
                ll flag=0;

                for(ll i=p;i>=0;i--)
                {
                     if(a[i]<=x)
                     {
                         if(a[i]==x) flag=1;
                         break;
                     }
                     cnt++;
                }
              
                cout<<cnt<<endl;

            }
             
        }
        else{  // can only increase the value

        if(x<a[p]) cout<<"-1"<<endl;
        else {
              ll cnt=0;
                ll flag=0;

                for(ll i=p;i<=n-1;i++)
                {
                     if(a[i]>=x)
                     {
                         if(a[i]==x) flag=1;
                         break;
                     }
                     cnt++;
                }
               
                cout<<cnt<<endl;


        }


        }

        a.clear();



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
 