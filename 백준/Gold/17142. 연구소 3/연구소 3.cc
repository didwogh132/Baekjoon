#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int arr[52][52];
int visited[52][52];
int used[260];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

struct node {
    int y;
    int x;
};

vector<node> vir;
vector<node> use_vir;
queue<node> q;
int Max;
int Min = INT_MAX;

void bfs() {
    while (!q.empty()) {
        node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (arr[ny][nx] == 1) continue;
            if (visited[ny][nx] > visited[now.y][now.x] + 1) {
                visited[ny][nx] = visited[now.y][now.x] + 1;
            }
            else if (visited[ny][nx] > -1) continue;
            else {
                visited[ny][nx] = visited[now.y][now.x] + 1;
            }
            q.push({ ny,nx });
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && visited[i][j] > Max) Max = visited[i][j];
            else if (arr[i][j] == 0 && visited[i][j] == -1) {
                Max = -1;
                return;
            }
        }
    }
}

void func(int num, int idx) {
    if (num == m) {
        memset(visited, -1, sizeof(visited));
        Max = 0;
        for (int i = 0; i < use_vir.size(); i++) {
            q.push(use_vir[i]);
            visited[use_vir[i].y][use_vir[i].x] = 0;
        }
        bfs();
        if (Max != -1 && Max < Min) Min = Max;
        return;
    }
    for (int i = idx; i < vir.size(); i++) {
        if (used[i] == 1) continue;
        used[i] == 1;
        use_vir.push_back(vir[i]);
        func(num + 1, i + 1);
        used[i] == 0;
        use_vir.pop_back();
    }
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                vir.push_back({ i, j });
            }
        }
    }
    func(0, 0);
    if (Min == INT_MAX) {
        cout << -1;
    }
    else {
        cout << Min;
    }

    return 0;
}