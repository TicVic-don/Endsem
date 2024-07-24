#include <iostream>
#include <vector>
using namespace std;

void printTeams(const vector<vector<int>>& teams) {
    for (int i =1 ;i<=teams.size();i++) {
        teams[i].push_back(i);
        for (int student : teams[i]) {
            cout << student << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printTeams(adj);

    return 0;
}
