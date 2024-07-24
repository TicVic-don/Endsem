#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <set>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int max_length = 0;
    int factor_count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (m % a[i] == 0) {
            factor_count++;
        }
    }
    
    if (factor_count == 0) {
        cout << 0 << endl;
    } else {
        cout << factor_count << endl;
    }
    
    return 0;
}
