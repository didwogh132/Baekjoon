#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[21];

    cin >> n;

    int sum_a = 0;
    int sum_b = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        else if (arr[i] % 30 == 0) {
            sum_a = sum_a + ((arr[i] / 30) + 1) * 10;
        }
        else {
            sum_a = sum_a + (arr[i] / 30) * 10 + 10;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        if (arr[i] % 60 == 0) {
            sum_b = sum_b + ((arr[i] / 60) + 1) * 15;
        }
        else {
            sum_b = sum_b + (arr[i] / 60) * 15 + 15;
        }
    }

    if (sum_a == sum_b) {
        cout << "Y M " << sum_a;
    }
    else if(sum_a < sum_b){
        cout << "Y " << sum_a;
    }
    else {
        cout << "M " << sum_b;
    }
    return 0;
}
