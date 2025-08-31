#include <iostream>
#include <vector>

using namespace std;

int n, a, m;
int tree[52];
vector<int>arr[52];
int cnt;

void dfs(int num) {
    if (num == m) return;
    
    int childcnt = 0;
    for (int i = 0; i < arr[num].size(); i++) {
        if (arr[num][i] == m) {
            continue;
        }
        dfs(arr[num][i]);
        childcnt++;
    }
    if (childcnt == 0) cnt++;
}


int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        if (tree[i] == -1) {
            a = i;
            continue;
        }
        arr[tree[i]].push_back(i);
    }
    cin >> m;

    

    if (m == a) {
        cout << 0;
    }
    else{
        dfs(a);
        cout << cnt;
    }

    return 0;
}