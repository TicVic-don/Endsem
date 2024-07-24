#include <iostream>
using namespace std;

const long long mod = 1000000007;

int main() {
    int f1, f2;
    cin >> f1 >> f2;
    int n;
    cin >> n;
    
    long long f[6];
    f[0] = f1;
    f[1] = f2;
    f[2] = f2 - f1;
    f[3] = -f1;
    f[4] = -f2;
    f[5] = f1 - f2;

    int index = (n - 1) % 6; // This will give us the correct term in the sequence
    long long result = (f[index] % mod + mod) % mod; // Ensure non-negative result
    cout << result << endl;

    return 0;
}
