#include <bits/stdc++.h>
using namespace std;
struct Coin { long long v, cnt; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  long long C;
    cin >> N >> C;
    array<Coin, 20> coin;
    for (int i = 0; i < N; ++i) cin >> coin[i].v >> coin[i].cnt;

    sort(coin.begin(), coin.begin() + N,
         [](const Coin& a, const Coin& b) { return a.v > b.v; });

    long long answer = 0;
    array<long long, 20> use{};

    while (true) {
        long long pay = C;
        use.fill(0);

        for (int i = 0; i < N; ++i) {
            if (coin[i].v > pay) continue;
            long long take = min(coin[i].cnt, pay / coin[i].v);
            use[i] = take;
            pay -= take * coin[i].v;
        }

        if (pay > 0) {
            bool ok = false;
            for (int i = N - 1; i >= 0; --i) {
                if (coin[i].cnt > use[i]) {
                    ++use[i];
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }

        long long limit = LLONG_MAX;
        for (int i = 0; i < N; ++i) {
            if (use[i] == 0) continue;
            limit = min(limit, coin[i].cnt / use[i]);
        }

        answer += limit;
        for (int i = 0; i < N; ++i) {
            coin[i].cnt -= use[i] * limit;
        }
    }

    cout << answer << '\n';
    return 0;
}
