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
ll a[100005];
ll pre[100005];



int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;

        for(ll i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];


        ll day=1;
        ll flag=0;


      while(day<=n)
        {
            if(pre[day]<day*k)
            {
                 cout<<day<<endl;
                 flag=1;

                 break;
            }
            else {
                day=(pre[day]+k-1)/k;
                day=min(day,n);
                if(pre[day]%k==0) day++;

                  
                if(day==n) break;
            }
             
        }

        if(flag==0)
        {
            ll val=(pre[n]+k-1)/k;
            if(pre[n]%k==0) val++;
            cout<<val<<endl;
            



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
 