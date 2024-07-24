#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Convert f to 0-based index for easier handling in C++
        f = f - 1;

        // Value of Dmitry's favorite cube
        int favorite_value = a[f];

        // Sort the array in non-increasing order
        vector<int> sorted_a = a;
        sort(sorted_a.rbegin(), sorted_a.rend());

        // Count occurrences of each value
        unordered_map<int, int> count;
        for (int val : sorted_a) {
            count[val]++;
        }

        // Find the range of positions for favorite value
        int start = 0;
        for (int val : sorted_a) {
            if (val == favorite_value) {
                break;
            }
            start++;
        }
        int end = start + count[favorite_value] - 1;

        // Determine the result
        if (end < k) {
            cout << "YES" << endl;
        } else if (start >= k) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }

    return 0;
}
