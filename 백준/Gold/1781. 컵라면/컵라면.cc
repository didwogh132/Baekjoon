#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int time;
    int value;
    bool operator<(const node& right) const {
        if (time != right.time) return time < right.time;
        return value > right.value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<node> problem;

    cin >> n;

    problem.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> problem[i].time >> problem[i].value;
    }

    sort(problem.begin(), problem.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int deadline = problem[i].time;
        int cnt = problem[i].value;

        pq.push(cnt);
        ans += cnt;

        if (pq.size() > deadline) {
            ans -= pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}