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
bool check(string s)
{
     ll flag=0;
     ll n=s.size();
     for(ll i=0,j=n-1;i<j;i++, j--)
     {
          if(s[i]!=s[j]) return true;
     }
     return false;

}


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
       

      cout << 3 << endl;
	cout << "L " << 2 << endl;
	cout << "R " << 2 << endl;
	cout << "R " << 2 * n - 1 << endl;
        

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
 