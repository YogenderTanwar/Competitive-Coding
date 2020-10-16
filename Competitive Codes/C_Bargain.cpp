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
ll n;

ll fact[100005];
ll val[100005];





int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
         fact[1]=1;

        for(ll i=2;i<=100000;i++)
        {
            fact[i]=(fact[i-1]%MOD+power(10,i-1)*i)%MOD;
        }

       // dbg(fact[11]);

        string s;
        cin>>s;
        n=s.size();

        ll ans=0;


        for(ll i=0;i<n;i++)
        {
             ll val=(s[i]-'0');
             ll left=i;
             ll right=n-i-1;
             left=(left%MOD*(left+1)%MOD);
             left=(left*(power(2,MOD-2)))%MOD;
             
            
             ans=(ans + ((left)%MOD*power(10,right)*(val%MOD))%MOD )%MOD;

             ll val1=0;

              val1=(fact[right]);


             
             val1=(val1%MOD*val%MOD)%MOD;
             

             ans=(ans%MOD + val1%MOD)%MOD;

          //   dbg(ans);



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
    if (b % 2) b-- , res = (res %MOD* a%MOD) %MOD; 
   else b = b / 2 , a =(a%MOD * a%MOD)%MOD; 
    } 
  return res; 
 } 
 