#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int arr[100010];
    string ans;
    stack<int> a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = 1;
    int i = 0;
    
    while (i < n) {
        while (num <= arr[i]) {
            a.push(num);
            ans += '+';
            num++;
        }

        if (!a.empty() && a.top() == arr[i]) {
            a.pop();
            ans += '-';
            i++;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    int size = ans.size();

    for (int i = 0; i < size; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}