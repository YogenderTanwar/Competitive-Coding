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
ll a[5000];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k,x,y;
        cin>>n>>k>>x>>y;
        k=k%n;
        
        if(k==0)
        {
             if(x==y) cout<<"YES"<<endl;
             else cout<<"NO"<<endl;
             continue;
             
        }
         ll cnt=0;
         ll val=x;
         ll flag=0;



        for(;cnt<=1000;cnt++)
        {
              val=(val+k)%n;
             // dbg(val);

             if(val==y) 
             {
                 flag=1;
                 break;
             }
        }

        

        if(flag) cout<<"YES"<<endl;
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
 