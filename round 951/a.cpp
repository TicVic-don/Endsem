#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Include this header for INT_MIN

using namespace std;

int findMaxPossibleValue(const vector<int>& arr) {
    int n = arr.size();
    int max_min_2_length = INT_MIN;  // To store the maximum of the minimums of 2-length subsequences
    int max_median_3_length = INT_MIN;  // To store the maximum of the medians of 3-length subsequences

    // For all 2-length subsequences
    for (int i = 0; i < n - 1; ++i) {
        int min_val = min(arr[i], arr[i + 1]);
        max_min_2_length = max(max_min_2_length, min_val);
    }

    // For all 3-length subsequences
    for (int i = 0; i < n - 2; ++i) {
        vector<int> subarray = {arr[i], arr[i + 1], arr[i + 2]};
        sort(subarray.begin(), subarray.end());
        int median_val = subarray[1];  // The median of the sorted subarray of length 3
        max_median_3_length = max(max_median_3_length, median_val);
    }

    // The answer is the maximum of the two calculated values
    return max(max_min_2_length, max_median_3_length);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << findMaxPossibleValue(arr) << endl;
    }

    return 0;
}
