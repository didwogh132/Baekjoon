#include <iostream>

using namespace std;


int main() {
    unsigned int pack = 0x00;

    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        pack = (pack << 3) | (unsigned int)(x - 1);
    }

    unsigned int asc = 0x00;
    unsigned int desc = 0x00;

    for (int i = 0; i < 8; i++) {
        asc = (asc << 3) | (unsigned int)i;
    }

    for (int i = 7; i >= 0; i--) {
        desc = (desc << 3) | (unsigned int)i;
    }

    if (pack == asc) {
        cout << "ascending";
    }
    else if (pack == desc) {
        cout << "descending";
    }
    else {
        cout << "mixed";
    }



    return 0;
}