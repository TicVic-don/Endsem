#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve(int n, vector<int>& v) {
    int x = 1;

    // Calculate least common multiple (LCM) of all multipliers
    for (auto &val : v) {
        x = lcm(x, val);
    }

    int sum = 0;
    vector<int> ans;

    // Distribute the coins
    for (auto &val : v) {
        sum += x / val;
        ans.push_back(x / val);
    }

    // Check if sum of bets is greater than or equal to total coins received
    if (sum >= x) {
        cout << "-1" << endl;
    } else {
        // Output the bets
        for (auto &val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> v(n);

        // Input multipliers
        for (auto &val : v) cin >> val;

        solve(n, v);
    }

    return 0;
}
