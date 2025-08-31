#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[100010];
int visited[100010];
int dist[100010];
vector<int>arr2;

void bfs(int start) {
    queue<int>q;
    q.push(start);
    visited[start] = 1;
    dist[start] = -1;
    while (!q.empty()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) next = now * 2;
            else if (i == 1) next = now + 1;
            else next = now - 1;

            if (next < 0 || next > 100000) continue;

            if (visited[next] == -1) {
                visited[next] = visited[now] + 1;
                dist[next] = now;
                q.push(next);
            }      
        
        }
    }
}

int main() {
    
    cin >> n >> m;
    memset(visited, -1, sizeof(visited));
    memset(dist, -1, sizeof(dist));
    bfs(n);

    cout << visited[m] - 1 << "\n";
    int num = m;
    int cnt = 0;
    arr2.push_back(num);
    while (dist[num] != -1) {
        arr2.push_back(dist[num]);
        num = dist[num];
    }
    for (int i = arr2.size() - 1; i >= 0; i--) {
        cout << arr2[i] << " ";
    }
    return 0;
}