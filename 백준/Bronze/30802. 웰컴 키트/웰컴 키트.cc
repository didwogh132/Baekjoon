#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[6];
    for (int i = 0; i < 6; i++) cin >> arr[i];
    int a, b;
    cin >> a >> b;
    int sum = 0;

    for (int i = 0; i < 6; i++) {
        if (arr[i] % a != 0) sum += (arr[i] / a) + 1;
        else sum += arr[i] / a;
    }

    cout << sum << '\n' << n / b << " " << n % b;

    return 0;
}