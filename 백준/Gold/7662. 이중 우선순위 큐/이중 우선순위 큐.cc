#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int t, k;

int main() {

    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> k;
        map<long long, int> m;
        priority_queue<long long> maxq;
        priority_queue<long long, vector<long long>, greater<long long>> minq;
        for (int i = 0; i < k; i++) {
            char a;
            long long n;
            cin >> a >> n;
            if (a == 'I') {
                minq.push(n);
                maxq.push(n);
                m[n]++;
            }
            else {
                if (m.empty()) continue;
                if (n == 1) {
                    while (!maxq.empty()) {
                        long long top = maxq.top(); maxq.pop();
                        if (m[top] > 0) {
                            m[top]--;
                            if (m[top] == 0) m.erase(top);
                            break;
                        }

                    }
                }
                else {
                    while (!minq.empty()) {
                        long long top = minq.top(); minq.pop();
                        if (m[top] > 0) {
                            m[top]--;
                            if (m[top] == 0) m.erase(top);
                            break;
                        }
                    }
                }
            }
        }

        while (!maxq.empty()) {
            long long top = maxq.top();
            if (m.count(top) && m[top] > 0) break;
            maxq.pop();
        }
        while (!minq.empty()) {
            long long top = minq.top();
            if (m.count(top) && m[top] > 0) break;
            minq.pop();
        }

        if (m.empty() || maxq.empty() || minq.empty()) cout << "EMPTY\n";
        else cout << maxq.top() << " " << minq.top() << "\n";
    }

    return 0;
}