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
ll a[105][105];
ll used[105][105];

// ll check(ll a,ll b,ll c,ll d)
// {
//      ll val=(a+b+c+d);
//      ll target=(val/4);
//      ll res=abs(target-a)+abs(target-b)+abs(target-c)+abs(target-d);
//      target++;

//      ll temp=abs(target-a)+abs(target-b)+abs(target-c)+abs(target-d);
//      return min(res,temp);

// }


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;

        for(ll i=1;i<=n;i++)
        {
             for(ll j=1;j<=m;j++)
             {
                  cin>>a[i][j];
             }
        }
        ll ans=0;
        clr(used);


        for(ll i=1;i<=n;i++)
        {
              for(ll j=1;j<=m;j++)
              {
                    if(used[i][j]) continue;
                    ll ei=n-i+1;
                    ll ej=m-j+1;
                    ll dx[4]={i,i,ei,ei};
                    ll dy[4]={j,ej,j,ej};
                    vector<ll> ele;

                    for(ll k=0;k<4;k++)
                    {
                         ll nx=dx[k],ny=dy[k];
                         if(!used[nx][ny])
                         {
                              used[nx][ny]=1;
                              ele.push_back(a[nx][ny]);
                               
                         }

                    }
                    sort(all(ele));

                    ll target=ele[ele.size()/2];
                    for(auto x: ele)
                    {
                                  ans+=(abs(target-x));
                    }
                   



              }
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
 