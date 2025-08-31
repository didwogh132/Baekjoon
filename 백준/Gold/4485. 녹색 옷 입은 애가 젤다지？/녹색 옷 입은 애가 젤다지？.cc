#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int n;
int arr[130][130];
int dist[130][130];
struct node {
   int ny;
   int nx;
   int cost;
   bool operator<(node right) const {
      if (cost < right.cost) return false;
      if (cost > right.cost) return true;
      return false;
   }
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int cnt = 1;

void dijkstra(int y, int x) {
   for(int i =0; i < n; i++) {
       for(int j =0; j < n; j++) {
           dist[i][j] = 21e8;
       }
    }
   priority_queue<node>pq;
   pq.push({ 0, 0, arr[0][0] });
   dist[0][0] = arr[0][0];

   while (!pq.empty()) {
      node now = pq.top(); pq.pop();

      if (dist[now.ny][now.nx] < now.cost) continue;

      for (int i = 0; i < 4; i++) {
         int ny = now.ny + ydir[i];
         int nx = now.nx + xdir[i];
         if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
         int nextcost = dist[now.ny][now.nx] + arr[ny][nx];
         if (dist[ny][nx] <= nextcost) continue;
         dist[ny][nx] = nextcost;

         pq.push({ ny, nx, nextcost });
      }
   }
}


int main() {

   while (1) {
      cin >> n;
      if (n == 0) break;
      memset(arr, 0, sizeof(arr));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
         }
      }

      dijkstra(0, 0);

      cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
      cnt++;
   }
}