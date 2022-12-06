#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int sum = 0;
int arr[10010];
int temp[10010];
int MAX(int a, int b) {
	return (a > b) ? a : b;
}
void sol(int N) {
	temp[1] = arr[1];
	temp[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++) {
		temp[i] = MAX(temp[i - 2] + arr[i], MAX(temp[i - 1], temp[i - 3] + arr[i - 1] + arr[i]));
	}
	printf("%d", temp[N]);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	sol(N);
	return 0;
}
