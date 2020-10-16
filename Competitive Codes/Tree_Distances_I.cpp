#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define MOD 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);
vector<ll> arr[300001];

ll a[300001],p[300001];

ll ans[300004];





void dfs(ll node, ll par)
{
    a[node]=0;
   

    ll x=0;


    for(auto child: arr[node])
    {
         if(child==par) continue;
         dfs(child,node);

         x=max(x,a[child]+1);

         

    }

    a[node]=(x);
    

} 


void dfs2(ll node,ll par, ll par_ans)
{

    vector<ll> prefix,suff;

    for(auto x: arr[node])
    {
         if(x==par) continue;
         prefix.push_back(a[x]);
         suff.push_back(a[x]);
    }
    ll len=prefix.size();

    for(ll i=1;i<prefix.size();i++) 
    {
          prefix[i]=max(prefix[i],prefix[i-1]);
    }

    for(ll i=len-2;i>=0;i--)
    {
         suff[i]=max(suff[i],suff[i+1]);
    }

    ll index=0;


    for(auto x: arr[node])
    {
        if(x==par) continue;
        ll left=(index==0)?-1:prefix[index-1];
        ll right=(index==len-1)?-1: suff[index+1];
        ll val=1+max(par_ans,max(left,right));

        dfs2(x,node,val);
        index++;

    }

    

    ans[node]=1+max(par_ans,prefix.empty()?-1:prefix.back());

   // cout<<node<<" "<<ans[node]<<" "<<par_ans<<endl;

    

}



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		REW(i, 1, n - 1)
		{
			ll u, v;
			cin >> u >> v;

			arr[u].push_back(v);
			arr[v].push_back(u);
		}
        dfs(1,-1);
       
        dfs2(1,0,-1);
        


        for(ll i=1;i<=n;i++) {
            //cout<<a[i]<<" ";
          cout<<ans[i]<<" ";


        }





	}


	return 0;
}


ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}