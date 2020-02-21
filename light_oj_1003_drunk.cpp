// BISMILLAH
// ALLAH THE MOST MERCIFUL
// RABBBI ZIDNI ILMA 
#include <bits/stdc++.h>
using namespace std;
#define sz 100000
map <string,int> mm;
map <string,int> str;
vector <int> adj[sz];
int vis[sz];
int indeg[sz];
queue <int> q;
void topo_init(int n){
    int i,j;
    for(i = 0;i<n;i++){
         if(indeg[i] == 0) 
         {
             q.push(i);
             vis[i] = 1;
         }
    }
}
int topo_sort(int n){
    int i,j,x;
    int cnt = 0;
    if(q.empty() == 1) return 1;
    while(!q.empty()){
      x = q.front();
      q.pop();
      cnt++;
      for(i = 0;i<adj[x].size();i++){
          if(!vis[adj[x][i]] && --indeg[adj[x][i]] == 0){
             q.push(adj[x][i]);
          }
      }
    }
    if(n == cnt) return 0;
    else return 1;
}
int main(){
   int i,j,res;
   int m,t;
   int h = 0;
   string p,g;
   cin >> t;
   for(i = 1;i<=t;i++){
       cin >> m;
       for(j = 0;j<m;j++){
           cin >> p >> g;
           mm[p]++;
           mm[g]++;
           if(mm[p] == 1) str[p] = h++;
           if(mm[g] == 1) str[g] = h++;
           adj[str[p]].push_back(str[g]);
           indeg[str[g]]++;
       }
       topo_init(h);
       res = topo_sort(h);
       if(res == 1) cout << "Case " << i << ": " << "No" << endl;
       else if(res == 0) cout << "Case " << i << ": " << "Yes" << endl;
       memset(vis,0,sizeof(vis));
       memset(indeg,0,sizeof(indeg));
       h = 0;
       str.clear();
       mm.clear();
       for(j = 0;j<sz;j++) adj[j].clear();
       while(!q.empty()){
           q.pop();
       }
   }
    return 0;
}