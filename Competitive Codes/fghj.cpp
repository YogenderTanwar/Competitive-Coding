#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
#define jaldi_chal  ios_base::sync_with_stdio(0); cin.tie(0);
#define tr(c,i) for(auto i=(c).begin(); i != (c).end(); i++)
#define REP(i,k) for( ll i=0;i<k;i++)
#define REW(i,a,b) for(ll i=a;i<=b;i++)
#define M 1000000007
#define F first
#define dbg(x)  cout<<#x<<" " <<x<<endl;
#define S second
#define inf 1e10
#define endl "\n"


int main() {
jaldi_chal
ll t,i;
ll a[]={9,16,21,18,28};

ll sum=0;
for(ll i=0;i<5;i++)
{
	ll val=0;
	for(ll j=i;j<5;j++)
	{
		val+=a[j];
		sum+=val;
	}
	cout<<sum<<" "<<i<<endl;
	
}

cout<<sum<<endl;
	return 0;
}
