#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int explore(int i, vector<vector<int>> &adj , vector<int> &visited , vector<int> &stack){
  visited[i]=1;
  stack[i]=1;
  for(vector<int>::const_iterator it =adj[i].begin() ; it!=adj[i].end(); it++){
    if(!visited[*it]&& explore(*it, adj,visited,stack))
         return 1;
    else if(stack[*it])
        return 1;     
  } 
  stack[i]=0;
  return 0;
            
    
  
}

int acyclic(vector<vector<int> > &adj) {
  vector<int> visited(adj.size());
  vector<int> stack(adj.size());
  for(int i=0; i<adj.size() ; i++){
    if(!visited[i]){
      if(explore(i,adj,visited,stack))
         return 1;
    }
  }

  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
