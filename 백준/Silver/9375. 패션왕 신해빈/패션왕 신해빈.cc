#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        map<string, long long> arr;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> b >> a;
            arr[a]++;
        }

        long long temp = 1;
        map<string, long long> ::iterator it;

        for (it = arr.begin(); it != arr.end(); it++) {
            temp *= (it->second + 1);
        }

        cout << temp - 1 << "\n";
    }


    return 0;
}