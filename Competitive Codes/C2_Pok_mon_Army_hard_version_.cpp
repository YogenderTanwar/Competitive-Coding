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
ll a[300005];
 ll ans=0;
 ll n;
 void  get_erase(ll i)
{
           if(i==0 || i==n+1) return ;

      if(a[i]>a[i+1] && a[i]>a[i-1]) ans-=a[i];
        if(a[i]<a[i+1] && a[i]<a[i-1]) ans+=a[i];


}

void  get_insert(ll i)
{
           if(i==0 || i==n+1) return ;

      if(a[i]>a[i+1] && a[i]>a[i-1]) ans+=a[i];
        if(a[i]<a[i+1] && a[i]<a[i-1]) ans-=a[i];


}

int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll q;
        cin>>n>>q;
        a[0]=-1;
        a[n+1]=-1;


        for(ll i=1;i<=n;i++) cin>>a[i];

       
             ans=0;

        for(ll i=1;i<=n;i++)
        {
            get_insert(i);

             
        }

        cout<<ans<<endl;

        for(ll i=1;i<=q;i++)
        {
             ll l,r;
             cin>>l>>r;
            //  dbg(l);
            //  dbg(r);

            //  dbg(ans);

             get_erase(l-1);
             // dbg(ans);
             get_erase(l);
             // dbg(ans);
             get_erase(l+1);
             // dbg(ans);
           //  dbg(ans);
             if(l!=r)
             {
                   if((l)!=r-1 && (l+1)!=r-1)  get_erase(r-1);
                   if(l+1!=r) get_erase(r);
                   get_erase(r+1);

             }
           //  dbg(ans);


             swap(a[l],a[r]);
             get_insert(l-1);
             get_insert(l);
             get_insert(l+1);
              if(l!=r)
             {
                   if((l)!=r-1 && (l+1)!=r-1)  get_insert(r-1);
                   if(l+1!=r) get_insert(r);
                   get_insert(r+1);

             }
             cout<<ans<<endl;


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
 