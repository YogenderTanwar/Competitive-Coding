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
        ll n;
        cin>>n;

        string s;
        cin>>s;
        deque<ll> a;
        ll cnt=1;

        for(ll i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                a.push_back(cnt);
                cnt=1;

            }
            else cnt++;




        }
        if(cnt>0) a.push_back(cnt);
        ll sum=0;


        for(ll i=0;i<a.size();i++) a[i]--, sum+=a[i];


        ll ans=0;
         cnt=0;


        for(ll i=0;i<a.size();i++)
        {
            cnt++;
            if(cnt>sum)
            {
                ans+=(a.size()-i+1)/2;
                break;
            }
            ll z=min(cnt,a[i]);

            sum-=a[i];
            cnt-=z;

            ans++;
             
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
 