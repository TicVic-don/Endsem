#include <iostream>
#include <vector>
using namespace std;

void dfsrec(vector<vector<int>> &adj,int s , vector<bool> &visited);

void dfs(vector<vector<int>> &adj, int s ,int v){
    vector<bool> visited(v,false);
    for(int i =0 ; i<v;i++){
        if(visited[i]==false){
           dfsrec(adj,i,visited);
        }
    }
}

void dfsrec(vector<vector<int>> &adj,int s , vector<bool> &visited){
    visited[s] = true;
    cout<<s<<" ";
    for(int u : adj[s]){
        if(visited[u]==false){
            dfsrec(adj,u,visited);
        }
    }
}
int main(){
    int v = 5;
    vector<vector<int>> adj(5);
    cout<<"teri ma ki chut";
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    cout<<endl;
    dfs(adj, 0, v); 
    cout<<endl;
}