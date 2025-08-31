#include <iostream>
#include <deque>

using namespace std;

int main() {
    
    int n, q;

    cin >> n >> q;
    deque<int> dq_front;
    deque<int> dq_back;
    int num = 0;

    for (int i = 0; i < q; i++) {
        char a;
        int x;
        cin >> a;
        if (a == 'B') {
            if (dq_back.empty()) continue;
            else {
                dq_front.push_front(num);
                num = dq_back.back();
                dq_back.pop_back();
            }
        }
        else if (a == 'F') {
            if (dq_front.empty()) continue;
            else {
                dq_back.push_back(num);
                num = dq_front.front();
                dq_front.pop_front();
            }
        }
        else if (a == 'A') {
            cin >> x;
            if (num == 0) {
                num = x;
            }
            else {
                dq_back.push_back(num);
                num = x;
                dq_front.clear();
            }
        }
        else {
            int erase = 0;
            for (int i = dq_back.size() -1; i >= 0; i--) {
                if (dq_back[i] != erase) {
                    erase = dq_back[i];
                }
                else {
                    dq_back.erase(dq_back.begin() + i);
                }
            }
        }
    }
    cout << num << "\n";

    if (dq_back.empty()) {
        cout << -1;
    }
    else {
        for (int i = dq_back.size() - 1; i >= 0; i--) {
            cout << dq_back[i] << " ";
        }
    }
    cout << "\n";
    if (dq_front.empty()) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 0; i < dq_front.size(); i++) {
            cout << dq_front[i] << " ";
        }
    }

    return 0;
}