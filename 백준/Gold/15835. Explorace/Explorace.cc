#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e, cost;
    bool operator<(const node& other) {
        return cost < other.cost;
    }
};
vector<int> parent;
vector<int> sz;
vector<node> arr;

int find(int x) {
    if(parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b){
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return false;

    if(sz[ra] < sz[rb]) swap(ra, rb);

    parent[rb] = ra;
    sz[ra] += sz[rb];
    return true;
}

int main() {

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;
        parent.resize(n+1);
        sz.resize(n+1, 1);
        arr.resize(m);
        for(int i =0; i <=n; i++) parent[i] =i;

        for(int i =0; i< m; i++) {
            cin >> arr[i].s >> arr[i].e >>arr[i].cost;
        }

        sort(arr.begin(), arr.end());

        int sum = 0;
        int cnt = 0;

        for(int i =0; i < arr.size(); i++) {
            if(cnt == n-1) break;
            if(unite(arr[i].s, arr[i].e)) {
                sum += arr[i].cost;
                cnt++;
            }
        }

        cout << "Case #" << tc << ": " << sum << " meters\n";
    }
    
    return 0;
}