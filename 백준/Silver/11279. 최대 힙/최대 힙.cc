#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>>pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                int a = pq.top(); pq.pop();
                cout << a << "\n";
            }
        }
        else {
            pq.push(num);
        }
    }
    return 0;
}