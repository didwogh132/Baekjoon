#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, l, r;
int arr[51][51];
int arr2[51][51];
int visited[51][51];
bool flag = true;
struct node {
    int y;
    int x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int sum = 1;
int day;
int cnt2;
vector<node> group;

void bfs(int y, int x) {

    queue<node> q;
    group.clear();
    q.push({ y, x });
    visited[y][x] = 1;
    group.push_back({ y,x });

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (abs(arr[ny][nx] - arr[now.y][now.x]) < l || abs(arr[ny][nx] - arr[now.y][now.x]) > r) continue;
            if (visited[ny][nx] > -1) continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx });
            group.push_back({ ny, nx });
            sum += arr[ny][nx];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    while (flag) {
        cnt2 = 0;
        memset(arr2, 0, sizeof(arr2));
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == -1) {
                    sum = arr[i][j];;
                    bfs(i, j);
                }
                if (group.size() == 1) {
                    cnt2++;
                    arr2[group[0].y][group[0].x] = sum / group.size();
                }
                if (group.size() > 1) {
                    for (int k = 0; k < group.size(); k++) {
                        arr2[group[k].y][group[k].x] = sum / group.size();
                    }
                }
            }
        }
        if (cnt2 == n * n) {
            break;
        }
        memcpy(arr, arr2, sizeof(arr2));
        if (flag) {
            day++;
        }
    }
    cout << day;

    return 0;
}