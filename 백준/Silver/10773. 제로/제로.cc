#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    cin >> k;
    stack<int> a;

    int sum = 0;

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (a.size() == 0) continue;
            else {
                a.pop();
            }
        }
        else {
            a.push(num);
        }
    }
    while (!a.empty()) {
        int x = a.top(); a.pop();
        sum += x;
    }

    cout << sum;

    return 0;
}