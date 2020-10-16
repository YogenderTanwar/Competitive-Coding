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
class fenwick
{
    public:
  vector<ll> ft;

    ll size;


     fenwick(ll n)
     {
         this->size=n;
         ft=vector<ll>(n+1,0);

       //  ft.assign(n+1,0);
        


     }

     void update(ll pos, ll delta)
     {
          while(pos<=size)
          {
               ft[pos]+=delta;
               pos+=(pos&(-pos));
          }
     }

     ll query(ll pos)
     { 
         ll sum=0;

          while(pos>0) 
          {
               sum+=ft[pos];
               pos-=(pos&(-pos));
          }
          return  sum;
     }


};





int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n,m,c;
        cin>>n>>m>>c;
        //dbg(c);

        fenwick obj(n);
        for(ll i=1;i<=m;i++)
        {
             char type;
             cin>>type;
             if(type=='Q')
             {
                 ll pos;
                 cin>>pos;
                 cout<<obj.query(pos)+c<<endl;

             }
             else {
                 ll pos1,pos2,delta;
                 cin>>pos1>>pos2>>delta;
                 obj.update(pos1,delta);
                   obj.update(pos2+1,-delta);


             }
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
 
