#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    
    for (int i = 1; i <= n; i++) q.push(i);

    int cnt = 0;
    queue<int> q2;

    while (q2.size() < n) {
        if (cnt == k - 1) {
            int a = q.front(); q.pop();
            q2.push(a);
            cnt = 0;
            continue;
        }
        int b = q.front(); q.pop();
        q.push(b);
        cnt++;
    }
    int c = q2.size();

    cout << "<";

    for (int i = 0; i < c; i++) {
        int a = q2.front(); q2.pop();
        if (i == c - 1) cout << a << ">";
        else cout << a << ", ";
    }

    return 0;
}