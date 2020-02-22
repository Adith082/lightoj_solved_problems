//BISMILLAH
//RABBI ZIDNI ILMA
//I tried to solve this problem using topological indegree concept and dfs
//HAPPY CODING
#include <bits/stdc++.h>
using namespace std;
#define sz 10009
int vis[sz];
map <int,int> mm;
map <int,int> nn;
map <int,int> cc;
vector <int> xx[sz];
vector <int> adj[sz];
vector <int> vv[sz];
int counter = 0;
int check[sz];
int temp[sz];
int h = 1;
int indeg[sz];
queue <int> q;
void topo_init(int n){
    int i,j;
     for(i = 0;i<n;i++){
         if(indeg[i] == 0){
             q.push(i);
         }
     }
}
int topo_sort(int n){
    int i,j,x;
    int cnt = 0;
    if(q.empty() == 1) return 0;
    else{
          while(!q.empty()){
              mm[q.front()] = 1;
              cnt++;
              q.pop();
          }
          return cnt;
    }
}
void dfs(int x){
    int i,j;
    vis[x] = 1;
    if(mm[x] == 1) 
    {
        xx[h].push_back(x);
        nn[h] = 1;
    }
    cc[h]++;
    for(i = 0;i<vv[x].size();i++){
        if(!vis[vv[x][i]]){
            dfs(vv[x][i]);
        }
    }
    return;
}
void real_dfs(int x){
           int i,j;
           check[x] = 1;
           counter++;
          for(i = 0;i<adj[x].size();i++){
              if(!check[adj[x][i]]){
                  real_dfs(adj[x][i]);
              }
          }
          return;
}
int main(){
    int i,j,res;
    int k,play = 0;
    int t,n,m,p,q;
    cin >> t;
    for(i = 1;i<=t;i++){
        cin >> n >> m;
        for(j = 0;j<m;j++){
            cin >> p >> q;
            adj[p-1].push_back(q-1);
            vv[p-1].push_back(q-1);
            vv[q-1].push_back(p-1);
            indeg[q-1]++;
        }
        topo_init(n);
        res = topo_sort(n);
        for(j = 0;j<n;j++){
            if(vis[j] == 0){
                dfs(j);
                h++;
            }
        }
        h--;
        for(j = 1;j<=h;j++){
            if(nn[j] == 0) res++;
            else if(nn[j] == 1){
                for(k = 0;k<xx[j].size();k++){
                     real_dfs(xx[j][k]);
                     play += counter;
                     counter = 0;
                }
                if(play != cc[j]) res++;
                play = 0;
                counter = 0;
            }
        }
      
         cout << "Case " << i << ": " << res << endl;
         memset(indeg,0,sizeof(indeg));
         memset(vis,0,sizeof(vis));
         memset(check,0,sizeof(check));
         for(j = 0;j<sz;j++){
             vv[j].clear();
             adj[j].clear();
             xx[j].clear();
         }
       h = 1;
       mm.clear();
       nn.clear();
       cc.clear();
       play = 0;
       counter = 0;
    }
    return 0;
}
