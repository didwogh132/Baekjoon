#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n, m;
int arr[101][101];
int arr2[101][101];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int visited[101][101];
int ans;
int cnt;
int Time;
struct node {
    int y;
    int x;
};

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 1) continue;
            if (visited[ny][nx] > 0) continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }

}

int main() {
    
    cin >> n >> m;
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (cnt >= 0) {
        memset(visited, 0, sizeof(visited));
        memset(arr2, 0, sizeof(arr2));
        bfs(0, 0);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + ydir[k];
                    int nx = j + xdir[k];
                    if (arr[i][j] == 1 && visited[ny][nx] != 0) {
                        arr2[i][j] = 1;
                        cnt++;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] -= arr2[i][j];
            }
        }
        
        if (cnt == 0) {
            break;
        }
        else {
            Time++;
            ans = cnt;
        }
    }

    cout << Time << "\n" << ans;
    return 0;
}