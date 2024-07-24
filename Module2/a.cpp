#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
void readUpdates(vector<int>& indices, string& chacha, int Update) {
    indices.resize(Update);
    for (int &index : indices) {
        cin >> index;
    }
    cin >> chacha;
}
void sortUpdateCharacters(string& chacha) {
    sort(chacha.begin(), chacha.end());
}
void processTestCase(int length_s, const string& ans, const vector<int>& indices, const string& chacha) {
    set<int> india(indices.begin(), indices.end());
    vector<int> chota(india.begin(), india.end());
    sort(chota.begin(), chota.end());
    string sorted_chacha = chacha;
    sortUpdateCharacters(sorted_chacha);
    map<int, char> charater;
    for (size_t i = 0; i < chota.size(); ++i) {
        charater[chota[i]] = sorted_chacha[i];
    }
    string updated_string = ans;
    for (const auto &pair : charater) {
        updated_string[pair.first - 1] = pair.second;
    }
    cout << updated_string << "\n";
}
void solve() {
    int num_tests;
    cin >> num_tests;

    while (num_tests--) {
        int length_s, Update;
        cin >> length_s >> Update;
        
        string ans;
        cin >> ans;

        vector<int> indices;
        string chacha;
        readUpdates(indices, chacha, Update);

        // Process each test case
        processTestCase(length_s, ans, indices, chacha);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
