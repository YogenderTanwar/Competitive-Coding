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


ll power(ll a, ll b);
 string s;
set<ll> arr[26];
ll size=s.size();

ll ft[200004];



void update(ll pos, ll delta)
{
    while(pos<=size) 
    {
        ft[pos]+=delta;
        pos+=(pos & -pos);

       


         
    }
     
}

ll query(ll pos)
{
    ll sum=0;

     while(pos>0)
     {
         sum+=ft[pos];
         pos-=(pos&-pos);
          
     }
     return sum;
}

 ll check()
 {
     ll need=0;
     string b;
     b=s;
     reverse(all(b));
     ll cnt=0;


     for(ll i=0;i<s.size();i++)
     {
         ll val=*arr[b[i]-'a'].begin();
         
         arr[b[i]-'a'].erase(arr[b[i]-'a'].begin());
         val++;
      //   dbg(val);
       



         
         
         ll  large=cnt-(query(val));
        // cout<<val<<" "<<large<<" "<<query(val)<<endl;


        update(val,1);
        cnt++;

         
         ll j=val+large-1;
        // dbg(j);

          need+=(j-i);
//                   s.erase(s.begin()+j);
//                    string c;
//                    c+=b[i];
//                   s.insert(i,c);
//         
         
         // cout<<need<<" "<<val<<endl;
          

     }

    return need;

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
       size=n;


        cin>>s;
       

        for(ll i=0;i<n;i++) 
        {
        	arr[s[i]-'a'].insert(i);
        }
        cout<<check();

    //   update(2,10);
    //    update(3,20);

    //    cout<<query(4)<<endl;



        

       


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
 