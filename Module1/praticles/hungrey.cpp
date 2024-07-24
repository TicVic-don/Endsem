#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> generatePrimes(int n) {
    vector<int> primes;
    int num = 2;
    while (primes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }
    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = generatePrimes(n);
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
