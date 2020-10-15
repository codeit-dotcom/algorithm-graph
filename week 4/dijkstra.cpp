#include <iostream>
#include <vector>
#include <queue>
#include<limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;
struct node {
  int index;
  int distance;
  node(int index=0 , int distance =0): index(index) , distance(distance){}
};
struct cmp {
	bool operator()(node first, node second){
		return first.distance > second.distance;
	}
};


long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<int >visited(adj.size());
  if(s==t) return 0;
  vector<int> dis(adj.size(),numeric_limits<int>::max());
  dis[s]=0;
  priority_queue<node,vector<node>,cmp> pq;
  pq.push(node(s,dis[s]));
  while(!pq.empty()){
    node m =pq.top();
    pq.pop();
    int ind =m.index;
    for(int i=0; i<adj[ind].size() ; i++){
      int v=adj[ind][i];
      if(dis[v] > dis[ind] + cost[ind][i]) {
	    dis[v] = dis[ind] + cost[ind][i];
        pq.push(node(v, dis[v])); 
	    }
    }
    
  }
   if(dis[t] == numeric_limits<int>::max())
    return -1;
    
  return dis[t];
     
  
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
