#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    if (n * m == 2) cout << "ChongChong";
    else cout << "GomGom";

    return 0;
}