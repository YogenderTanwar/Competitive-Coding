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
vector<ll> arr[200004];
ll dp1[200004],dp2[200004] ;

//dp1 taking the elemeent 
//dp2 not taking the elemeent 

void dfs(ll node,ll par)
{
    vector<ll> pre,ele;


     for(auto x:arr[node])
     {
          if(x==par) continue;
        
          dfs(x,node);
          ll ans=max(dp1[x],dp2[x]);
          pre.push_back(ans);
          ele.push_back(x);
            // not take the node x
          dp2[node]+=ans;
     }

     for(ll i=1;i<pre.size();i++) pre[i]+=pre[i-1];
    //  cout<<endl;

    //  for(auto x: pre) cout<<x<<" ";
    //  cout<<endl;



     ll len=pre.size();
     // taking the element 

     for(ll i=0;i<pre.size();i++)
     {
         ll left=i-1;
        // dbg(left);

         if(left==-1) left=0;
         else left=pre[left];
         ll right=i+1;
         if(right==len) right=0;
         else right=pre[len-1]-pre[i];
        //  dbg(left);
        //  dbg(right);

         dp1[node]=max(dp1[node],left+right+dp2[ele[i]]+1);

     }

    // cout<<node<<" "<<dp1[node]<<" "<<dp2[node]<<" "<<pre.size()<<endl;





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

        for(ll i=1;i<n;i++) 
        {
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v) , arr[v].push_back(u);

        }

        dfs(1,-1);

     cout<<max(dp1[1],dp2[1])<<endl;

    //    for(ll i=1;i<=n;i++) 
    //    {
    //         cout<<dp1[i]<<" "<<endl;

    //    }




        
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
 