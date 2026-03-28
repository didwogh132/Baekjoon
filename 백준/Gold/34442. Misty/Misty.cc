#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int s, e, cost, idx;
    bool operator<(const node& other) {
        return cost < other.cost;
    }
};

vector<node> arr;
vector<int> parent;
vector<int> sz;

int find(int x) {
    if(parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return false;

    if(sz[ra] < sz[rb]) swap(ra, rb);

    parent[rb] = ra;
    sz[ra] += sz[rb];

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    sz.resize(n+1, 1);
    
    for(int i = 0; i <= n; i++) parent[i] = i;

    for(int i =0; i< m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        arr.push_back({s, e, cost, i + 1});
    }

    sort(arr.begin(), arr.end());

    cout << n-1 << "\n";

    for(int i =0; i < m; i++) {
        if(unite(arr[i].s, arr[i].e)) {
            cout << arr[i].idx << "\n";
        }
    }
    
    return 0;
}