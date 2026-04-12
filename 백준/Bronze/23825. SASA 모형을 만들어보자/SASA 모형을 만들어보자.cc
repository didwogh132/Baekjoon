#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int n_cnt = n / 2;
    int m_cnt = m / 2;

    cout << ((n_cnt <= m_cnt) ? n_cnt : m_cnt);
    return 0;
}