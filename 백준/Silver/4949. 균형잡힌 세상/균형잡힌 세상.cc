#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string name;
    while (getline(cin, name)) {
        if (name == ".") break;
        else {
            stack<char> arr;
            bool flag = true;
            for (int i = 0; i < name.size(); i++) {
                if (name[i] == '(' || name[i] == '[') {
                    arr.push(name[i]);
                }
                else if (name[i] == ')' || name[i] == ']') {
                    if (arr.empty()) {
                        flag = false;
                        break;
                    }
                    char a = arr.top();
                    if (a == '(' && name[i] == ')') arr.pop();
                    else if (a == '[' && name[i] == ']') arr.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
                if (i == name.size() - 1) {
                    if (arr.size() != 0) flag = false;
                }
            }

            if (flag) {
                cout << "yes" << "\n";
            }
            else {
                cout << "no" << "\n";
            }
        }
    }

    return 0;
}