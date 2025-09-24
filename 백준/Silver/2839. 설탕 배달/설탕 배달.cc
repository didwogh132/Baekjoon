#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int num;
    int used;
};

int main() {
    int n;
    int arr[5005];
    cin >> n;

    fill(arr, arr + n + 1, 0xffff);

    int cnt = 0;
    queue<node> q;
    q.push({ 3, 1 });
    q.push({ 5, 1 });
    arr[3] = 1;
    arr[5] = 1;
    while (!q.empty()) {
        node a = q.front(); q.pop();

        if (arr[a.num] < a.used) continue;

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                node b = { a.num + 3, a.used + 1 };
                if (arr[b.num] <= b.used) continue;
                arr[b.num] = b.used;
                q.push(b);
            }
            else {
                node b = { a.num + 5, a.used + 1 };
                if (arr[b.num] <= b.used) continue;
                arr[b.num] = b.used;
                q.push(b);
            }
        }
    }

    if (arr[n] == 0xffff) cout << -1;
    else cout << arr[n];

    return 0;
}