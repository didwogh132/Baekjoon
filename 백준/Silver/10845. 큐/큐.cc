#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int back;
    int front;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command.compare("push") == 0) {
            int num;
            cin >> num;
            back = num;
            q.push(num);
        }
        else if (command.compare("pop") == 0) {
            if (q.size() == 0) {
                cout << "-1" << "\n";
            }
            else {
                front = q.front(); q.pop();
                cout << front << "\n";
            }
        }
        else if (command.compare("size") == 0) {
            cout << q.size() << "\n";
        }
        else if (command.compare("empty") == 0) {
            if (q.size() == 0) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else if (command.compare("front") == 0) {
            if (q.size() == 0) {
                cout << "-1" << "\n";
            }
            else {
                front = q.front();
                cout << front << "\n";
            }
        }
        else if (command.compare("back") == 0) {
            if (q.size() == 0) {
                cout << "-1" << "\n";
            }
            else {
                cout << back << "\n";
            }
        }
    }
    return 0;
}