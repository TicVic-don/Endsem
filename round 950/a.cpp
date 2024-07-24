#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;
        
        // Count the occurrences of each difficulty level in the bank
        unordered_map<char, int> problem_count;
        for (char c : a) {
            problem_count[c]++;
        }
        
        // Define the difficulty levels we need
        vector<char> levels = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
        int problems_needed = 0;
        
        // Check how many more problems are needed for each difficulty level
        for (char level : levels) {
            int required = m - problem_count[level];
            if (required > 0) {
                problems_needed += required;
            }
        }
        
        cout << problems_needed << endl;
    }
    
    return 0;
}
