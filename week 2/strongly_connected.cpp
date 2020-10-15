#include <algorithm>
#include <iostream>
#include <vector>
#include<stack>
using std::stack;
using std::vector;
using std::pair;void dfs(vector<vector<int> > &adj, int x, vector<int> &visited, stack<int> &Stack) {
	// Mark the current node as visited
	visited[x] = 1;
	
	// Recur for all the vertices adjacent to this vertex
	for (int i = 0; i < adj[x].size(); i++) {
      if(!visited[adj[x][i]]){
        //visited[adj[x][i]] = 1;
		dfs(adj, adj[x][i], visited, Stack);
	  }	
	}
	
	// All vertices reachable from x are processed by now, push x to Stack
	Stack.push(x);
}
 


int number_of_strongly_connected_components(vector<vector<int> > adj ,vector<vector<int>> readj) {
  int result = 0;
  //write your code here
  stack<int> Stack;
  vector<int> visited(adj.size(),0);
  for(int i=0; i<readj.size(); i++){
       if(!visited[i]){
         dfs(readj,i,visited,Stack);

       }
  }
 std::fill(visited.begin(),visited.end(),0); 
 while (! Stack.empty()) {
	// Pop a vertex from stack
    int x = Stack.top();
    Stack.pop();
 
    // get one Strongly connected component of the popped vertex
    if (!visited[x]) {
	  stack<int> componentStack;
	  dfs(adj, x, visited, componentStack);
	  result++;
	}
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int>> readj(n,vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    readj[y-1].push_back(x-1);
  }
  std::cout << number_of_strongly_connected_components(adj,readj);
}
