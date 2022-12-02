#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[1000001];
void sol(int N) {
	arr[1] = 1;
	arr[2] = 2;
	if (N <= 2) return;
	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
	}
	return;
}
int main() {
	scanf("%d", &N);
	sol(N);
	printf("%d",arr[N]);
}
