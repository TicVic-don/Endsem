#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<long long> &a, long long n){
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    // //print a
    //  for(long long i = 0; i<a.size(); i++){
    //     cout<<a[i]<<" ";
    //  }

    int pnt = 0, ans = 0;
    for (int i = 0; i < a.size(); i++) {
        while(a[i] - a[pnt] >= n) {
            pnt++;
        }
        ans = max(ans, i - pnt + 1);
    }
    cout << ans << endl;
   
  
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> v(n);
        for(long long i = 0; i<n; i++){
            cin>>v[i];
        }
        solve(v, n);
         }
    return 0;
}
