#include<stdio.h>
#include<string.h>


int main() {
	int n,x;
	int stack[10005], top = 0;
	char s[6];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		if (s[0] == 'p' && s[1] == 'u') {
			scanf("%d", &x);
			top++;
			stack[top] = x;
		}
		else if (s[0] == 'p') {
			if (top < 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[top]);
				top--;
			}
		}
		else if (s[0] == 's') {
			printf("%d\n", top);
		}
		else if (s[0] == 'e') {
			if (top < 1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else {
			if (top < 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[top]);
			}
		}
	}
}