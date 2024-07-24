#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;  
    vector<int> results(t); 

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> pages(n);
        for (int j = 0; j < n; ++j) {
            cin >> pages[j];
        }
        int highestIndexBook = pages[n - 1];
        int maxPages = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (pages[j] > maxPages) {
                maxPages = pages[j];
            }
        }

        
        results[i] = highestIndexBook + maxPages;
    }

    
    for (int i = 0; i < t; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
