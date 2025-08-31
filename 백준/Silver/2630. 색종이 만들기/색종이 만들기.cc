#include <iostream>

using namespace std;

int n;
int arr[130][130];
int white = 0;
int blue = 0;

void divid(int y1, int x1, int size) {
    int first = arr[y1][x1];
    bool same = true;

    for (int i = y1; i < y1 + size; i++) {
        for (int j = x1; j < x1 + size; j++) {
            if (arr[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (first == 0) white++;
        else blue++;
        return;
    }

    int half = size / 2;
    divid(y1, x1, half);
    divid(y1, x1 + half, half);
    divid(y1 + half, x1, half);
    divid(y1 + half, x1 + half, half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    divid(0, 0, n);

    cout << white << "\n" << blue;
    return 0;
}