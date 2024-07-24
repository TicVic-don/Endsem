#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

string solve(int a, int b, int n, int m){

    if(n-m > 0){
        // checking sign of a and b, if a is positive and b is negative then return "-Infinity"
        if((a > 0 && b < 0) || (a < 0 && b > 0)){
            return "-Infinity";
        }
        else{
            return "Infinity";
        }
    }
    else if(n-m < 0){
        return "0/1";
    }
    else{
        // if n-m = 0
        if(b < 0){
            a = -a;
            b = -b;
        }
        
        int gcd = __gcd(abs(a), abs(b));
        a = a / gcd;
        b = b / gcd;
        
        string str = to_string(a) + "/" + to_string(b);
        return str;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 0; i < n + 1; i++){
        cin >> a[i];
    }
    vector<int> b(m + 1);
    for(int i = 0; i < m + 1; i++){
        cin >> b[i];
    }
    string sol = solve(a[0], b[0], n, m);
    cout << sol << endl;
}
