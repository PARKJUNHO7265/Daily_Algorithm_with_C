#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    char str[110];
	char arr[110];
	while (1) {
		int count = -1;
		gets(str);
		if (str[0] == '.') {
			break;
		}
		for (int j = 0; str[j] != '.'; j++) {
			if (str[j] == '('||str[j]=='[') {
				arr[++count] = str[j];
			}
			else if (str[j] == ')') {
				if (count > -1 && arr[count] == '(') {
					--count;
				}
				else {
					count=-2;
					break;
				}
			}
			else if (str[j] == ']') {
				if (count > -1 && arr[count] == '[') {
					--count;
				}
				else {
					count=-2;
					break;
				}
			}
		}
		if (count == -1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}
