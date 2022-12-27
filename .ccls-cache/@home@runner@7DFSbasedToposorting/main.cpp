

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(vector<int> adj[],int u, stack<int> s, bool visited[]){
  visited[u]=true;
  for(int l:adj[u]){
    if(visited[u]==false){
      DFS(adj,u,s,visited);
    }
  }
  cout<<u<<endl;
  s.push(u);
}

void DFS_based_Topo(vector<int> adj[], int V){
  stack<int> s;
  bool visited[V];
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  for(int i=0;i<V;i++){
      for(int u:adj[i]){
        if(visited[u]==false){
          DFS(adj,u,s,visited);
        }
      }
  }
  // while(!s.empty()){
  //    cout << s.top() <<"JSJD ";
  //    s.pop();
  // }
}

void printGraph(vector<int> adj[], int v){
  for(int i=0;i<v;i++){
    cout<<"Node"<<" "<<i<<endl;
    for(int k:adj[i]){
      cout<<" "<<k;
    }
    cout<<endl;
  }
}

void addEdge(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
}

int main(){
  int V=5;
  vector<int> adj[V];

  addEdge(adj,0,1);
  addEdge(adj,1,3);
  addEdge(adj,3,4);
  addEdge(adj,2,3);
  addEdge(adj,2,4);

  printGraph(adj, V);

  DFS_based_Topo(adj, V);
  
  
}