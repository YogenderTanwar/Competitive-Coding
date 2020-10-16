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
bool check(char c)
{
     if(c=='a'||c=='e'||c=='i'||c=='o' || c=='u') return false;
     return true;

}

int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        string s;
        cin>>s;

         ll prev=0;

        ll cnt=0;
        set<ll> b;
        ll n=s.size();


        for(ll i=0;i<n;i++) 
        {
            if(check(s[i]))
            {
                cnt++;
                b.insert(s[i]-'a');
                if(cnt>=3)
                {
                     if(b.size()>=2)
                     {
                          cout<<s.substr(prev,i-prev)<<" ";
                          prev=i;
                          cnt=1;
                          b.clear();
                          b.insert(s[i]-'a');

                     }
                }


            }
            else {
                cnt=0;
                b.clear();


            }

             
        }

        if(prev<=n-1)
        {

            cout<<s.substr(prev,n-prev);
             
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
 