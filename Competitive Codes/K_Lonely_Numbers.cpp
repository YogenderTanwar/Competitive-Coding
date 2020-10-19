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

ll prime[1000001];
vector<ll> p;

void seive()
{
	for(ll i=1;i<=1000000;i++) prime[i]=1;
	prime[1]=0;
	for(ll i=2;i*i<=1000000;i++)
	{
		if(prime[i])
		{
			for(ll j=i*i;j<=1000000;j=j+i)
			{
				
				prime[j]=0;
			}
		}
	}
    for(ll i=1;i<=1000000;i++) if(prime[i]) p.push_back(i);

	
}


int main()
{
    fast
    ll t = 1; 
    cin >> t;
    seive();

    
    while (t--)
    {
        ll n;
        cin>>n;
        set<ll> s;
        



        ll ans=(n+1)/2;
        if(n<=3) {
            cout<<n<<endl;
        }
        else {

        ll ans=1;

        ll i=0;
        while( i<p.size() && p[i]<=n)
        {
             if(p[i]*p[i]<=n) {
             i++;
             continue;
        }
             ans++;
             i++;


        }

        cout<<ans<<endl;


            

           



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
 