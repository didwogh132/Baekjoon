#include <iostream>

#define Max 1000010

using namespace std;

int n;
long long tree[Max * 4];

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return;

    if (s == e) {
        tree[node] += value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int s, int e, int b) {
    if (s == e) {
        return s;
    }

    int mid = (s + e) / 2;
    if (tree[node * 2] >= b) {
        return query(node * 2, s, mid, b);
    }
    else {
        return query(node * 2 + 1, mid + 1, e, b - tree[node * 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            int s = query(1, 1, Max, b);
            cout << s << "\n";
            update(1, 1, Max, s, -1);
        }
        else {
            cin >> b >> c;

            update(1, 1, Max, b, c);
        }
    }

    return 0;
}