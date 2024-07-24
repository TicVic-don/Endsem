#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element
#include <numeric>   // For std::accumulate

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k; // Read n and k
        vector<int> a(n);

        for (int j = 0; j < n; ++j) {
            cin >> a[j]; // Read each element into the vector
        }

        int sum_a = accumulate(a.begin(), a.end(), 0); // Calculate the sum of the array
        int max_a = *max_element(a.begin(), a.end()); // Find the maximum element in the array

        // Calculate the result using the given formula
        int result = 2 * sum_a - k + 1 - 2 * max_a;

        // Print the result
        cout << result << endl;
    }

    return 0;
}
