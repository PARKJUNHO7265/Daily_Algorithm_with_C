#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int N;
int arr[10010] = { 0 };
int count = -1;

void Push(int A) {
	count++;
	arr[count] = A;
}
void Pop() {
	if (count == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[count]);
		arr[count] = 0;
		count--;
	}
}
void Top() {
	if (count == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[count]);
	}
}
void Size() {
	printf("%d\n", count + 1);
}
void Empty() {
	if (count == -1) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char command[10];
		scanf("%s", &command);
		if (strcmp(command, "push") == 0) {
			int num;
			scanf("%d", &num);
			Push(num);
		}
		else if (strcmp(command, "pop") == 0) {
			Pop();
		}
		else if (strcmp(command, "size") == 0) {
			Size();
		}
		else if (strcmp(command, "empty") == 0) {
			Empty();
		}
		else if (strcmp(command, "top") == 0) {
			Top();
		}
	}
	return 0;
}
