#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, T;
bool flag;
int z;

struct node {
    int y;
    int x;
    int cnt;
};

vector<vector<node>> arr;

void bfs(int sy, int sx) {
    queue<node> q;
    q.push({ sy, sx, 0 });

    // 시작점 방문 처리
    for (int i = 0; i < arr[sy].size(); i++) {
        if (arr[sy][i].x == sx) {
            arr[sy][i].cnt = 0;
            break;
        }
    }

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = now.y - 2; i <= now.y + 2; i++) {
            if (i < 0 || i > T) continue;

            for (int j = 0; j < arr[i].size(); j++) {
                int ny = i;
                int nx = arr[i][j].x;

                if (arr[i][j].cnt != -1) continue;
                if (abs(now.x - nx) > 2) continue;

                arr[i][j].cnt = now.cnt + 1;
                if (ny == T) {
                    z = arr[i][j].cnt;
                    flag = true;
                    return;
                }

                q.push({ ny, nx, arr[i][j].cnt });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> T;

    arr.resize(T + 1);  // y좌표 범위

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[y].push_back({ y, x, -1 });  // 초기 cnt = -1 (미방문)
    }

    // 시작점 추가
    arr[0].push_back({ 0, 0, -1 });

    bfs(0, 0);

    if (flag) cout << z << "\n";
    else cout << -1 << "\n";

    return 0;
}