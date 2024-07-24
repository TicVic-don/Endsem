#include<bits/stdc++.h>
using namespace std;

// Function to solve the problem
void solve(){
    int num_students, num_queries;
    cin >> num_students >> num_queries;
    vector<int> magic_values(num_students);
    vector<int> prefix_sums(num_students, 0);
    for (int i = 0; i < num_students; i++) {
        cin >> magic_values[i];
        if (i == 0) {
            prefix_sums[i] = magic_values[i];
        } else {
            prefix_sums[i] = magic_values[i] + prefix_sums[i - 1];
        }
    }
    for (int i = 0; i < num_queries; i++) {
        int left_index, target_sum;
        cin >> left_index >> target_sum;
        int low = left_index - 1;
        int high = num_students - 1;
        int lower_bound = (left_index == 1 ? 0 : prefix_sums[left_index - 2]);
        if (target_sum > (prefix_sums[num_students - 1] - lower_bound)) {
            cout << -1 << endl;
            continue;
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (prefix_sums[mid] - lower_bound >= target_sum) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low + 1 << endl;
    }
}

// Main function
int main(){
    solve();
    return 0;
}
