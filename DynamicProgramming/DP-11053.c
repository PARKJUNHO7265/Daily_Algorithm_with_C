#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int result = 0;
int max;
int arr[10010];
int temp[10010];
int compare(int a, int b) {
	return (a > b) ? a : b;
}
void sol(int N) {
	for (int i = 1; i <= N; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (temp[j] > max) {
					max = temp[j];
				}
			}

		}
		temp[i] = max + 1;
		result = compare(result, temp[i]);
	}
	printf("%d", result);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	sol(N);
	return 0;
}
