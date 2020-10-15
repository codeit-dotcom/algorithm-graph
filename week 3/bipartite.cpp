#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  
  
  vector<int> colour(adj.size(),-1);
     vector<int> visited(adj.size(),0);
  colour[0]=1;
  queue<int> queue;
  for(int i=0; i<adj.size();i++){
   if(!visited[i]) { 
  queue.push(i);
  
  while(!queue.empty()){
  int u= queue.front();
  queue.pop();
  
  for(int i=0; i< adj[u].size() ; i++){
           int v = adj[u][i];
           if (colour[v] == colour[u])
        return 0;
        
	  // Destination v is not colored
      else if (colour[v] == -1) {
        // Assign alternate color to this adjacent v of u
        colour[v] = 1- colour[u];
		queue.push(v);
	  }


     }
     visited[u]=1;
  }
    
  }}
  return 1;
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
  std::cout << bipartite(adj);
}
