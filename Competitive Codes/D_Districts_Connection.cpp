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
ll a[5005];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll flag=0;

        for(ll i=1;i<=n;i++)
        {
             cin>>a[i];

        }

        vector<pair<ll,ll> > ans;
        ll index=-1;
       

        for(ll i=2;i<=n;i++)
        {
             if(a[i]!=a[1])
             {
                 if(index==-1) index=i;
                 flag=1;
                 ans.push_back({1,i});


             }
        }

        if(flag==0) 
        {
             cout<<"NO"<<endl;
        }
        else {

            for(ll i=2;i<=n;i++)
            {
                 if(a[i]==a[1])
                 {
                     ans.push_back({index,i});

                 }
            }

            cout<<"YES"<<endl;
            for(auto x: ans) cout<<x.F<<" "<<x.S<<endl;

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
 