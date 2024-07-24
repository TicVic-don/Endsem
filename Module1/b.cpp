#include <iostream>
#include <algorithm>

using namespace std;

// Function to compute GCD of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long x, y, z;
    cin >> x >> y >> z;

    // Compute GCD of the three numbers
    long long result = gcd(gcd(x, y), z);

    cout << result << endl;

    return 0;
}
