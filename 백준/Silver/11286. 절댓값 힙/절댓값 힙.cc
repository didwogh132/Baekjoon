#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    priority_queue<int, vector<int>, less<int>> pq_max;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (pq_min.empty() && pq_max.empty()) cout << 0 << "\n";
            else {
                int a;
                int b;
                if (pq_min.empty()) {
                    b = pq_max.top(); pq_max.pop();
                    cout << b << "\n";
                    continue;
                }
                else if (pq_max.empty()) {
                    a = pq_min.top(); pq_min.pop();
                    cout << a << "\n";
                    continue;
                }
                a = pq_min.top();
                b = pq_max.top();

                if (abs(0 - a) > abs(0 - b)) {
                    pq_max.pop();
                    cout << b << "\n";
                }
                else if (abs(0 - a) == abs(0 - b)) {
                    pq_max.pop();
                    cout << b << "\n";
                }
                else {
                    pq_min.pop();
                    cout << a << "\n";
                }
            }
        }
        else if (num > 0) {
            pq_min.push(num);
        }
        else {
            pq_max.push(num);
        }
    }


    return 0;
}