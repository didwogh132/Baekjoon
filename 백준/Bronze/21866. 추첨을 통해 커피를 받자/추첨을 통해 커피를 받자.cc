#include <iostream>

using namespace std;

int main() {
    int arr[9] = { 100, 100, 200, 200, 300, 300, 400, 400, 500 };
    
    int sum = 0;
    bool flag = false;
    for (int i = 0; i < 9; i++) {
        int num;
        cin >> num;
        if (num > arr[i]) {
            flag = true;
            break;
        }
        sum += num;
    }

    if (flag) cout << "hacker";
    else if (sum >= 100) cout << "draw";
    else cout << "none";
    return 0;
}