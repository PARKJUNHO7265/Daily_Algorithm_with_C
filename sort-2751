#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[1000001];
int j;
int compare(const void *one, const void *two) {
	if (*(int*)one > *(int*)two) return 1;
	else if (*(int*)one < *(int*)two) return -1;
	else return 0;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), compare);
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
