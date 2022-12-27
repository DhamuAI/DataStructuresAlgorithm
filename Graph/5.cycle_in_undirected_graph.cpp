#include <iostream>
#include <vector>

using namespace std;

int find_cycle_undirected_graph(vector<int> adj[], int S, bool visited[],
                                 int parent) {
    visited[S]= true;
  
    for(int k: adj[S]){
      if(visited[k]==false){
        if(find_cycle_undirected_graph(adj, k, visited, S)==true){
          return true;
          }
        }else if(k!=parent){
        return true;
        }
      }
  return false;
  }
void printGraph(vector<int> adj[], int V) {
  cout << "ADJ_LIST DATA STUCTURE" << endl;
  for (int i = 0; i < V; i++) {
    cout << "Node No"
         << " " << i << "\t";
    for (int k : adj[i]) {
      cout << k << endl;
    }
    cout << "\n";
  }
}

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {

  int V = 10;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  // addEdge(adj, 4, 2);
  addEdge(adj, 1, 5);
  addEdge(adj,5,6);
  // addEdge(adj,6,7);
  addEdge(adj,8,9);
  addEdge(adj,0,8);
  addEdge(adj,9,7);
  printGraph(adj, V);

  int S = 0; // source
  bool visited[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
  }
  if (find_cycle_undirected_graph(adj, S, visited, -1) == true) {
    cout<<"True, it has cycle"<<endl;
  } else {
    cout<<"No cycles";
  }
  return 0;
}