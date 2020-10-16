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
vector<ll> a,c;

set<ll> b;



int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        a.clear();
        b.clear();
        c.clear();

        for(ll i=0;i<n;i++)
        {
            ll ele;
            cin>>ele;
            a.push_back(ele);
            b.insert(ele);
            c.push_back(ele);

        }



        sort(all(a),greater<ll> ());
         if(b.size()<n) 
         {
              cout<<"YES"<<endl;
         }
         else if(a!=c) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
         


        
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
 