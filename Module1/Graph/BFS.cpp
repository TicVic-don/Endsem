#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int> adj[], int v , int s){
    vector<bool> visited(v,false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty())
   {
    int a  = q.front();
    q.pop();
    cout<<a<<" ";
    for(int u : adj[a]){

        if(visited[u]==false){
            visited[u]= true;
            q.push(u);
        }

    }

   } 
}

int main(){
    int v = 5;
    vector<int> adj[v];
    cout<<"teri ma ki chud";
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    cout<<endl;
    BFS(adj, v, 0); 
    cout<<endl;

 cout<<"Adjacency List of the graph\n";
// print adj list
    for(int i =0;i<v;i++){
        cout<<i;
        for(int u : adj[i]){
            cout<<"->"<<u;
        }
        cout<<endl;
    }
    
    return 0;
}