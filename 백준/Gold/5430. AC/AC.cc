#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        string p, x;
        int n;
        deque<int> dq;
        bool flag = true;
        bool ans_flag = true;
        cin >> p >> n >> x;

        string num;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] >= '0' && x[i] <= '9') {
                num += x[i];
            }
            else if (x[i] == ',' || x[i] == ']') {
                if (n == 0) break;
                dq.push_back(stoi(num));
                num.clear();
            }
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                if (flag) flag = false;
                else flag = true;
            }
            else {
                if (dq.empty()) {
                    ans_flag = false;
                    break;
                }
                if (flag) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }

        if (ans_flag) {
            cout << "[";
            while (!dq.empty()) {
                if (flag) {
                    int now = dq.front(); dq.pop_front();

                    if (!dq.empty()) {
                        cout << now << ",";
                    }
                    else {
                        cout << now;
                    }
                }
                else {
                    int now = dq.back(); dq.pop_back();

                    if (!dq.empty()) {
                        cout << now << ",";
                    }
                    else {
                        cout << now;
                    }
                }
            }
            cout << "]" << "\n";
        }
        else {
            cout << "error" << "\n";
        }
    }

    return 0;
}
