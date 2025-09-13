#include <stdio.h>

using namespace std;


int main() {
    unsigned int pack = 0x00;

    for (int i = 0; i < 8; i++) {
        int x;
        scanf("%d", &x);
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
        printf("ascending");
    }
    else if (pack == desc) {
        printf("descending");
    }
    else {
        printf("mixed");
    }



    return 0;
}