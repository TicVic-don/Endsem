#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> nmat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nmat[j][i] = mat[i][j];
        }
    }
    return nmat;
}

string solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ds1(n, vector<int>(m)), ds2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ds1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ds2[i][j];
        }
    }
    
    set<set<int>> ssi;
    for (auto row: ds1) {
        set<int> cur(row.begin(), row.end());
        ssi.insert(cur);
    }
    for (auto row: ds2) {
        set<int> cur(row.begin(), row.end());
        if (ssi.find(cur) == ssi.end()) return "NO";
    }
    
    if (n == m) {   
        ds1 = transpose(ds1), ds2 = transpose(ds2);
        ssi.clear();

        for (auto row: ds1) {
            set<int> cur(row.begin(), row.end());
            ssi.insert(cur);
        }
        
        for (auto row : ds2) {
            set<int> cur(row.begin(), row.end());
            if (ssi.find(cur) == ssi.end()) return "NO";
        }
        
        return "YES";
    }
    
    ssi.clear();
    for (int j = 0; j < m; j++) {
        set<int> cur;
        for (int i = 0; i < n; i++) {
            cur.insert(ds1[i][j]);
        }
        ssi.insert(cur);
    }
    for (int j = 0; j < m; j++) {
        set<int> cur;
        for (int i = 0; i < n; i++) {
            cur.insert(ds2[i][j]);
        }
        if (ssi.find(cur) == ssi.end()) return "NO";
    }

    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cout << solve() << "\n";
    }

    return 0;
}
