#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int num;
    int idx;
};

bool cmp(node a, node b) {
    return a.num > b.num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        queue<node> q;
        cin >> n >> m;
        node arr[101];
        int cnt = 1;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr[i] = { a, i };
            q.push({arr[i].num, i});
        }
        sort(arr, arr + n, cmp);

        int num_idx = 0;

        while (!q.empty()) {
            node x = q.front(); q.pop();
            if (x.num == arr[num_idx].num && x.idx == m) {
                break;
            }
            else if (x.num == arr[num_idx].num) {
                num_idx++;
                cnt++;
            }
            else {
                q.push(x);
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}