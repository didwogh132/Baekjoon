#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int r, c;
char arr[251][251];
bool visit[251][251];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int ans_sheep, ans_wolf;
int sheep, wolf;
void dfs(int y, int x) {
    if (visit[y][x]) return;

    visit[y][x] = true;
    if (arr[y][x] == 'v') wolf++;
    else if (arr[y][x] == 'o') sheep++;

    for (int i = 0; i < 4; i++) {
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (arr[ny][nx] == '#') continue;
        
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visit[i][j]) {
                sheep = 0, wolf = 0;
                if (arr[i][j] == 'v') wolf++;
                else if (arr[i][j] == 'o') sheep++;
                dfs(i, j);

                if (sheep > wolf) {
                    ans_sheep += sheep;
                }
                else if (wolf >= sheep) {
                    ans_wolf += wolf;
                }
            }
        }
    }

    cout << ans_sheep << " " << ans_wolf;
    return 0;
}