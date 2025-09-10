#include <iostream>

using namespace std;

int n, s;
int arr[100010];

int main() {
    
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 100010;
    int left = 0, right = 0;
    int sum = 0;

    while (true) {
        if (sum >= s) {
            int len = right - left;
            if (len < ans) ans = len;
            sum -= arr[left];
            left++;
        }
        else {
            if (right == n) break;
            sum += arr[right];
            right++;
        }
    }

    cout << (ans == 100010 ? 0 : ans);

    return 0;
}