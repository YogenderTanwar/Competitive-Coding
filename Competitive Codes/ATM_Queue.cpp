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
map<ll,vector<ll> > m;


int main()
{
    fast
    ll tt = 1; 
    cin>>tt;

      for(ll t=1;t<=tt;t++)
    {
        m.clear();
        ll n,k;
        cin>>n>>k;



        for(ll i=1;i<=n;i++)
        {
             ll ele;
             cin>>ele;
             m[(ele+k-1)/k].push_back(i);


        }
cout<<"Case "<<"#"<<t<<": ";
        for(auto x: m)
        {
             for(auto it:x.S) cout<<it<<" ";
        }
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
 