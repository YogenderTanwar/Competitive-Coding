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
   for(ll tt=1;tt<=t;tt++)
    {
        string s;
        cin>>s;
        ll n=s.size();

        ll cnt=0;
    ll ans=0;

    for(ll i=0;i<n;i++)
    {
         if(s[i]=='K' && i+3<n)
         {
             ll flag=0;
             string temp=s.substr(i,4);
             if(temp=="KICK") {
                 cnt++;
                 i+=2;

             }
            
                

             
             

         }
         else if(s[i]=='S' && i+4<n)
         {
              string temp=s.substr(i,5);
                 if(temp=="START") 
                 {
                     ans+=cnt;
                     i+=4;
                 }

         }
    }

    cout<<"Case #"<<tt<<": "<<ans<<endl;

        
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
 