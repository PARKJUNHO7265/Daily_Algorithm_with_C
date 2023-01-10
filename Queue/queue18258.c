#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int N;
int FRONT = 0;
int REAR = -1;
int que[2000000];
void empty() {
	if (REAR - FRONT == -1) printf("1\n");
	else printf("0\n");
}
void push(int data) {
	REAR++;
	que[REAR] = data;
}
void pop() {
	if (REAR - FRONT == -1) printf("-1\n");
	else {
		printf("%d\n", que[FRONT]);
		FRONT++;
	}
}
void size() {
	printf("%d\n",REAR - FRONT + 1);
}
void front() {
	if (REAR - FRONT == -1) printf("-1\n");
	else printf("%d\n", que[FRONT]);
}
void back() {
	if (REAR - FRONT == -1) printf("-1\n");
	else printf("%d\n", que[REAR]);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char str[10];
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			int data;
			scanf("%d", &data);
			push(data);
		}
		else if (!strcmp(str, "front")) {
			front();
		}
		else if (!strcmp(str, "pop")) {
			pop();
		}
		else if (!strcmp(str, "size")) {
			size();
		}
		else if (!strcmp(str, "empty")) {
			empty();
		}
		else if (!strcmp(str, "back")) {
			back();
		}
	}
}
