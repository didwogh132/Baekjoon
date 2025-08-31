#include <iostream>

using namespace std;

int main() {
    int nin, nout;
    int ntime = 0;
    int Max = 0;
    for (int i = 0; i < 10; i++) {
        cin >> nout >> nin;
        ntime = ntime - nout + nin;
        if (ntime > Max) Max = ntime;
    }
    cout << Max;
    return 0;
}