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
        ll n,k;
        cin>>n>>k;
        priority_queue<ll> p;

        for(ll i=1;i<=n;i++)
        {
            ll ele;
            cin>>ele;
            p.push(ele);


        }

        while(p.size()!=k)
        {
            ll val=p.top();
            p.pop();
            if(val%2)
            {
                 ll temp=val/2;
                  p.push(temp);
                  p.push(temp+1);

            }
            else if(p.size()+2!=k){
                 ll temp=val/2;
                    p.push(temp-1);
                  p.push(temp+1);

            }
            else {
                 ll temp=val/2;
                  p.push(temp);
                  p.push(temp);

            }
          

        }

        ll ans=0;
        while(!p.empty()) 
        {
            ll val=p.top();
            p.pop();
            ans+=(val*val);

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
 