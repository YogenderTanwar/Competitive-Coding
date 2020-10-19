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
char a[300004];
// ll vis[300004];



int main()
{
    fast
    ll t = 1; 
    cin >> t;
    

    while (t--)
    {
        ll n;
        cin>>n;
      //  clr(vis);
        ll cl=0,anti=0, off=0;


        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]=='>') cl++;
            else if(a[i]=='<') anti++;
            else off++;


        }
        ll cnt=0;

        for(ll i=0;i<n;i++)
        {
             if(i==0 ) 
             {
                 if(a[n-1]=='-' || a[0]=='-') continue;
                 if((a[0]=='<' && a[n-1]=='>') ||( a[0]=='>' && a[n-1]=='<' )) cnt++;
                 else if(a[0]=='>' && anti>0) cnt++;
                 else if(a[n-1]=='<' && cl> 0) cnt++;

                 
             }
             else if(i==n-1)
             {
                  if(a[n-1]=='-' || a[n-2]=='-') continue;
                 if((a[n-2]=='<' && a[n-1]=='>') ||( a[n-2]=='>' && a[n-1]=='<' )) cnt++;
                 else if(a[n-2]=='>' && anti>0) cnt++;
                 else if(a[n-1]=='<' && cl> 0) cnt++;

             }
             else {
                  if(a[i]=='-' || a[i-1]=='-'  ) continue;
                 if((a[i]=='<' && a[i-1]=='>') ||( a[i]=='>' && a[i-1]=='<' )) cnt++;
                 else if(a[i]=='>' && anti>0) cnt++;
                 else if(a[i-1]=='<' && cl> 0) cnt++;

             }
        }

        cout<<n-cnt<<endl;




        
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
 