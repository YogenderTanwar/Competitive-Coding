#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n);
    for (int i = 0; i<n; i++) cin>>p[i];
    vector<int> deg(n);
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<i; j++) if (p[j]>p[i]) deg[i]++;
        for (int j = i+1; j<n; j++) if (p[j]<p[i]) deg[i]++;
    }
 
    int sum = 0;
    for (auto it: deg) sum+=it, cout<<it<<" ";
    
    vector<bool> can(sum+1);
    can[0] = true;
    for (auto it: deg)
    {
        for (int i = sum; i>=it; i--) if (can[i-it]) can[i] = true;
    }
 
    if (can[sum/2]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--) solve();
}