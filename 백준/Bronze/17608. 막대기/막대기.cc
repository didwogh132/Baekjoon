#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        if (ans.empty()) ans.push(arr[i]);
        else if (ans.top() < arr[i]) ans.push(arr[i]);
    }

    cout << ans.size();
    return 0;
}