#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n + 1, 0);

    for(int i =0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        num[a]++;
        num[b]++;
    }

    for(int i = 1; i <=n; i++) {
        cout << num[i] << "\n";
    }
    return 0;
}