#include <iostream>
#include <string>

using namespace std;

int a;
string s;
int cnt[130];
int main() {
    cin >> a >> s;

    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;

    if (cnt['b'] > cnt['s']) cout << "bigdata?";
    else if (cnt['b'] == cnt['s']) cout << "bigdata? security!";
    else cout << "security!";

    return 0;
}