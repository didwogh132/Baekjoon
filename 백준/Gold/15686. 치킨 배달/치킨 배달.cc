#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
struct node {
    int y;
    int x;
};
node choice[14];
vector<node> chicken;
vector<node> home;
int arr[51][51];
int used[14];
int visited[51][51];
int Min = INT_MAX;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx] > visited[now.y][now.x] + 1) {
                visited[ny][nx] = visited[now.y][now.x] + 1;
            }
            else if (visited[ny][nx] > -1) continue;
            else {
                visited[ny][nx] = visited[now.y][now.x] + 1;
            }
            q.push({ ny, nx });
        }
    }
}

void func(int start, int num) {
    if (start >= m) {
        memset(visited, -1, sizeof(visited));
        int sum = 0;
        for (int i = 0; i < m; i++) {
            bfs(choice[i].y, choice[i].x);
        }
        for (int i = 0; i < home.size(); i++) {
            sum += visited[home[i].y][home[i].x];
        }
        if (sum < Min) Min = sum;
        return;
    }

    for (int i = num; i < chicken.size(); i++) {
        if (used[i] == 1) continue;
        choice[start] = chicken[i];
        used[i] = 1;
        func(start + 1, i + 1);
        choice[start] = { 0, 0 };
        used[i] = 0;
    }
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) home.push_back({ i,j });
            else if (arr[i][j] == 2) chicken.push_back({ i, j });
        }
    }
    func(0, 0);

    cout << Min;
    return 0;
}