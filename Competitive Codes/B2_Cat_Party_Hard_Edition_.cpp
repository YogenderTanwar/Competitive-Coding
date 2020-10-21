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
ll cnt[100005];
map<ll,ll> freq;


bool check(ll n)
{
    ll cnt=0;
    ll val=-1;

    for(auto x: freq)
    {
        if(x.S>0) cnt++, val=x.F;
        if(cnt>2) return false;

    }
   // dbg(cnt);

         if(cnt==1)
         {
             
             if(freq[1]==n || (val==n && freq[val]==1)) return true;
             else return false;

              
         }
         else if(cnt==2){
             ll x=-1,y,cnt_a,cnt_b;

             for(auto i: freq)
             {
                  if(x==-1 && i.S>0)
                  {
                      x=i.F, cnt_a=i.S;
                  }
                  else if(i.S>0){
                      y=i.F, cnt_b=i.S;

                  }
             }
             if(y>x) 
             {
                 swap(x,y);
                 swap(cnt_a, cnt_b);

             }
            //  cout<<x<<" "<<cnt_a<<endl;
            //    cout<<y<<" "<<cnt_b<<endl;

            

             
             if((cnt_b==1 ) && (freq[x]*x==n-1)  || (freq[x - 1] * (x - 1) == n - x && freq[y] == 1))
             {
                  return true;

             }
             else return false;


         }
         else return false;
         
     
}



int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i], cnt[a[i]]++;

        for(ll i=1;i<=100000;i++)
        {
            if(cnt[i]>0)
             freq[cnt[i]]++;

        }

       

        for(ll i=n;i>=1;i--)
        {
             if(check(n))
             {
                  cout<<i<<endl;
                  return 0;
             }

             ll val=cnt[a[i]];
             freq[val]--;
             if(val-1>0) freq[val-1]++;
           //  dbg(i);
           

        






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
 