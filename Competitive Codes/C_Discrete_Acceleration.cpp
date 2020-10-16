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
#define factor 1e6
ll power(ll a, ll b);
double flag[100005];
 ll  n,l;

double get_left(double T)
{
      double speed=1;
      double dis=0;
      for(ll i=0;i<n;i++)
      {
            double t=(flag[i]-dis)/speed;

            if(t<T)
            {
                  T-=t;
                  speed++;
                  dis=flag[i];
            }
            else {
                 return  dis + speed*T;
            }
      }

      return dis+speed*T;

}

double get_right(double T)
{
      double speed=1;
      double dis=l;
      for(ll i=n-1;i>=0;i--)
      {
            double t=(dis-flag[i])/speed;

            if(t<T)
            {
                  T-=t;
                  speed++;
                  dis=flag[i];
            }
            else {
                 return  dis - speed*T;
            }
      }

      return dis-speed*T;
      
}

bool check(double key)
{
   //  cout<<get_left(key)<<" "<<get_right(key)<<endl;


     if(get_left(key)>=get_right(key)) return true;
     else return false;
     //return false;

   

     
}


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
      
      
        cin>>n>>l;
 
        for(ll i=0;i<n;i++)  cin>>flag[i];

        double low=0,high=l;

        double ans=0;
       // cout<<check(0.625)<<endl;




        for(ll i=1;i<=100;i++)
        {
             double mid=(low+high)/2;
            // dbg(mid);

             if(check(mid))
             {
                //  dbg(ans);

                  ans=mid;
                  high=mid;
                   
             }
             else {
                  low=mid;

             }
              
        }

        cout<<setprecision(8)<<fixed;


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
 