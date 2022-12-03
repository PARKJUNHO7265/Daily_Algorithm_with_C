#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[301];
int temp[301];
int stack = 0;
int compare(int a, int b) {
	return (a > b) ? a : b;
}
void sol() {
	for (int i = 0; i < N; i++) {
		temp[i] = compare(temp[i - 3] + arr[i - 1], temp[i - 2]) + arr[i];
	}
	printf("%d", temp[N - 1]);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sol();
}
