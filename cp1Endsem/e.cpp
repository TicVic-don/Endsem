#include<bits/stdc++.h>

using namespace std;

#define int long long

const int max_num_digits = 20;
int dp[max_num_digits][max_num_digits][2][2][9]; // Added a dimension to track digit sum modulo 9
int n, m, k, d;

void reset() {
    for (int i = 0; i < max_num_digits; i++) {
        for (int j = 0; j < max_num_digits; j++) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    for (int mod = 0; mod < 9; ++mod) { // Reset digit sum modulo
                        dp[i][j][k][l][mod] = -1;
                    }
                }
            }
        }
    }
}

int dfs(int c, int x = 0, int y = 11, int lead = 1, bool z = 0, int modsum = 0) {
    if (dp[x][y][lead][z][modsum] != -1) {
        return dp[x][y][lead][z][modsum];
    }
    if (x == to_string(c).length()) {
        return dp[x][y][lead][z][modsum] = (modsum == 0); // Divisible by 9
    }

    int limit = 9;
    int dig = to_string(c)[x] - '0';
    if (!z) {
        limit = dig;
    }

    dp[x][y][lead][z][modsum] = 0;
    for (int xth_digit = 0; xth_digit <= limit; xth_digit++) {
        if (xth_digit == 7) continue; // No 7s allowed
        if (!lead && xth_digit == y) continue;
        int new_modsum = (modsum + xth_digit) % 9;
        if (z) {
            dp[x][y][lead][z][modsum] += dfs(c, x + 1, xth_digit, xth_digit == 0 && lead, 1, new_modsum);
        } else {
            dp[x][y][lead][z][modsum] += dfs(c, x + 1, xth_digit, xth_digit == 0 && lead, xth_digit < limit, new_modsum);
        }
    }
    return dp[x][y][lead][z][modsum];
}

int main() {
    cin >> n >> m;
    reset();
    int total = dfs(m);
    reset();
    int torem = dfs(n - 1);
    total -= torem;
    cout << total;
}