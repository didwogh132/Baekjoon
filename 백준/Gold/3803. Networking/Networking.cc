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
vector<node> arr;

int find(int x) {
    if(parent[x] == x ) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return false;

    parent[rb] = ra;

    return true;
}

int main() {
    int p, r;
    
    while(true) {
        cin >> p;
        if(p == 0) break;
        else cin >> r;

        
        parent.resize(p+1);
        arr.resize(r);

        for(int i =0; i <= p; i++) {
            parent[i] = i;
        }

        for(int i =0; i < r; i++) {
            cin >> arr[i].s >> arr[i].e >> arr[i].cost;
        }

        sort(arr.begin(), arr.end());

        int sum = 0;
        int cnt = 0;
        for(int i =0; i < arr.size(); i++) {
            if(cnt == p -1) break;
            if(unite(arr[i].s, arr[i].e)) {
                sum += arr[i].cost;
                cnt++;
            }
        }

        cout << sum << "\n";
    }
    return 0;
}