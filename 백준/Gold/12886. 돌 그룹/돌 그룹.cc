#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int a;
    int b;
};

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int S = A + B + C;

    if (S % 3 != 0) {
        cout << 0;
        return 0;
    }

    static bool visited[1501][1501];
    memset(visited, 0, sizeof(visited));

    int arr0[3];
    arr0[0] = A; arr0[1] = B; arr0[2] = C;
    sort(arr0, arr0 + 3);
    int a0 = arr0[0], b0 = arr0[1], c0 = arr0[2];

    queue<Node> q;
    q.push({ a0, b0 });
    visited[a0][b0] = true;

    while (!q.empty()) {
        Node now = q.front(); q.pop();
        int x = now.a;
        int y = now.b;
        int z = S - x - y;

        if (x == y && y == z) {
            cout << 1;
            return 0;
        }

        int U[3], V[3], W[3];

        if (x != y) {
            int u = x, v = y, w = z;
            if (u < v) {
                int nu = u + u;
                int nv = v - u;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = w;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            } else { // v < u
                int nu = v + v;
                int nv = u - v;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = z;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            }
        }

        if (x != z) {
            int u = x, v = z, w = y;
            if (u < v) {
                int nu = u + u;
                int nv = v - u;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = w;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            } else {
                int nu = v + v;
                int nv = u - v;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = y;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            }
        }

        if (y != z) {
            int u = y, v = z, w = x;
            if (u < v) {
                int nu = u + u;
                int nv = v - u;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = w;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            } else {
                int nu = v + v;
                int nv = u - v;
                int arr[3];
                arr[0] = nu; arr[1] = nv; arr[2] = x;
                sort(arr, arr + 3);
                int na = arr[0], nb = arr[1];
                if (!visited[na][nb]) {
                    visited[na][nb] = true;
                    q.push({ na, nb });
                }
            }
        }
    }

    cout << 0;
    return 0;
}