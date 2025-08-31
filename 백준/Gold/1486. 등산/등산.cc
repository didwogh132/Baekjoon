#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, t, d;
struct node {
    int y, x;
    int time;
    bool operator <(node right) const {
        return time > right.time;
    }
};
int arr[26][26];
int visited[26][26];
int visited2[26][26];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void dijkstra(int y, int x) {
    priority_queue<node> pq;
    pq.push({ y, x, 0 });
    visited[y][x] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (visited[now.y][now.x] < now.time) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nexttime;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (abs(arr[now.y][now.x] - arr[ny][nx]) > t) continue;
            if (arr[ny][nx] > arr[now.y][now.x]) {
                nexttime = visited[now.y][now.x] + (arr[ny][nx] - arr[now.y][now.x]) * (arr[ny][nx] - arr[now.y][now.x]);
            }
            else {
                nexttime = visited[now.y][now.x] + 1;

            }
            if (nexttime > d) continue;
            if (nexttime < visited[ny][nx]) {
                visited[ny][nx] = nexttime;
            }
            else if (visited[ny][nx] > -1) continue;
            else {
                visited[ny][nx] = nexttime;
            }
            pq.push({ ny, nx, nexttime });
        }
    }
}
void dijkstra2(int y, int x) {
    priority_queue<node> pq;
    pq.push({ y, x, 0 });
    visited2[y][x] = visited[y][x];

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (visited2[now.y][now.x] < now.time) continue;
        if (visited2[now.y][now.x] > d) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nexttime;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (abs(arr[now.y][now.x] - arr[ny][nx]) > t) continue;
            if (arr[ny][nx] > arr[now.y][now.x]) {
                nexttime = visited2[now.y][now.x] + (arr[ny][nx] - arr[now.y][now.x]) * (arr[ny][nx] - arr[now.y][now.x]);
            }
            else {
                nexttime = visited2[now.y][now.x] + 1;

            }
            if (nexttime > d) continue;
            if (nexttime < visited2[ny][nx]) {
                visited2[ny][nx] = nexttime;
            }
            else if (visited2[ny][nx] > -1) continue;
            else {
                visited2[ny][nx] = nexttime;
            }
            pq.push({ ny, nx, nexttime });
        }
    }
}

int main() {
    memset(visited, -1, sizeof(visited));
    cin >> n >> m >> t >> d;
    char a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a >= 'a' && a <= 'z') {
                arr[i][j] = a - 'a' + 26;
            }
            else {
                arr[i][j] = a - 'A';
            }
        }
    }
    dijkstra(0, 0);

    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] != -1) {
                if (arr[i][j] > max) {
                    memset(visited2, -1, sizeof(visited2));
                    dijkstra2(i, j);
                    if (visited2[0][0] != -1) {
                        max = arr[i][j];
                    }
                }
            }
        }
    }

    cout << max;

    return 0;
}