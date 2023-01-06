#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[1000000];
void sol(int N) {
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		int min = 100000;
		if (i % 3 == 0) {
			arr[i] = arr[i / 3] + 1;
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		if (i % 2 == 0) {
			arr[i] = arr[i / 2] + 1;
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		arr[i] = arr[i - 1] + 1;
		if (arr[i] < min) {
			min = arr[i];
		}
		arr[i] = min;
	}
	printf("%d", arr[N]);
}
int main() {
	scanf("%d", &N);
	sol(N);
}
