#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solve(vector<int> &a) {
    int n = a.size();
    bool flag = true;
    
    // Finding the left boundary where the array is not sorted
    int l = 0;
    while (l < n - 1 && a[l] <= a[l + 1]) {
        l++;
    }
    
    // If the entire array is sorted
    if (l == n - 1) {
        cout << "yes" << endl;
        cout << "1 1" << endl;
        return "yes";
    }

    // Finding the right boundary where the array is not sorted
    int r = n - 1;
    while (r > 0 && a[r] >= a[r - 1]) {
        r--;
    }

    // Reverse the subarray from l to r
    reverse(a.begin() + l, a.begin() + r + 1);

    // Check if the array is sorted after the reversal
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "no" << endl;
            return "no";
        }
    }
    
    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1 << endl;
    return "yes";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
    return 0;
}
