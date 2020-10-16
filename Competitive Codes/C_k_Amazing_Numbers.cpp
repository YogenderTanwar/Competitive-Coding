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
ll ans[300005];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        m.clear();

        for(ll i=1;i<=n;i++)
        {
             ll ele;
             cin>>ele;
             m[ele].push_back(i);


        }

        for(ll i=1;i<=n;i++) ans[i]=inf;


        for(auto x: m)
        {
             auto it=x.S;

             ll val=it[0];

            for(ll i=1;i<it.size();i++) val=max(val, it[i]-it[i-1]);
            val=max(val,n+1-it.back());

            //cout<<x.F<<" "<<val<<endl;


           
              ans[val]=min(ans[val],x.F);



        }

        ll prev=-1;

        for(ll i=1;i<=n;i++)
        {
             if(prev==-1)
             {
                 if(ans[i]==inf) ans[i]=-1;
                 else prev=ans[i];
                  
             }
             else {
                 prev=min(prev,ans[i]);
                 ans[i]=prev;

             }

             cout<<ans[i]<<" ";
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
 