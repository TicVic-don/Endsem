#include <bits/stdc++.h>
using namespace std;
#define int long long int 
struct Range {
    int x, y, index;
};

bool compareByStart(const Range &a, const Range &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

bool compareByEnd(const Range &a, const Range &b) {
    if (a.y == b.y) return a.x > b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].x;
        ranges[i].index = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].y;
    }

    vector<int> ress(n, 0);
    vector<int> containedByResult(n, 0);

    sort(ranges.begin(), ranges.end(), compareByStart);

    int maxY = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].y < maxY) {
            ress[ranges[i].index] = 1;
        }
        maxY = max(maxY, ranges[i].y);
    }

    sort(ranges.begin(), ranges.end(), compareByEnd);

    int minY = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].y > minY) {
            containedByResult[ranges[i].index] = 1;
        }
        minY = min(minY, ranges[i].y);
    }

    for (int i = 0; i < n; ++i) {
        cout << ress[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << containedByResult[i] << " ";
    }
    cout << "\n";

    return 0;
}