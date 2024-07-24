#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void printTeams(const vector<vector<int>>& teams) {
    for (const auto& team : teams) {
        for (int student : team) {
            cout << student << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string stripe;
    cin >> stripe;
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        colors[i] = stripe[i] - 'A';
    }
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
    vector<vector<int>> backtrack(n, vector<int>(k, -1));
    for (int j = 0; j < k; ++j) {
        dp[0][j] = (colors[0] == j) ? 0 : 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int l = 0; l < k; ++l) {
                if (j != l) {
                    int repaint = dp[i - 1][l] + ((colors[i] == j) ? 0 : 1);
                    if (repaint < dp[i][j]) {
                        dp[i][j] = repaint;
                        backtrack[i][j] = l;
                    }
                }
            }
        }
    }
    int min_repaints = INT_MAX;
    int last_color = -1;
    for (int j = 0; j < k; ++j) {
        if (dp[n - 1][j] < min_repaints) {
            min_repaints = dp[n - 1][j];
            last_color = j;
        }
    }
    string result(n, ' ');
    int current_color = last_color;
    for (int i = n - 1; i >= 0; --i) {
        result[i] = current_color + 'A';
        current_color = backtrack[i][current_color];
    }

    cout << min_repaints << endl;
    cout << result << endl;

    return 0;
}
