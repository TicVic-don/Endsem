#include <iostream>
#include <vector>
using namespace std;

void swapper(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> v = {0, 0, 1, 0, 1, 0, 1, 1, 1};
    int n = v.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (v[mid] == 0) {
            swapper(v[low], v[mid]);
            low++;
            mid++;
        } else {
            mid++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
