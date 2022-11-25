#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int T;
int count = 0;

int main() {
	scanf("%d ", &T);
	for (int i = 0; i < T; i++) {
		int state = 0;
		char str[100];
		scanf("%s", &str);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '(') {
				count++;
			}
			else {
				count--;
			}
			if (count < 0) {
				state = 1;
			}
		}
		if (count == 0 && state == 0) {
			printf("YES\n");
			count = 0;
		}
		else {
			printf("NO\n");
			count = 0;
		}
	}
	return 0;
}
