#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

#define MAX 200010
#define mod 1000000007
#define M_PI 3.141592

using namespace std;

int mapydir[4][9] = { {1, 2, 1, 1, 0, -1, -1, -2, -1}, {0, 1, 1, 2, 3, 2, 1, 1, 0 } , {-1, -2, -1, -1, 0, 1, 1, 2, 1},{0, -1, -1, -2, -3, -2, -1, -1, 0} };
int mapxdir[4][9] = { {0, -1, -1, -2, -3, -2, -1, -1, 0} ,{1, 2, 1, 1, 0, -1, -1, -2, -1}, {0, 1, 1, 2, 3, 2, 1, 1, 0}, {-1, -2, -1, -1, 0, 1, 1, 2, 1} };
int Cost[] = { 1,2,7,10,5,10,7,2,1 };
int ydir[] = { 0, 1, 0, -1 };
int xdir[] = { -1, 0, 1, 0 };

int arr[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int x = n / 2;
    int y = n / 2;
    int dir = 0;
    int ans = 0;

    for (int i = 0; i < n * 2 - 1; i++) {
        int step = i / 2 + 1;
        for (int j = 0; j < step; j++) {
            int ny = y + ydir[dir];
            int nx = x + xdir[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                cout << ans;
                return 0;
            }
            int sand = arr[ny][nx];

            if (sand > 0) {
                int sand_next = sand;
                arr[ny][nx] = 0;
                for (int mapdir = 0; mapdir < 9; mapdir++) {
                    int sny = y + mapydir[dir][mapdir];
                    int snx = x + mapxdir[dir][mapdir];
                    int sand_to_move = sand * Cost[mapdir] / 100;
                    if (sny < 0 || snx < 0 || sny >= n || snx >= n) {
                        ans += sand_to_move;
                        sand_next -= sand_to_move;
                    }
                    else {
                        arr[sny][snx] += sand_to_move;
                        sand_next -= sand_to_move;
                    }
                }
                int nny = ny + ydir[dir];
                int nnx = nx + xdir[dir];
                if (nny < 0 || nnx < 0 || nny >= n || nnx >= n) {
                    ans += sand_next;
                }
                else {
                    arr[nny][nnx] += sand_next;
                }
            }
            y = ny, x = nx;
        }
        dir = (dir + 1) % 4;
    }
    return 0;
}