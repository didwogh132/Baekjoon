#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, string> arr;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        cout << arr[a] << "\n";
    }

    return 0;
}