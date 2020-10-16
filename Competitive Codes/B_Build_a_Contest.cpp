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
        ll n,m;
        cin>>n>>m;
        vector<ll> a(m);
        for(ll i=0;i<m;i++) cin>>a[i];
        set<ll> s;
        map<ll,ll > f;
       // dbg(n);


        for(ll i=0;i<m;i++) 
        {
           // cout<<"heloo"<<endl;

             s.insert(a[i]);
           //  cout<<a[i]<<" "<<s.size()<<endl;

             f[a[i]]++;
             if(s.size()==n) 
             {
                  cout<<"1";
                  for(ll j=1;j<=n;j++)
                  {
                       if(f[j]>1) f[j]--;
                       else if(f[j]==1)  f[j]=0, s.erase(j);
                  }
                

             }
             else cout<<"0";

        }


        
        
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
 