#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    deque<int> dq;
    int n = 0; // 0 = 왼쪽 뒤, 오른쪽 앞, 1 = 위 뒤, 아래 앞 2 = 왼쪽 앞, 오른쪽 뒤 3 = 위 앞, 아래 뒤
    int b = 0;
    int w = 0;

    for (int i = 0; i < q; i++) {
        string query;
        char a;
        cin >> query;
        if (query == "push") {
            cin >> a;
            if (a == 'b') {
                dq.push_back(1);
                b++;
            }
            else if (a == 'w') {
                dq.push_back(2);
                w++;
            }
            if (n == 1) {
                while (!dq.empty() && dq.front() != 2) {
                    dq.pop_front();
                    b--;
                }
            }
            else if (n == 3) {
                while (!dq.empty() && dq.back() != 2) {
                    dq.pop_back();
                    b--;
                }
            }
        }
        else if (query == "pop") {
            if (dq.empty()) continue;
            else {
                if (dq.front() == 1) b--;
                else if (dq.front() == 2) w--;
                dq.pop_front();
            }
            if (n == 1) {
                while (!dq.empty() && dq.front() != 2) {
                    dq.pop_front();
                    b--;
                }
            }
            else if (n == 3) {
                while (!dq.empty() && dq.back() != 2) {
                    dq.pop_back();
                    b--;
                }
            }
        }
        else if (query == "rotate") {
            cin >> a;
            if (a == 'l') {
                n = (n + 3) % 4;
                if (n == 1) {
                    while (!dq.empty() && dq.front() != 2) {
                        dq.pop_front();
                        b--;
                    }
                }
                else if (n == 3) {
                    while (!dq.empty() && dq.back() != 2) {
                        dq.pop_back();
                        b--;
                    }
                }
            }
            else if (a == 'r') {
                n = (n + 1) % 4;
                if (n == 1) {
                    while (!dq.empty() && dq.front() != 2) {
                        dq.pop_front();
                        b--;
                    }
                }
                else if (n == 3) {
                    while (!dq.empty() && dq.back() != 2) {
                        dq.pop_back();
                        b--;
                    }
                }
            }
        }
        else if (query == "count") {
            cin >> a;
            if (a == 'b') {
                cout << b << "\n";
            }
            else if (a == 'w') {
                cout << w << "\n";
            }
        }
    }
    
    return 0;
}