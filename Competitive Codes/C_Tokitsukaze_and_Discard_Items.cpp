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
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> sp(m);

        for(ll i=0;i<m;i++) cin>>sp[i];

        ll ans=0;
        ll prev=0;

        ll curr=(sp[0]+k-1)/k;
       // dbg(curr);


        for(ll i=1;i<m;i++)
        {
             ll val=sp[i];
             val-=prev;
             ll its=(val+k-1)/k;
             //cout<<sp[i]<<" "<<its<<endl;

             if(curr==-1) 
             {
                 curr=its;

             }
                 else  if(curr==its) continue;
             else {
                 ans++;
                 curr=-1;
                 prev=i;
                 i--;
             }

           //  cout<<ans<<" "<<i<<endl;



        }
        if(curr!=-1) ans++;

        cout<<ans<<endl;


        //cout<<ans<<endl;

       



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
 
