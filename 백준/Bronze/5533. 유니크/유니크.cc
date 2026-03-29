#include <iostream>
#include <vector>

using namespace std;

struct node {
    int a, b, c;
    bool a_flag = false;
    bool b_flag = false;
    bool c_flag = false;;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<node> arr;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i].a >> arr[i].b >> arr[i].c;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].a == arr[j].a) {
                arr[i].a_flag = true;
                arr[j].a_flag = true;
            }
            if (arr[i].b == arr[j].b) {
                arr[i].b_flag = true;
                arr[j].b_flag = true;
            }
            if (arr[i].c == arr[j].c) {
                arr[i].c_flag = true;
                arr[j].c_flag = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        if (!arr[i].a_flag) sum += arr[i].a;
        if (!arr[i].b_flag) sum += arr[i].b;
        if (!arr[i].c_flag) sum += arr[i].c;

        cout << sum << "\n";
    }
    return 0;
}