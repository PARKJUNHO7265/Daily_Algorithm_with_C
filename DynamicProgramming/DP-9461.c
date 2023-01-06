#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int T;
long long arr[101];
void sol() {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	arr[9] = 7;
	for (int i = 10; i <= 100; i++) {
		arr[i] = (arr[i - 1] + arr[i - 5]);
	}
	return;
}
int main() {
	scanf("%d", &T);
	sol();
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
	return 0;
}
