//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 700
int cost[sz];
int maxx = -1;
vector <int> adj[sz];
vector <int> weight[sz];
int vis[sz];
int par[sz];
struct edge{
    int u,v,w;
};
vector <edge> vv;
bool cmp(edge A,edge B){
    return A.w < B.w;
}
int findd(int r){
    if(par[r] == r) return r;
    return par[r] = findd(par[r]);
}
void mst(int n){
     
     int i,j;
     int x,y;
     int countt = 0;
     for(i = 0;i<n;i++) par[i] = i;
     sort(vv.begin(),vv.end(),cmp);
     int len = vv.size();
     for(i = 0;i<len;i++){
         x = findd(vv[i].u);
         y = findd(vv[i].v);
         if(x!=y){
             par[x] = y;
             adj[x].push_back(y);
             adj[y].push_back(x);
             weight[x].push_back(vv[i].w);
             weight[y].push_back(vv[i].w);
             countt++;
             if(countt == n-1) break;
         }
     }
}
void bfs(int source){
    queue <int> q;
    int i,j,x;
    int len;
    q.push(source);
    vis[source] = 1;
    cost[source] = 0;
    while(!q.empty()){
        x = q.front();
        q.pop();
        len = adj[x].size();
        for(i = 0;i<len;i++){
            if(!vis[adj[x][i]]){
                vis[adj[x][i]] = 1;
                q.push(adj[x][i]);
                if(weight[x][i]>=cost[x]){
                    cost[adj[x][i]] = weight[x][i];
                }
                else{
                    cost[adj[x][i]] = cost[x];
                }
            }
        }
    }
    return;
}
int main(){
    edge get;
    int t;
    int res;
    int tt;
    int p,q,c;
    int i,j;
    int n,m;
    scanf("%d",&t);
    for(i = 1;i<=t;i++){
        maxx = -1;
        scanf("%d %d",&n,&m);
        for(j = 1;j<=m;j++){
             scanf("%d %d %d",&p,&q,&c);
             get.u = p;
             get.v = q;
             get.w = c;
             vv.push_back(get);
        }
        mst(n);
        scanf("%d",&tt);
        bfs(tt);
        printf("Case %d:\n",i);
        for(j = 0;j<n;j++){
            if(vis[j] == 0){
                printf("Impossible\n");
            }
            else{
                res = cost[j];
                printf("%d\n",res);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));
        vv.clear();
        for(j = 0;j<n;j++){
            adj[j].clear();
            weight[j].clear();
        }
    }
    return 0;
}