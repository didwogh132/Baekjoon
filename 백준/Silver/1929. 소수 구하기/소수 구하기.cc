#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<bool> primenum;
    primenum.resize(n + 1, false);

    primenum[0] = primenum[1] = true;

    for (int i = 2; i * i <= n; i++) {
        if (primenum[i]) continue;
        else {
            for (int j = 2; j * i <= n; j++) {
                primenum[i * j] = true;
            }
        }
    }

    for (int i = m; i <= n; i++) {
        if (!primenum[i]) cout << i << "\n";
    }

    return 0;
}