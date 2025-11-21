#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> arr[300010];
long long cost[300010];
struct node {
    int num;
    long long value;
    bool operator< (const node& right) const {
        return value < right.value;
    }
};
priority_queue<node> pq;

void bfs(int num) {

    pq.push({ num, cost[num] });
    long long ans = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        ans += now.value;
        cout << ans << "\n";

        for (int i = 0; i < arr[now.num].size(); i++) {
            int next = arr[now.num][i];
            pq.push({ next, cost[next] });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        arr[parent].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        long long value;
        cin >> value;
        cost[i] = value;
    }

    bfs(1);

    return 0;
}