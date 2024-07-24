#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string checkNonDecreasingGCDSequence(const vector<int>& arr) {
    int n = arr.size();
    vector<int> gcds(n - 1);

    // Calculate GCDs of neighboring elements
    for (int i = 0; i < n - 1; ++i) {
        gcds[i] = __gcd(arr[i], arr[i + 1]);
    }

    // Find the first index where GCD sequence is decreasing
    int j = -1;
    for (int i = 0; i < n - 2; ++i) {
        if (gcds[i] > gcds[i + 1]) {
            j = i;
            break;
        }
    }

    // If GCD sequence is already non-decreasing, return "YES"
    if (j == -1) return "YES";

    // Check removing each element at index j, j+1, and j+2
    for (int k = 0; k < 3; ++k) {
        vector<int> modified;
        for (int i = 0; i < n; ++i) {
            if (i != j + k) {
                modified.push_back(arr[i]);
            }
        }

        vector<int> modifiedGCDs(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            modifiedGCDs[i] = __gcd(modified[i], modified[i + 1]);
        }

        bool nonDecreasing = true;
        for (int i = 0; i < n - 3; ++i) {
            if (modifiedGCDs[i] > modifiedGCDs[i + 1]) {
                nonDecreasing = false;
                break;
            }
        }

        if (nonDecreasing) return "YES";
    }

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << checkNonDecreasingGCDSequence(arr) << "\n";
    }

    return 0;
}
