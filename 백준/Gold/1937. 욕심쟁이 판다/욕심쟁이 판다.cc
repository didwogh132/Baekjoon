#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[505][505];
int dp[505][505];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
    int cost;
};
vector<node> nodes;

int main() {
    int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            arr[i][j] = a;
            dp[i][j] = 1;
            nodes.push_back({ i, j, a });
        }
    }

    sort(nodes.begin(), nodes.end(), [](const node& a, const node& b) {
        if (a.cost != b.cost) return a.cost < b.cost;
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
        });

    for (size_t i = 0; i < nodes.size(); i++) {
        int y = nodes[i].y;
        int x = nodes[i].x;
        int cost = nodes[i].cost;

        for (int j = 0; j < 4; j++) {
            int ny = y + ydir[j];
            int nx = x + xdir[j];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (arr[ny][nx] > cost) {
                if (dp[ny][nx] < dp[y][x] + 1) {
                    dp[ny][nx] = dp[y][x] + 1;
                    if (ans < dp[ny][nx]) ans = dp[ny][nx];
                }
            }
        }
        if (ans < dp[y][x]) ans = dp[y][x];
    }

    cout << ans;

    return 0;
}
