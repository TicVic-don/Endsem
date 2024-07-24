#include <iostream>
#include <vector>

using namespace std;

// Function to print the contents of a vector
void DbgVec(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);

    // Initialize the vector based on the given pattern
    for (int i = 0; i < n - m; ++i) {
        vec[i] = n - i;
    }
    for (int i = n - m; i < n; ++i) {
        vec[i] = i - n + m + 1;
    }

   for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
