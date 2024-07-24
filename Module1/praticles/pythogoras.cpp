#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to count the number of Pythagorean triplets (i, j, k) such that i > j > k and i^2 = j^2 + k^2
int countPythagoreanTriplets(int n) {
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int kSquared = i * i - j * j;
            int k = sqrt(kSquared);
            if (k * k == kSquared && k < j) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    int result = countPythagoreanTriplets(n);
    cout  << result << endl;

    return 0;
}
