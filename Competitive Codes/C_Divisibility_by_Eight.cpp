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
        string s;
        cin>>s;

        ll cnt=0;
        ll n=s.size();

        for(ll i=0;i<n;i++) 
        {
            if(s[i]=='0' || s[i]=='8') 
            {
               cout<<"YES"<<endl;

            cout<<s[i]<<endl;
            return 0;
            
            }
        }
       {

            for(ll i=0;i<n;i++)
            {
                ll val=((s[i]-'0')*100);
                ll val1=(s[i]-'0')*10;

                if(s[i]=='8')
                {
                    cout<<"YES"<<endl;
                    cout<<"8"<<endl;
                    return 0;

                }


                 for(ll j=i+1;j<n;j++)
                 {
                     val+=(s[j]-'0')*10;
                     val1+=(s[j]-'0');
                      for(ll k=j+1;k<n;k++)
                     {
                         val+=(s[k]-'0');
                       //  dbg(val);


                         if(val%8==0)
                         {
                             cout<<"YES"<<endl;
                             cout<<val<<endl;
                             return 0;

                         }
                         val-=(s[k]-'0');

                     }
                     val-=(s[j]-'0')*10;
                     if(val1%8==0)
                     {
                          cout<<"YES"<<endl;
                             cout<<val1<<endl;
                             return 0;

                     }
                     val1-=(s[j]-'0');


                 }
            }

            cout<<"NO"<<endl;
            return 0;


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
 