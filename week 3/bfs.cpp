#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> visited(adj.size(),0);
  if(s==t) return 0;
  vector<int> dist(adj.size(),-1);
  dist[s]=0;
  queue<int> queue;
  queue.push(s);
  while(!queue.empty()){
    int u=queue.front();
    queue.pop();
    if(!visited[u]){
   for(int i=0 ; i<adj[u].size(); i++){
     int v= adj[u][i];
      if(dist[v]==-1){
        queue.push(v);
        dist[v]=dist[u]+1;
        
       if(v==t) return dist[t]; 
      }}
      visited[u]=1;
   } 
  
  }

  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
