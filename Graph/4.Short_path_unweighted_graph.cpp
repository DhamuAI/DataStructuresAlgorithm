#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS uses Queue Data-structure to get the traversal done
void BFS_shortest_distance_unweighted(vector<int> adj[],int V, int S){

  int distance[V];
  bool visited[V];

  for(int i=0; i<V; i++){
    visited[i]=false;
    distance[i]=0;
    }

  queue<int> q;
  visited[S]=true;
  q.push(S);
  while(q.empty()==false){
    int u = q.front();
    q.pop();
    // cout<<"Travesed"<<u<<endl;
    for(int k:adj[u]){
      if(visited[k]==false){
        distance[k]=distance[u]+1;
        visited[k]=true;
        q.push(k);
      }
    }
  }
  for(int i=0;i<V;i++){
    cout<<distance[i]<<endl;
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
  addEdge(adj,1,3);
  addEdge(adj,2,3);
  addEdge(adj,1,2);

 printGraph(adj,V);

  int S = 0; //source_node
  BFS_shortest_distance_unweighted(adj,V,S);
  }