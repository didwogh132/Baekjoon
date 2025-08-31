#include <iostream>
#include <cstring>

#define MAX 100010
using namespace std;

int n, k;
int arr[MAX];
int tree[MAX * 4];
char a;
int b, c;

int init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s];

    int mid = (s + e) / 2;
    int left = init(node * 2, s, mid);
    int right = init(node * 2 + 1, mid + 1, e);

    return tree[node] = left * right;
}

void update(int node, int s, int e, int idx, int value) {
    if (idx < s || idx > e) return ;
    if (s == e) {
        tree[node] = value;
        return;
    }
    int mid = (s + e) / 2;
    
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);

    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 1;
    if (l <= s && r >= e) return tree[node];

    int mid = (s + e) / 2;
    int left = query(node * 2, s, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, e, l, r);

    return left * right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> k) {

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] < 0) arr[i] = -1;
        }
        init(1, 1, n);

        for (int i = 0; i < k; i++) {
            cin >> a >> b >> c;
            if (a == 'C') {
                if (c > 0 && arr[b] > 0) continue;
                else if (c < 0 && arr[b] < 0) continue;
                else {
                    if (c > 0) {
                        arr[b] = 1;
                        update(1, 1, n, b, 1);
                    }
                    else if (c < 0) {
                        arr[b] = -1;
                        update(1, 1, n, b, -1);
                    }
                    else {
                        arr[b] = 0;
                        update(1, 1, n, b, 0);
                    }
                }
            }
            else if (a == 'P') {
                int x = query(1, 1, n, b, c);
                if (x == 0) {
                    cout << '0';
                }
                else if (x > 0) {
                    cout << '+';
                }
                else {
                    cout << '-';
                }
            }
        }
        cout << "\n";

        memset(arr, 0, sizeof(arr + 1));
        memset(tree, 0, sizeof(tree));
    }

    return 0;
}