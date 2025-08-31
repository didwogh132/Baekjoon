#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[8][8];
int arr2[8][8];
int visited[8][8];
int used[8][8];
struct node {
    int y;
    int x;
};
queue<node> q;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
vector<node> block;
vector<node> emptys;
int Max;

void bfs() {
    memset(visited, -1, sizeof(visited));
    queue<node> q2(q);

    while (!q2.empty()) {
        node now = q2.front(); q2.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] > -1) continue;
            if (arr2[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            q2.push({ ny, nx });
        }
    }
}

void func(int depth, int idx) {
    if (depth == 3) {
        int cnt = 0;
        memcpy(arr2, arr, sizeof(arr));
        for (int i = 0; i < block.size(); i++) {
            arr2[block[i].y][block[i].x] = 1;
        }
        bfs();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == -1 && arr2[i][j] == 0) cnt++;
            }
        }
        if (cnt > Max) Max = cnt;
        return;
    }

    for (int i = idx; i < emptys.size(); i++) {
        block.push_back(emptys[i]);
        func(depth + 1, i + 1);
        block.pop_back();
    }

}


int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push({ i, j });
            }
            if (arr[i][j] == 0) {
                emptys.push_back({ i, j });
            }
        }
    }
    func(0, 0);

    cout << Max;

    return 0;
}