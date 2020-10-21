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
ll dis1[1005][1005];

ll dx[4] = { -1, 0, 1, 0};
ll dy[4] = {0, 1, 0, - 1};
ll n,m;
ll ex,ey;



bool check(ll x, ll y)
{

	if (x < 1 || x > n || y < 1 || y > m) return false;

	if (vis[x][y] || s[x][y] == '#' || s[x][y]=='M') return false;

	return true;

}

bool bfs(ll sx, ll sy)
{

	queue<pair<ll, ll> > q;
	q.push({sx, sy});
	vis[sx][sy] = 1;

    


    if(((sx==1 || sx==n  || sy==1 || sy==m)) && dis1[sx][sy]<dis[sx][sy])
                {
                    ex=sx;
                    ey=sy;
                    return true;
                }

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

				dis1[nx][ny] = dis1[currx][curry] + 1;
				vis[nx][ny] = 1;

				q.push({nx, ny});
                   //cout<<nx<<" "<<ny<<" "<<dis1[nx][ny]<<" "<<dis[nx][ny]<<endl;

               

                if(((nx==1 || nx==n  || ny==1 || ny==m)) && dis1[nx][ny]<dis[nx][ny])
                {
                    ex=nx;
                    ey=ny;
                    return true;
                }


			}
		}
	}

    return false;


}





int main() {


	jaldi_chal
	ll t = 1, i;
	//cin >> t;
	while (t--)
	{

		cin >> n>>m;




		ll sx, sy;
		
        queue<pair<ll,ll> > q;



		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= m; j++)
			{
				cin >> s[i][j];
                dis[i][j]=inf;
				if (s[i][j] == 'A') sx = i , sy = j;
				if (s[i][j] == 'M') {
                    dis[i][j]=0;
                    q.push({i,j});
                    
                }

			}

		}

        // if(q.empty())
        // {
        //     memset(dis,-1,sizeof dis);

        // }


        while(!q.empty())
        {
            ll currx = q.front().F;
		ll curry = q.front().S;
		q.pop();

        for(ll i=0;i<4;i++)
        {
            ll nx=currx+dx[i], ny=curry+dy[i];
            if(check(nx,ny) && dis[nx][ny]>=1+dis[currx][curry])
            {
                dis[nx][ny]=1+dis[currx][curry];
                q.push({nx,ny});
            }

        }

       


            
        }

        //  for(ll i=1;i<=n;i++)
        // {
        //      for(ll j=1;j<=m;j++) 
        //      {
        //          cout<<dis[i][j]<<" ";

        //      }
        //      cout<<endl;

        // }


		

		

        if(bfs(sx, sy))
        {
             cout<<"YES"<<endl<<dis1[ex][ey]<<endl;

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