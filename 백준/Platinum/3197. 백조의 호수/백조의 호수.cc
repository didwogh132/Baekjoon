#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int y;
    int x;
};
node swanS;
node swanE;
int swan_cnt;
queue<node> nextswan;
queue<node> nextwater;
int n, m;
int day;
string arr[1501];
int visited[1501][1501];
int swanvisit[1501][1501];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
bool flag = false;

void water_bfs() {
    queue<node> water(nextwater);
    nextwater = queue<node>();

    while (!water.empty()) {
        node now = water.front(); water.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] == 1) continue;
            if (arr[ny][nx] == 'X') {
                arr[ny][nx] = '.';
                visited[ny][nx] = 1;
                nextwater.push({ ny, nx });
            }
            else {
                visited[ny][nx] = 1;
                water.push({ ny, nx });
            }
        }
    }
}
void swan_bfs() {
    queue<node> swan(nextswan);
    nextswan = queue<node>();

    while (!swan.empty()) {
        node now = swan.front(); swan.pop();

        if (now.y == swanE.y && now.x == swanE.x) {
            if (arr[now.y][now.x] == 'L') {
                flag = true;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (swanvisit[ny][nx] == 1) continue;
            if (arr[ny][nx] == 'X') {
                swanvisit[ny][nx] = 1;
                nextswan.push({ ny, nx });
            }
            else {
                swanvisit[ny][nx] = 1;
                swan.push({ ny, nx });
            }
        }
    }
}


int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' || arr[i][j] == 'L') {
                nextwater.push({ i, j });
                visited[i][j] = 1;
                if (arr[i][j] == 'L') {
                    if (swan_cnt == 0) {
                        swanS = { i, j };
                        nextswan.push({ i, j });
                        swanvisit[i][j] = 1;
                        swan_cnt++;
                    }
                    else {
                        swanE = { i, j };
                    }
                }
            }
        }
    }

    while (true) {

        swan_bfs();
        water_bfs();

        if (flag) {
            cout << day;
            break;
        }
        else {
            day++;
        }
    }

    return 0;
}