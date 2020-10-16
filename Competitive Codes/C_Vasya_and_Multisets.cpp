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
 ll cnt[101];



int main() {


	jaldi_chal
	ll t = 1, i;
	// cin >> t;
	while (t--)
	{
        ll n;
        cin>>n;
        ll a[n+1];
        map<ll,ll> m;
       


        for(ll i=1;i<=n;i++) cin>>a[i], m[a[i]]++;

        for(auto x: m) 
        {
            cnt[x.S]++;
        }
      //  for(ll i=1;i<=5;i++) cout<<cnt[i]<<" ";



       char c[n+5];

       for(ll i=1;i<=n;i++) c[i]='C';

       if(cnt[1]%2==0)
       {
            ll need=cnt[1]/2;
           // dbg(need);


            for(ll i=1;i<=n;i++) 
            {
                 if(need>0 && m[a[i]]==1) 
                 {
                     need--;
                     c[i]='A';

                 }
            }
             for(ll i=1;i<=n;i++) 
            {
                if(c[i]=='C') c[i]='B';
            }

            cout<<"YES"<<endl;
            for(ll i=1;i<=n;i++) cout<<c[i];

       }
       else{
           ll flag=0;

           for(ll i=3;i<=100;i++) 
           {
                if(cnt[i]>0) 
                {
                    flag=1;
                    break;
                }
           }
           if(flag) 
           {
               ll need=cnt[1]/2;
               ll z=1;

                for(ll i=1;i<=n;i++) 
            {
                 if(need>0 && m[a[i]]==1 ) 
                 {
                     need--;
                     c[i]='A';
                    


                 }
                 else if( (z>0 && m[a[i]]>2)) {
                     z--;
                       c[i]='A';

                 }
            }
             for(ll i=1;i<=n;i++) 
            {
                if(c[i]=='C') c[i]='B';
            }

            cout<<"YES"<<endl;
            for(ll i=1;i<=n;i++) cout<<c[i];
                
           }
           else {
               cout<<"NO"<<endl;

           }





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