#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
ll power(ll a, ll b);
char s[1005][1005];
ll vis[1005][1005];
ll moves[1005][1005];

ll dis[1005][1005];
ll dx[4] = { -1, 0, 1, 0};
ll dy[4] = {0, 1, 0, - 1};
ll n,m;


bool check(ll x, ll y)
{

	if (x < 1 || x > n || y < 1 || y > m) return false;

	if (vis[x][y] || s[x][y] == '#') return false;

	return true;

}

void bfs(ll sx, ll sy)
{

	queue<pair<ll, ll> > q;
	q.push({sx, sy});
	vis[sx][sy] = 1;

	while (!q.empty())
	{
		ll currx = q.front().F;
		ll curry = q.front().S;
		q.pop();

		for (ll i = 0; i < 4; i++)
		{
			if (check(currx + dx[i], curry + dy[i]))
			{
				
				ll nx = currx + dx[i], ny = curry + dy[i];
                moves[nx][ny]=i;

				dis[nx][ny] = dis[currx][curry] + 1;
				vis[nx][ny] = 1;

				q.push({nx, ny});

			}
		}
	}

}





int main() {


	jaldi_chal
	ll t = 1, i;
	//cin >> t;
	while (t--)
	{

		cin >> n>>m;




		ll sx, sy;
		ll ex, ey;

		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= m; j++)
			{
				cin >> s[i][j];
				if (s[i][j] == 'A') sx = i , sy = j;
				if (s[i][j] == 'B') ex = i , ey = j;

			}

		}


		bfs(sx, sy);

		// for (ll i = 1; i <= n; i++)
		// {
		// 	for (ll j = 1; j <= n; j++)
		// 	{
		// 		cout << dis[i][j]  << " ";
		// 	}
		// 	cout << endl;

		// }

        if(dis[ex][ey])
        {
             cout<<"YES"<<endl<<dis[ex][ey]<<endl;

             ll x=ex,y=ey;
             string s;
            //  dbg(sx);
            //  dbg(sy);


             while(!(x==sx && y==sy))
             {
                 if(moves[x][y]==0) x++, s+='U';
                 else if(moves[x][y]==1) y--, s+='R';
                 else if(moves[x][y]==2) x--, s+='D';
                 else y++ ,s+='L';
                // cout<<x<<" "<<y<<endl;
               



             }
           //  cout<<moves[x][y]<<endl;

            // cout<<x<<" "<<y<<endl;


             reverse(all(s));

             cout<<s;


        }
        else cout<<"NO";
        


	







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