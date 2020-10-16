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
vector<ll> arr[100005];
ll vis[100005];

  ll n;
ll bfs()
{

    queue<ll> q;
    ll cnt=0;

    q.push(1);


    ll ans=1;
    cnt=1;
    vis[1]=1;



    while(!q.empty())
    {
        ll cnt2=0;
        while(cnt>0)
        {
            ll node=q.front();
           // dbg(node);

            q.pop();
            for(auto x: arr[node])
            {

                 if(vis[x]) continue;
                // dbg(x);

                  vis[x]=1;

                 cnt2++;
                 q.push(x);

            }
            cnt--;

            

        }
      //  dbg(cnt2);


        if(cnt2%2) ans++;
        cnt=cnt2;

         
    }

    return ans;





}


int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
      
        cin>>n;

        for(ll i=2;i<=n;i++)
        {
             ll u;
             cin>>u;
             arr[u].push_back(i);
             arr[i].push_back(u);

        }

        cout<<bfs();

        
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
 