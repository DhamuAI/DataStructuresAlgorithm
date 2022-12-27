#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void khan_topo_sort(vector<int> adj[], int V, vector<int> indegree) {
  queue<int> q;
  for(int i=0;i<V;i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }
  cout<<"Topological Sort"<<endl;
  while(q.empty()==false){
    int u = q.front();
    q.pop();
    cout<<u<<endl;
    for(int k:adj[u]){
      indegree[k]=indegree[k]-1;
      if(indegree[k]==0){
        q.push(k);
      }
    }
    
  }
}
void printGraph(vector<int> adj[], int V, vector<int> indegree) {
  cout << "Graph Connections" << endl;
  for (int i = 0; i < V; i++) {
    cout << "Node"<< " " << i;
    for (int k : adj[i]) {
      cout<< "\t" << k;
      indegree[k]=indegree[k]+1;
    }
    cout << endl;
  }
  cout<<"Indegree_list"<<endl;

  for(int i=0;i<V;i++){
    cout<<indegree[i]<<endl;
  }
}

void addEdge(vector<int> adj[], int u, int v) {
  // Directed Graph
  adj[u].push_back(v);
}
int main() {
  int V = 5;
  vector<int> adj[V];
  vector<int> indegree;

  for(int i=0;i<V;i++){
    indegree.push_back(0);
  }

  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 3);

  printGraph(adj, V, indegree);
  khan_topo_sort(adj, V, indegree);
}