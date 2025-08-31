#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n;
string arr[151];
struct Node {
	int y;
	int x;
};
int visited[151][151];

void dijkstra(int y, int x) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	queue<Node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		int ydir[] = { -1, 1, 0, 0 };
		int xdir[] = { 0, 0, -1, 1 };

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] > visited[now.y][now.x] && arr[ny][nx] == '1') {
				visited[ny][nx] = visited[now.y][now.x];
			}
			else if (arr[ny][nx] == '0' && visited[ny][nx] > visited[now.y][now.x] + 1 ) {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			else if (visited[ny][nx] >= 0) continue;
			else if (arr[ny][nx] == '1'){
				visited[ny][nx] = visited[now.y][now.x];
			}
			else if (arr[ny][nx] == '0') {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			
			q.push({ ny,nx });
		}
	}

}


int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dijkstra(0, 0);

	cout << visited[n - 1][n - 1];

	return 0;
}