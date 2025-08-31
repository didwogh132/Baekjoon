#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    long long count_zero[41] = {};
    long long count_one[41] = {};
    count_zero[0] = 1;
    count_zero[1] = 0;
    count_one[0] = 0;
    count_one[1] = 1;
    for (int i = 2; i <= 40; i++) {
        count_zero[i] = count_zero[i - 1] + count_zero[i - 2];
        count_one[i] = count_one[i - 1] + count_one[i - 2];
    }
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        cout << count_zero[n] << " " << count_one[n] << "\n";
    }

    return 0;
}