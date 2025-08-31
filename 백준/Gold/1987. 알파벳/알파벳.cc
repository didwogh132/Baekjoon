#include <iostream>
#include <string>

using namespace std;

int n, m;
string arr[21];
int used[30];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int Max;

void dfs(int y, int x, int cnt) {
    if (cnt > Max) {
        Max = cnt;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (used[arr[ny][nx] - 'A'] == 1) continue;
        used[arr[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        used[arr[ny][nx] - 'A'] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    used[arr[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << Max;
    
    return 0;
}