#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n;
vector<int> arr[51];
int visited[51][51];
vector<int> candidate;
vector<int> score;
int Min = INT_MAX;
int cnt;

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num][num] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < arr[now].size(); i++) {
            int next = arr[now][i];
            if (visited[num][next] > -1) continue;
            visited[num][next] = visited[num][now] + 1;
            q.push(next);
        }
    }
}

int main() {
    cin >> n;
    memset(visited, -1, sizeof(visited));
    int from, to;
    while (true) {
        cin >> from >> to;
        if (from == -1 && to == -1) break;
        else {
            arr[from].push_back(to);
            arr[to].push_back(from);
        }
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
        int Max = 0;
        for (int j = 1; j <= n; j++) {
            if(visited[i][j] > Max) Max = visited[i][j];
        }
        score.push_back(Max);
        if (Max < Min) {
            Min = Max;
        }
    }
    for (int i = 0; i < score.size(); i++) {
        if (score[i] == Min) {
            candidate.push_back(i + 1);
            cnt++;
        }
    }
    sort(candidate.begin(), candidate.end());

    cout << Min << " " << cnt << "\n";
    for (int i = 0; i < candidate.size(); i++) {
        cout << candidate[i] << " ";
    }
    return 0;
}