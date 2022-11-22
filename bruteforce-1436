#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int count = 0;
int num_temp;

void Input() {
	scanf("%d", &N);
}

void solution(int A) {
	while (A >= 666) {
		if (A % 1000 == 666) {
			count++;
			break;
		}
		else {
			A /= 10;
		}
	}
}

int main() {
	int num = 665;
	Input();
	while (1) {
		solution(num);
		if (count == N) {
			break;
		}
		num++;
	}
	printf("%d", num);
}
