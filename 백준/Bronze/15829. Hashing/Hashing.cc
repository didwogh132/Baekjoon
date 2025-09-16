#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string arr;
    long long k;
    long long hash = 0;
    cin >> n >> arr;

    for (int i = 0; i < n; i++) {
        k = arr[i] - 'a' + 1;
        for (int j = 0; j < i; j++) {
            k = (k * 31) % 1234567891;
        }
        hash = (hash + k) % 1234567891;
    }

    cout << hash;

    return 0;
}