#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int arr[501][501];
int temp[501][501];
int max = -100000000;
int compare(int a, int b) {
	return (a > b) ? a : b;
}
void sol() {
	temp[0][0] = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			temp[i][j] = compare(temp[i - 1][j], temp[i - 1][j - 1]) + arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (max < temp[n - 1][i]) {
			max = temp[n - 1][i];
		}
	}
	printf("%d", max);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	sol();
	return 0;
}
