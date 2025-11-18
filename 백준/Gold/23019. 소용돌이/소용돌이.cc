#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int ydir[] = { -1, 0, 1, 0 };
int xdir[] = { 0, 1, 0, -1 };

int n;
string arr[26];
bool visited[26][26];
string ans_min;
string ans_max;

void dfs(int y, int x, int depth, string& cur)
{
    if (depth == n * n) {
        if (ans_min.empty() || cur < ans_min) ans_min = cur;
        if (ans_max.empty() || cur > ans_max) ans_max = cur;
        return;
    }

    int minDist = 1000000;

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + ydir[dir];
        int nx = x + xdir[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;

        int dist = ny;
        if (dist > nx) dist = nx;
        if (dist > n - 1 - ny) dist = n - 1 - ny;
        if (dist > n - 1 - nx) dist = n - 1 - nx;

        if (dist < minDist) minDist = dist;
    }

    if (minDist == 1000000) {
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + ydir[dir];
        int nx = x + xdir[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;

        int dist = ny;
        if (dist > nx) dist = nx;
        if (dist > n - 1 - ny) dist = n - 1 - ny;
        if (dist > n - 1 - nx) dist = n - 1 - nx;

        if (dist != minDist) continue;

        visited[ny][nx] = true;
        cur.push_back(arr[ny][nx]);
        dfs(ny, nx, depth + 1, cur);
        cur.pop_back();
        visited[ny][nx] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ans_min = "";
        ans_max = "";

        int sy[4] = { 0, 0, n - 1, n - 1 };
        int sx[4] = { 0, n - 1, 0, n - 1 };

        for (int k = 0; k < 4; k++) {
            memset(visited, false, sizeof(visited));

            int y = sy[k];
            int x = sx[k];

            string cur = "";
            cur.push_back(arr[y][x]);
            visited[y][x] = true;

            dfs(y, x, 1, cur);
        }

        cout << ans_max << " " << ans_min << "\n";
    }

    return 0;
}