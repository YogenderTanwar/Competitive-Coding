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
const ll inf = 1e10;
ll power(ll a, ll b);
vector<string> a;
  ll n,m;
ll check_n(ll pos)
{
     ll res=inf;

     for(ll i=1;i<=m;i++)
     {
          char c=a[pos][i-1];
          if(c>='0' && c<='9')
          {
              res=min(res,i-1);
              res=min(res,m-i+1);
          }

     }
   //  dbg(res);

     return res;
     
}

ll check_s(ll pos)
{
     ll res=inf;

     for(ll i=1;i<=m;i++)
     {
          char c=a[pos][i-1];
          if(c=='*' || c=='#' || c=='&')
          {
              res=min(res,i-1);
              res=min(res,m-i+1);
          }

     }
   //  dbg(res);

     return res;
     
}

ll check_a(ll pos)
{
     ll res=inf;

     for(ll i=1;i<=m;i++)
     {
          char c=a[pos][i-1];
          if(c>='a' && c<='z')
          {
              res=min(res,i-1);
              res=min(res,m-i+1);
          }

     }
     return res;
     
}


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
      
        cin>>n>>m;
        a.resize(n);

        for(ll i=0;i<n;i++)
        {
            cin>>a[i];

             
        }

        ll ans=inf;


        for(ll i=0;i<n;i++)
        {   
            ll res=0;  
            res+=check_n(i);

             for(ll j=0;j<n;j++)
             {
                 if(i==j) continue;
                 res+=check_s(j);

                 for(ll k=0;k<n;k++)
                 {
                     if(j==k || k==i) continue;
                     res+=check_a(k);
                    //  dbg(res);

                    //  if(res==1) 
                    //  {
                    //       cout<<i<<" "<<j<<" "<<k<<endl;

                    //  }

                     ans=min(ans,res);
                     res-=check_a(k);



                 }
                 res-=check_s(j);
             }
             res-=check_n(i);


            // dbg(res);

             //ans=min(ans,res);
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
 