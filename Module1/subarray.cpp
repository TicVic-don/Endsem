#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void findAllSubarrays(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> subarrays;
    for (int start = 0; start < n; ++start) {
        vector<int> subarray1;
        for (int end = start; end < n; ++end) {
            // Print subarray from start to end
            for (int k = start; k <= end; ++k) {
                cout << arr[k] << " ";
                subarray1.push_back({arr[k]});
            }
           int a =  accumulate(subarray1.begin(), subarray1.end(), 0);
            if(a/5 == 0 ){
                subarrays.push_back(subarray1);
            }
            
            cout << endl;
        }
    }
    cout << "Subarrays: " << endl;
    for (int i = 0; i < subarrays.size(); i++) {
        for (int j = 0; j < subarrays[i].size(); j++) {
            cout << subarrays[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 56, 2};
    findAllSubarrays(arr);
    return 0;
}
