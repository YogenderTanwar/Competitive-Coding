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
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        ll val=1e5-2;
        vector<ll> ans;

        while(n>=val)
        {
            ans.push_back(1e5);
            ans.push_back(1e5-1);
            ans.push_back(1);
            n-=val;



        }

        if(n>=0)
        {
            ans.push_back(n+2);
            ans.push_back(n+1);
        }

        cout<<ans.size()<<endl;
        

        for(auto x: ans) cout<<x<<" ";
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
 