#include <stdio.h>

int main() {
    unsigned int pack = 0x00;

    for (int i = 0; i < 8; i++) {
        int x;
        scanf("%d", &x);
        pack = (pack << 3) | (unsigned int)(x - 1);
    }

    if (pack == 0x53977) printf("ascending");
    else if (pack == 0xFAC688) printf("descending");
    else printf("mixed");

    return 0;
}