#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int n, m;
int visited[1010][1010];
int answer[1010][1010];
int zero_cnt[1010][1010];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
};
string arr[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(zero_cnt, -1, sizeof(zero_cnt));

    vector<int> zero_size;
    int next_cnt = 0;
    for (int sy = 0; sy < n; sy++) {
        for (int sx = 0; sx < m; sx++) {
            if (arr[sy][sx] == '0' && zero_cnt[sy][sx] == -1) {
                queue<node> q;
                q.push({ sy, sx });
                zero_cnt[sy][sx] = next_cnt;
                int size_cnt = 1;

                while (!q.empty()) {
                    node now = q.front(); q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ny = now.y + ydir[i];
                        int nx = now.x + xdir[i];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                        if (arr[ny][nx] == '1') continue;
                        if (zero_cnt[ny][nx] != -1) continue;
                        zero_cnt[ny][nx] = next_cnt;
                        size_cnt++;
                        q.push({ ny, nx });
                    }
                }
                zero_size.push_back(size_cnt);
                next_cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0') {
                answer[i][j] = 0;
            }
            else {
                int used[4];
                int used_cnt = 0;
                int sum_size = 1;

                for (int k = 0; k < 4; k++) {
                    int ny = i + ydir[k];
                    int nx = j + xdir[k];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                    int ncnt = zero_cnt[ny][nx];
                    if (ncnt == -1) continue;

                    int dup = 0;
                    for (int t = 0; t < used_cnt; t++) {
                        if (used[t] == ncnt) {
                            dup = 1;
                            break;
                        }
                    }
                    if (dup == 1) continue;

                    used[used_cnt] = ncnt;
                    used_cnt++;
                    sum_size += zero_size[ncnt];
                }
                answer[i][j] = sum_size % 10;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answer[i][j];
        }
        cout << "\n";
    }

    return 0;
}