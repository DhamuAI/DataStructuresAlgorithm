#include <iostream>
#include <vector>

using namespace std;
void DFS(vector<int> adj[], int s, bool visited[]){
  visited[s]=true;
  cout<<"Traversed Node"<<" "<<s<<endl;
  for(int u:adj[s]){
    if(visited[u]==false){
      DFS(adj, u, visited);
    }
  }
}

void printGraph(vector<int> adj[], int V){

  cout<<"ADJACENCY LIST REP:"<<endl;
  for(int i=0;i<V;i++){
    cout<<"Node"<<i<<"\t";
    for( int x:adj[i]){
      cout<<x<<" ";
    }
    cout<<endl;
  }
}

void addEdge(vector<int> adj[], int u, int v){
  //directed
  adj[u].push_back(v);
  // adj[v].push_back(u);
}
int main() {
int V;
cout<<"Enter Number of Nodes"<<endl;
cin>>V;
vector<int> adj[V];

  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,2,3);
  addEdge(adj,2,4);
  addEdge(adj,0,4);

 printGraph(adj,V);

  int S = 0; //source_node
  bool visited[V];
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  DFS(adj, S, visited);
  }