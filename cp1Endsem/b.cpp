#include<bits/stdc++.h>

using namespace std;

#define ll long long
using namespace std;
using matrix = vector<vector<long long>>;
const long long MOD = 1e8 + 7;


matrix multiply(const matrix &a, const matrix &b) {
    ll n = a.size();
    matrix c(n, vector<long long>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}


matrix power(const matrix &base, long long exp) {
    if (exp == 1) {
        return base;
    }
    matrix half = power(base, exp / 2);
    matrix result = multiply(half, half);
    if (exp % 2 == 1) {
        result = multiply(result, base);
    }
    return result;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        
        
        matrix trans = {{0, 1, 1, 1}, 
                        {1, 0, 1, 1}, 
                        {1, 1, 0, 1}, 
                        {1, 1, 1, 0}};

        
        matrix result = power(trans, k);

        
        cout << result[0][0] << endl;
    }
    return 0;
}