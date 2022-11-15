#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[100];
int i;
int solution() {
	for (i = 1; i < N; i++) {
		int j = 0;
		int num;
		num = i;
		while (num / 10 > 0) {
			arr[j] = num % 10;
			j++;
			num /= 10;
		}
		arr[j] = num;
		int sum = i;
		for (int k = 0; k <= j; k++) {
			sum += arr[k];
		}
		if (sum == N) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
int main() {
	scanf("%d", &N);
	solution();
}
