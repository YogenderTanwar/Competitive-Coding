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
        string a,b;
        cin>>a>>b;
        vector<pair<char,ll> > cnta,cntb;
        ll cnt=0;


        for(ll i=0;i<a.size();i++)
        {
            if(i==0) cnt++;
            else if(a[i]==a[i-1]) cnt++;
            else {
                cnta.push_back({a[i-1],cnt});
                cnt=1;
            }

             
        }

        if(cnt>0) cnta.push_back({a.back(),cnt});

        cnt=0;
          for(ll i=0;i<b.size();i++)
        {
            if(i==0) cnt++;
            else if(b[i]==b[i-1]) cnt++;
            else {
                cntb.push_back({b[i-1],cnt});
                cnt=1;
            }

             
        }
         if(cnt>0) cntb.push_back({b.back(),cnt});

         if(cnta.size()!=cntb.size()) cout<<"NO"<<endl;
         else {
             ll flag=0;
             for(ll i=0;i<cnta.size();i++)
             {
                 if(cnta[i].F==cntb[i].F && cntb[i].S>=cnta[i].S);
                 else {
                     flag=1;
                     break;
                 }

             }
             if(flag) cout<<"NO"<<endl;
             else cout<<"YES"<<endl;
             
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
 