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
        ll n,m;
        cin>>n>>m;
        ll flag=0;
        ll cnt=0;


        for(ll i=1;i<=n;i++)
        {
             ll a,b,c,d;
             cin>>a>>b>>c>>d;
             if(a==c && b==d) 
             {
                  flag=1;

             }
             else if(b==c) cnt++;
           

        }
      //dbg(cnt);


        if(cnt>=1) flag=1;


        if((  flag==1) && m%2==0) cout<<"YES"<<endl;
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
 