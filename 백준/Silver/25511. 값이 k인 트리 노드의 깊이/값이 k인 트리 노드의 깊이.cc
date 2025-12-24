#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> tree;
vector<int> visit;
bool flag = false;
void func(int num, int depth) {
    if (visit[num] == k) {
        cout << depth;
        flag = true;
        return;
    }

    if (tree[num].empty()) {
        return;
    }
    else if(!flag){
        for (int i = 0; i < tree[num].size(); i++) {
            func(tree[num][i], depth + 1);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    
    tree.resize(n);
    visit.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
    }

    for (int i = 0; i < n; i++) cin >> visit[i];

    func(0, 0);
    return 0;
}