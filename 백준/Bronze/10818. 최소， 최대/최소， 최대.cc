#include <iostream>

using namespace std;


int main() {
    int n;
    int min = 1000001, max = -1000001;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    cout << min << " " << max;

    return 0;
}