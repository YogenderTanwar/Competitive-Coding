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
 string ans;

 void solve(ll n)
 {
      if(n==0) ans+='R';
      else if(n==1) ans+='G';
      else ans+='B';
 }


int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
        ll n;
        cin>>n;
        string s;
        cin>>s;

        ll dp[n+1][3];

        for(ll i=0;i<n;i++)
        {
             for(ll j=0;j<3;j++) dp[i][j]=1;

        }
        //RGB


        if(s[0]=='R') dp[0][0]=0;
        else if(s[0]=='G') dp[0][1]=0;
        else dp[0][2]=0;

        for(ll i=1;i<n;i++)
        {
             if(s[i]=='R') dp[i][0]=0;
        else if(s[i]=='G') dp[i][1]=0;
        else dp[i][2]=0;

            dp[i][0]+=(min(dp[i-1][1],dp[i-1][2]));
              dp[i][1]+=(min(dp[i-1][0],dp[i-1][2]));
                dp[i][2]+=(min(dp[i-1][1],dp[i-1][0]));

    //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;


             
        }
        ll res=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));



        cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;

       
        ll prev=-1;
         

        if(res==dp[n-1][0]) prev=0;
        else if(res==dp[n-1][1]) prev=1;
        else prev=2;

        solve(prev);

        for(ll i=n-2;i>=0;i--)
        {
            ll temp=inf;
            ll index;
            for(ll j=0;j<3;j++) 
            {
                if(j==prev) continue;
                if(dp[i][j]<temp) temp=dp[i][j], index=j;
                
            }
            prev=index;
            solve(prev);

             
        }

        reverse(all(ans));

        cout<<ans<<endl;



        












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