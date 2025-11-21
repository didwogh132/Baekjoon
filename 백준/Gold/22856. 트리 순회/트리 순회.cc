#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100010];
int n;
int lastdepth;

void dfs(int num, int depth) {
    if (num == -1) {
        return;
    }
    int left = arr[num][0];
    int right = arr[num][1];
    if (left != -1) {
        dfs(left, depth + 1);
    }

    lastdepth = depth;

    if (right != -1) {
        dfs(right, depth + 1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back(b);
        arr[a].push_back(c);
    }

    dfs(1, 0);

    int ans = 2 * (n - 1) - lastdepth;

    cout << ans;

    return 0;
}