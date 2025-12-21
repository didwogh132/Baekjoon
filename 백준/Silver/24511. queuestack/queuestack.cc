#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> idx;
    idx.resize(n);
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        cin >> idx[i];
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (idx[i] == 0) {
            dq.push_front(num);
        }
    }
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int ans;
        if (dq.empty()) {
            ans = x;
        }
        else {
            ans = dq.front();
            dq.pop_front();
            dq.push_back(x);
        }

        cout << ans << " ";
    }
    return 0;
}