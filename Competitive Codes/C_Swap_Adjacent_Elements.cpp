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
ll a[200004];


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        for(ll i=1;i<=n;i++) cin>>a[i];
        string s;
        cin>>s;
        ll prev=1,curr=1,valmin=a[1],valmax=a[1];
        ll flag=0;
        s+='0';


        for(ll i=1;i<=n;i++)
        {
             ll val=s[i-1]-'0';
             if(val==1) 
             {
                 valmin=min(valmin,a[i]);
                 valmax=max(valmax,a[i]);
                 curr++;

             }
             else{
                  valmin=min(valmin,a[i]);
                 valmax=max(valmax,a[i]);

                 if(curr==valmax && prev==valmin) ;
                 else {
                    //  dbg(curr);
                    //  dbg(valmax);
                    //  dbg(prev);
                    //  dbg(valmin);




                     flag=1;
                     break;
                 }

                 if(i!=n)
                 {
                     prev=i+1;
                     curr=i+1;
                      valmin=a[i+1];
                 valmax=a[i+1];

                 }



             }

        }

        if(flag==0) cout<<"YES"<<endl;
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
 