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
vector<ll> gr[100004];
ll a[100004];
set<ll> tot;



ll shortest_cycle(ll n) 
{ 
    // To store length of the shortest cycle 
    ll ans = inf; 
  
    // For all vertices 
   for(auto i: tot) { 
  
        // Make distance maximum 
        vector<ll> dist(n, (ll)(1e18)); 
  
        // Take a imaginary parent 
        vector<ll> par(n, -1); 
  
        // Distance of source to source is 0 
        dist[i] = 0; 
        queue<ll> q; 
  
        // Push the source element 
        q.push(i); 
  
        // Continue until queue is not empty 
        while (!q.empty()) { 
  
            // Take the first element 
            ll x = q.front(); 
            q.pop(); 
  
            // Traverse for all it's childs 
            for (ll child : gr[x]) { 
  
                // If it is not visited yet 
                if (dist[child] == (ll)(1e18)) { 
  
                    // Increase distance by 1 
                    dist[child] = 1 + dist[x]; 
  
                    // Change parent 
                    par[child] = x; 
  
                    // Push llo the queue 
                    q.push(child); 
                } 
  
                // If it is already visited 
                else if (par[x] != child and par[child] != x) 
                    ans = min(ans, dist[x] + dist[child] + 1); 
            
            } 
            if(ans==3)
            {
                return ans;

            }
           // dbg(ans);

        } 
    } 
  
    // If graph contains no cycle 
    if (ans == 1e18) 
        return -1; 
  
    // If graph contains cycle 
    else
        return ans; 
} 
set<pair<ll,ll> > s;





int main()
{
    fast
    ll t = 1; 
    //cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll neg=0;
        for(ll i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(a[i]%2) neg++;
        }
        if(neg>=3)
        {
             cout<<"3";
             return 0;
        }

        for(ll i=0;i<62;i++)
        {
             ll cnt=0;
             vector<ll> b;
             for(ll j=1;j<=n;j++) 
             {
                  if(( (1ll<<i) & a[j])) b.push_back(j);
             }
             if(b.size()>=3) 
             {
                 //  cout<<"sdefr";
                  cout<<"3"<<endl;
                  return 0;

             }
             if(b.size()==2)
             {
                

                 if(s.count({b[0],b[1]})) continue;
                 tot.insert(b[0]);
                 tot.insert(b[1]);

                //  cout<<b[1]<<" "<<b[0]<<endl;

                 gr[b[0]].push_back(b[1]);
                 gr[b[1]].push_back(b[0]);
                 s.insert({b[0],b[1]});
                  s.insert({b[1],b[0]});


             }

        }
      


        cout << shortest_cycle(n+1); 




        
      
        
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
 