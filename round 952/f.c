#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int num;
    cin >> num;

    for (int quux = 0; quux < num; ++quux) {
        long long int corge, grault;
        cin >> corge >> grault;

        vector<long long int> arg(grault);
        vector<long long int> waldo(grault);
        for (int i = 0; i < grault; ++i) {
            cin >> arg[i];
        }
        for (int i = 0; i < grault; ++i) {
            cin >> waldo[i];
        }

        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> fred;

        for (int i = 0; i < grault; ++i) {
            fred.push(make_pair(1, i)); 
        }

        long long int plugh = 0;
        while (corge > 0) {
            plugh = fred.top().first; 

            while (!fred.empty() && fred.top().first == plugh) {
                int thud = fred.top().second;
                fred.pop();

                corge -= arg[thud]; 

                fred.push(make_pair(plugh + waldo[thud], thud));
            }
        }

        cout << plugh << endl;
    }

    return 0;
}
