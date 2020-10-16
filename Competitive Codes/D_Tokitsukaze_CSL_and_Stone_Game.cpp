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
        vector<ll> a(n);
        map<ll,ll> m;

ll flag=1;

        for(ll i=0;i<n;i++) {
            cin>>a[i];
            m[a[i]]++;
            if(m[a[i]]>2) flag=1;

        }

        sort(all(a));

        ll ans=0;

        if(flag) 
        {
            cout<<"cslnb"<<endl;
            return 0;
            
        }

        if(a[0]!=0) ans=a[0];
        ll prev=0;


        for(ll i=1;i<n;i++)
        {
            if(a[i]>prev) 
            {
                ans+=(a[i]-prev-1);
                prev++;
            }
            cout<<ans<<endl;


             
        }

        cout<<ans<<endl;


        if(ans%2) cout<<"sjfnb"<<endl;
        else cout<<"cslnb"<<endl;


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
 