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
 vector<ll> a;
void add(vector<ll> &temp , ll index)
{
    ll val=a[index];
   // dbg(val);


    for(ll i=0;i<5;i++)
    {
         if((1<<i) & val) 
         {
              temp[i]++;
         }
    }
     
}

bool check(vector<ll> temp, ll sum)
{
     ll val=sum/2;
    //  dbg(temp.size());
    //  dbg(val);


     //dbg(val);
     ll flag=0;


     for(ll i=0;i<temp.size();i++) 
     {
        // cout<<temp[i]<<" "<<val<<endl;


          if(temp[i]>val) {
              flag=1;
              break;
          }

     }
     //dbg(flag);

   if(flag) return false;
   else return true;

}

int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        set<ll> s;
      //  cout<<"asdfg";
       


        for(ll i=1;i<=n;i++)
        {
            
            ll p=1;
            ll val=0,ele;


            for(ll j=1;j<=k;j++)
            {
                cin>>ele;
                val+=(ele*p);
                p*=2;



            }
          //   dbg(val);

            if(!s.count(val)) s.insert(val),  a.push_back(val);
             
        }
        ll flag=0;

        n=a.size();
        // dbg(n);


        for(ll i=1;i<(1<<n);i++)
        {
            ll cnt=0;
            vector<ll> temp(10,0);

            for(ll j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                      add(temp,j);
                      cnt++;
                }
                  
            }
            // for(auto x: temp ) cout<<x<<" ";
            // cout<<endl;
            
         //   cout<<check(temp,cnt)<<endl;


            if(check(temp,cnt)==true)
            {
              // dbg(i);


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
 