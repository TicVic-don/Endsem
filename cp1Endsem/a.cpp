#include <bits/stdc++.h>
#include <string>
using namespace std;

string minint(string a) {
    vector<int> e;
    vector<int> o;

    for (char digitChar : a) {
        int digit = digitChar - '0';
        if (digit % 2 == 0) {
            e.push_back(digit);
        } else {
            o.push_back(digit);
        }
    }

    string res = "";
    int eidx = 0, oidx = 0;

    while (eidx < e.size() && oidx < o.size()) {
        if (e[eidx] < o[oidx]) {
            res += to_string(e[eidx++]);
        } else {
            res += to_string(o[oidx++]);
        }
    }

    while (eidx < e.size()) {
        res += to_string(e[eidx++]);
    }
    while (oidx < o.size()) {
        res += to_string(o[oidx++]);
    }

    return res;
}

void solve()
{
    string s;
    cin >> s;
    cout << minint(s) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}