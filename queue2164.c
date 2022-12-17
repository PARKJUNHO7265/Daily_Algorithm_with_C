#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int up = 0;
int down;
int que[500100];
void pop() {
	up = (up + 1) % N;
}
void movebelow() {
	down = (down + 1) % N;
	que[down] = que[up];
	up = (up + 1) % N;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		que[i] = i + 1;
	}
	down = N - 1;
	while (1) {
		if (down == up) break;
		pop();
		if (down == up) break;
		movebelow();
	}
	printf("%d", que[down]);
	return 0;
}
