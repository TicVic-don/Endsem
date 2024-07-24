#include <iostream>
#include <vector>
using namespace std;

// Function to count trailing zeros in binary representation of a number
int countTrailingZeros(int n) {
    int count = 0;
    while ((n & 1) == 0 && n != 0) {
        n >>= 1;
        count++;
    }
    return count;
}

void findLongestCommonSubsegment(int t, vector<pair<int, int>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int x = test_cases[i].first;
        int y = test_cases[i].second;
        
        int xor_val = x ^ y;
        int trailing_zeros = countTrailingZeros(xor_val);
        
        int max_length = 1 << trailing_zeros; // 2^trailing_zeros
        cout << max_length << endl;
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        test_cases[i] = {x, y};
    }
    
    findLongestCommonSubsegment(t, test_cases);
    
    return 0;
}
