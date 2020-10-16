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
ll a[100];


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;

        ll sum=0;
          vector<ll> pos,neg,zero;
          ll cnt_pos=0,cnt_neg=0;

        for(ll i=1;i<=n;i++)
        {
             cin>>a[i];
             sum+=a[i];
             if(a[i]>0) pos.push_back(a[i]), cnt_pos+=a[i];
             else if(a[i]<0) neg.push_back(a[i]), cnt_neg+=abs(a[i]);
             else zero.push_back(a[i]);
        }
      

        if(sum==0) 
        {
             cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            sort(all(pos));
            sort(all(neg), greater<ll> ());

           if(cnt_pos>cnt_neg)
           {
                for(auto x: pos) cout<<x<<" ";
            for(auto x: neg) cout<<x<<" ";

           }
           else {
                for(auto x: neg) cout<<x<<" ";
                for(auto x: pos) cout<<x<<" ";

           }
           
            for(auto x: zero) cout<<x<<" ";
            cout<<endl;
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
 