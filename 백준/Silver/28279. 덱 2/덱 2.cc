#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    deque<int> dq;
    int back;
    int front;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command.compare("1") == 0) {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (command.compare("2") == 0) {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (command.compare("3") == 0) {
            if (dq.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                front = dq.front(); dq.pop_front();
                cout << front << "\n";
            }
        }
        else if (command.compare("4") == 0) {
            if (dq.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                back = dq.back(); dq.pop_back();
                cout << back << "\n";
            }
        }
        else if (command.compare("5") == 0) {
            cout << dq.size() << "\n";
        }
        else if (command.compare("6") == 0) {
            if (dq.size() == 0) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if (command.compare("7") == 0) {
            if (dq.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                front = dq.front();
                cout << front << "\n";
            }
        }
        else if (command.compare("8") == 0) {
            if (dq.size() == 0) {
                cout << -1 << "\n";
            }
            else {
                back = dq.back();
                cout << back << "\n";
            }
        }
    }
    return 0;
}