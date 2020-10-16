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
const ll inf1 = 1e18;
ll power(ll a, ll b);
vector<pair<ll,pair<ll,ll> > >  a;


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll cnt=0;
        a.clear();


        ll prev=-1;
        ll index=-1;

        for(ll i=0;i<n;i++) 
        {
            if(s[i]=='W')
            {
                if(index==-1) index=i;
                if(prev==-1) prev=i+1;
                else {
                    if(cnt>0)
                    {
                        a.push_back({cnt,{prev,i-1}});
                    }
                    prev=i+1;

                    cnt=0;

                   

                }


            }
            else {
                if(prev!=-1)
                {
                    cnt++;

                }
            }
        }
        ll index2=prev;

      

        for(ll i=0;i<a.size();i++)
        {
           

            ll cost=a[i].F;
           //  dbg(cost);
            if(k>=cost) 
            {
                k-=cost;
                ll se=a[i].S.F;
                ll e=a[i].S.S;
                for(ll j=se;j<=e;j++) s[j]='W';
                a[i].F=inf1;

            }
        }
        if(k>0)
        {
            sort(all(a));
            for(ll i=0;i<a.size();i++)
        {
            ll cost=a[i].F;
            if(cost==inf1) break;
            if(k>0 && cost>0) 
            {
                ll z=min(k, cost);
                k-=z;
            
                ll se=a[i].S.F;
                ll e=a[i].S.S;
                for(ll j=se;j<se+z;j++) s[j]='W';
                a[i].F=-1;

            }
            if(k==0) break;
        }

       





        }

        if(k>0)
        {
            if(index==-1) index=n;

             for(ll i=index-1;i>=0;i--)
             {
                  if(k>0) s[i]='W', k--;

             }

             if(k>0 && index2!=-1)
             {
                 for(ll i=index2;i<n;i++)
                 {
                    if(k>0) s[i]='W', k--;
                 }
                 
             }
        }
      //   cout<<s<<endl;

         ll ans=0;
         prev=-1;
        for(ll i=0;i<n;i++)
        {
            
             if(s[i]=='W')
             {
                 if(prev==-1) ans++ , prev=i;
                 else {
                     if(prev==i-1) ans+=2;
                     else ans++;

                     prev=i;
                 }
             }
             //dbg(ans);

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
 