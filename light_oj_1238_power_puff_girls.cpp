#include <bits/stdc++.h>
using namespace std;
int rr[] = {1,-1,0,0};
int cc[] = {0,0,1,-1};
int adj[20][20];
int col1[20][20];
void init(int m,int n)
{
    int i,j;
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            col1[i][j] = 0;
        }
    }
    return;
}
int bfs(int x1,int y1,int m,int n)
{
    int countt = 0;
    int i,j;
    int x,y,u,v;
    queue <pair<int,int> > q1;
    q1.push({x1,y1});

    while(!q1.empty())
    {
        x = q1.front().first;
        y = q1.front().second;
        q1.pop();
        if(adj[x][y] == 1)
        {
            return col1[x][y];
        }
        for(i = 0;i<4;i++)
        {
            u = x + rr[i];
            v = y + cc[i];
                if(u<0 || u>=m || v<0 || v>=n || col1[u][v])
              continue;
              if(adj[u][v] == 0 || adj[u][v] == 1)
             {
                 q1.push({u,v});
                 col1[u][v] = col1[x][y] + 1;
        }
    }
}
}
int main()
{
    char s;
    int j,k;
    int t,i,dest1,dest2;
    int m,n,x1,y1,x2,y2,x3,y3;
    cin >> t;
    for(i = 1;i<=t;i++)
    {
        cin >> m >> n;
        init(m,n);
         adj[m][n];
        for(j = 0;j<m;j++)
        {
            for(k = 0;k<n;k++)
            {
               cin >> s;
               if(s == '.') adj[j][k] = 0;
               else if(s == '#' || s == 'm') adj[j][k] = 2;
               else if(s == 'h')
               {
                   adj[j][k] = 1;
                   dest1 = j;
                   dest2 = k;
               }
               else if(s == 'a')
               {
                   adj[j][k] = 0;
                   x1 = j;
                   y1 = k;
               }
               else if(s == 'b')
               {
                   adj[j][k] = 0;
                   x2 = j;
                   y2 = k;
               }
               else if(s == 'c')
               {
                   adj[j][k] = 0;
                   x3 = j;
                   y3 = k;
               }
            }
        }
        int aa = bfs(x1,y1,m,n);
        init(m,n);
        int res = bfs(x2,y2,m,n);
        init(m,n);
        int ma = max(aa,res);
        int jk = bfs(x3,y3,m,n);
        init(m,n);
        int result = max(ma,jk);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
