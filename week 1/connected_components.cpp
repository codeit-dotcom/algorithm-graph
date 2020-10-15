#include <iostream>
#include <vector>

using std::vector;
using std::pair;
void explore(vector<int> &visited , vector<vector<int>> &adj , int i){
  visited[i]=1;
  for(vector<int>::const_iterator it = adj[i].begin() ; it !=adj[i].end() ; ++it){
    if(!visited[*it]){
      explore(visited,adj, *it);
    }
  }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<int> visited(adj.size());
  for(int i=0 ; i< adj.size(); i++){
     if(!visited[i]){
       explore(visited , adj , i);
       res++;
     }
  }

  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
