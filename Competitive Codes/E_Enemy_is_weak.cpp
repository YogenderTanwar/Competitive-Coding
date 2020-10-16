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
class fenwick
{
    public:
  vector<ll> ft;

    ll size;


     fenwick(ll n)
     {
         this->size=n;
         ft=vector<ll>(n+1,0);

       //  ft.assign(n+1,0);
        


     }

     void update(ll pos, ll delta)
     {
          while(pos<=size)
          {
               ft[pos]+=delta;
               pos+=(pos&(-pos));
          }
     }

     ll query(ll pos)
     { 
         ll sum=0;

          while(pos>0) 
          {
               sum+=ft[pos];
               pos-=(pos&(-pos));
          }
          return  sum;
     }


};



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
         fenwick left(n), right(n);
        map<ll,ll> m;

        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];   
             m[a[i]]=a[i];

          

        }
      //  sort(a+1,a+n+1);


       for(ll i=1;i<=n;i++) right.update(m[a[i]],1);


        ll ans=0;

        for(ll i=1;i<=n;i++)
        {
           // dbg(a[i]);
           // for(ll i=1;i<=n;i++) cout<<left.ft[i]<<" ";
            //cout<<endl;


            ll leftcnt=(i-1)-(left.query(m[a[i]]));
            ll rightcnt=(right.query(m[a[i]]-1));

            //cout<<leftcnt<<" "<<rightcnt<<endl;



            ans+=(leftcnt*rightcnt);

            left.update(m[a[i]],1);
            right.update(m[a[i]],-1);
    
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
 