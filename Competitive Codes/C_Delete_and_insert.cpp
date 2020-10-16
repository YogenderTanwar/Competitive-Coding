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
        string s;
        cin>>s;
        ll ans=inf;
        map<ll,ll> m;
        ll mn=inf, mx=-1;
        for(ll i=0;i<s.size();i++) 
        {
             m[s[i]-'A']++;
            

        } 

        for(auto x: m)
        {
             mn=min(mn, x.S);
             mx=max(mx, x.S);

        }
        // dbg(mn);
        // dbg(mx);


        for(ll i=mn;i<=mx;i++)
        {
            ll cnt=0;

             for(ll j=0;j<26;j++)
             { 
                 if(m[j]>0)
                 {
                        ll val=abs(i-m[j]);
                 cnt+=(val*(j+1));

                 }
              

             }
             ans=min(ans,cnt);
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
 