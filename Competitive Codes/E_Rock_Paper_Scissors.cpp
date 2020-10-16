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
        ll a[3][10];
        ll b[3][10];


        for(ll i=1;i<=2;i++)
        {
             cin>>a[i][1]>>a[i][2]>>a[i][3];
             a[i][3+1]=a[i][1];
             a[i][5]=a[i][2];
             a[i][6]=a[i][3];

        }
         for(ll i=1;i<=2;i++)
        {
             for(ll j=1;j<=3;j++) b[i][j]=a[i][j], b[i][j+3]=a[i][j];

        }

        ll mx=0;

        for(ll i=1;i<=1;i++)
        {
              ll j=i+1;

                 
                 
                

                  ll val=min(a[1][i],a[2][j]);
                  if(abs(i-j)==1) mx+=val;
                  else if(abs(i-j)==2) mx-=val;
                  a[1][i]-=val;
                  a[2][j]-=val;
                  a[1][i+3]-=val;
                  a[2][j+3]-=val;
                  dbg(mx);




                  


                  j=i;
                  
                   
                   val=min(a[1][i],a[2][j]);
                  if(abs(i-j)==1) mx+=val;
                  else if(abs(i-j)==2) mx-=val;
                   a[1][i]-=val;
                  a[2][j]-=val;
                   a[1][i+3]-=val;
                  a[2][j+3]-=val;

                  j=i+2;
                  
                   val=min(a[1][i],a[2][j]);
                   dbg(val);

                  if(abs(i-j)==1) mx+=val;
                  else if(abs(i-j)==2) mx-=val;
                   a[1][i]-=val;
                  a[2][j]-=val;
                   a[1][i+3]-=val;
                  a[2][j+3]-=val;

                  dbg(mx);


             
        }

        cout<<mx<<endl;





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
 