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
        ll n;
        cin>>n;
        vector<ll> a(n);
        map<ll,ll> index;
      


        for(ll i=0;i<n;i++) cin>>a[i], index[a[i]]=i+1;

        if(n<=3) 
        {
             cout<<"1"<<endl;
             return 0;
        }

        sort(all(a));
        // check 1 element 

        ll prev=a[2]-a[1];
        ll flag=0;

        for(ll i=3;i<n;i++)
        {
            if(a[i]-a[i-1]!=prev) 
            {
                flag=1;
                break;
            }

        }

        if(flag==0) 
        {
            cout<<index[a[0]];
            return 0;
        }

        // check 2 element 

        prev=a[2]-a[0];
        flag=0;

        for(ll i=3;i<n;i++)
        {
            if(a[i]-a[i-1]!=prev) 
            {
                flag=1;
                break;
            }

        }

        if(flag==0) 
        {
            cout<<index[a[1]];
            return 0;
        }


        ll d=a[1]-a[0];

        ll cnt=0;
        ll exp=-1;

        for(ll i=2;i<n;i++)
        {
             if(a[i]-a[i-1]!=d)
             { 
                 //cout<<"hello"<<endl;

                 if(cnt==0)
                 {
                     if(i+1==n)
                     {
                         cout<<index[a[n-1]];
                         return 0;
                     }
                      if(a[i+1]-a[i-1]!=d)
                  {
                       cout<<"-1";
                       return 0;
                  }
                  else {
                      exp=i;
                      cnt++;
                      i++;

                  }

                 }
                 else {
                     cout<<"-1";
                     return 0;
                 }
                 
             }
        }
       // dbg(exp);


        if(exp!=-1) 
        {
            cout<<index[a[exp]];

        }
        else cout<<"-1"<<endl;




       

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
 