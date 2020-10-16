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
        ll n,M;
        cin>>n>>M;
        vector<ll> freq(105,0);
        


        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        ll sum=0;

        for(ll i=1;i<=n;i++)
        {
             sum+=a[i];
             if(sum<=M) cout<<"0"<<" ";
             else {
                 ll need=(sum-M);
                 ll cnt=0;

                 for(ll i=100;i>=1;i--)
                 {
                     if(freq[i]*i>=need)
                     {
                          cnt+=(need+i-1)/i;
                          break;
                     }
                     else{

                         need-=freq[i]*i;
                         cnt+=freq[i];

                     }
                      
                 }

                 cout<<cnt<<" ";


             }
             freq[a[i]]++;

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
 