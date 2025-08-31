#include <iostream>

using namespace std;

int arr[10010];

int main() {

    int t;
    cin >> t;
    
    arr[0] = 1;

    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 10000; j++) {
            arr[j] += arr[j - i];
        }
    }
    for (int tc = 0; tc < t; tc++) {
        int num;
        cin >> num;
        cout << arr[num] << "\n";
    }


    return 0;
}