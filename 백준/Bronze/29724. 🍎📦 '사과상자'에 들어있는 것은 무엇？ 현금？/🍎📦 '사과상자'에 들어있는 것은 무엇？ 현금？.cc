#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int apple = 0;
    int ans_we = 0;
    for (int i = 0; i < n; i++) {
        char a;
        int w, h, l;
        cin >> a >> w >> h >> l;

        if (a == 'A') {
            int a_w = w / 12;
            int a_h = h / 12;
            int a_l = l / 12;
            apple += a_w * a_h * a_l;
            ans_we += a_w * a_h * a_l * 500 + 1000;
        }
        else if (a == 'B') {
            ans_we += 6000;
        }
    }

    cout << ans_we << "\n" << apple * 4000;
    return 0;
}