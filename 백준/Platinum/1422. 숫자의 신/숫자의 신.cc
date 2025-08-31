#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct node {
    int idx;
    int size;
};
bool cmp(string a, string b) {
    return a + b > b + a;
}
string arr[50];

int main() {
    int k, n;
    node num;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + k, cmp);

    for (int i = 0; i < k; i++) {
        if (i == 0) {
            num.idx = i;
            num.size = arr[i].size();
        }
        else {
            if (num.size == arr[i].size()) {
                if (arr[num.idx] > arr[i]) continue;
                else {
                    num.idx = i;
                }
            }
            else if (arr[i].size() > num.size) {
                num.idx = i;
                num.size = arr[i].size();
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (i == num.idx) {
            for (int j = 0; j <= n - k; j++) {
                cout << arr[i];
            }
        }
        else {
            cout << arr[i];
        }
    }

    return 0;
}