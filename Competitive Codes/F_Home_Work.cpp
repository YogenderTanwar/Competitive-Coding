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
        string s;
        cin>>s;

       ll n=s.size();

       ll dp[n+1][26];
       clr(dp);

       dp[0][s[0]-'a']=1;


       for(ll i=1;i<n;i++)
       {
            ll val=s[i]-'a';
           dp[i][s[i]-'a']++;

           ll mx=-1;

        for(ll j=0;j<26;j++)
        {
             mx=max(dp[i-1][j],mx);
             dp[i][j]=max(dp[i][j],dp[i][j]+mx);
             cout<<dp[i][j]<<" ";


        }      
        cout<<endl;

            
       }

       ll ans=0;
       for(ll i=0;i<26;i++) ans=max(ans,dp[n-1][i]);
       ll len=ans;
       string res;
        ll index=25;
       for(ll i=0;i<26;i++) 
       {
            if(dp[n-1][i]==ans) 
            {
                index=i;
                break;
            }
       }
       res+=char('a'+index);
       len--;

      
       cout<<ans<<endl;



       for(ll i=n-1;i>=0;i--)
       {
            if(len==0) break;
            for(ll j=index;j>=0;j--)
            {
                if(dp[i][j]==len)
                {
                    len--;
                    res+=char('a'+j);
                    index=j;
                    break;
                }
                 if(len==0) break;

            }
            // dbg(res);
            // cout<<len<<endl;


             if(len==0) break;

           
       }

       reverse(all(res));

       cout<<res<<endl;





        


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
 