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
        string s;
        cin>>s;
        ll n=s.size();

        ll st=0,e=n-1;
        ll ans=0;
        ll cnt_a=0,cnt_b=0;
        while(st<n && s[st]=='B') {
            st++;

        }
        if(st==n) 
        { 
           if(n%2==0) cout<<"0"<<endl;
            else cout<<"1"<<endl;
        }
        else {
            while(e>=0 && s[e]=='A')
            {
                e--;

            }
          
            ll temp=st%2;
          //  dbg(st);




           vector<ll> space;
           space.push_back(st);

          
           ll cnt=0;


           for(ll i=st;i<n&&i<=e;i++)
           {
               if(s[i]=='A' )
               {
                   if(i!=st)
                   {
                         space.push_back(cnt);
                   cnt=0;

                   }
                 

               }
               else {
                   cnt++;

               }
               //dbg(cnt);


           }
           if(cnt>0) space.push_back(cnt);
             ll ans=n-1-e;
             ll tot=0;

            //  for(auto x: space) cout<<x<<" ";
            //  cout<<endl;


             for(ll i=space.size()-1;i>0;i--)
             {

                tot+=space[i];
                if(tot==0) ans++;
                else tot--;
               // dbg(ans);


             }

             tot+=space[0];

             if(tot%2) ans++;

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
 