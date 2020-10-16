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

        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        ll cnt=0;
        vector<ll> b;

        for(ll i=1;i<=n;i++)
        {
             if(a[i]==0) cnt++;
             else {
                 if(cnt>0) b.push_back(cnt);
                 cnt=0;

             }
        }
        if(cnt>0) b.push_back(cnt);
        b.push_back(0);

        sort(all(b),greater<ll> ());
       // cout<<b[0]<<" "<<b[1]<<endl;


        if(b[0]%2==1 && (((b[0]/2)+1)>b[1]))
        {
       cout<<"Alice"<<endl;
             
        }
        else cout<<"Bob"<<endl;

        
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
 