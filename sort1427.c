#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[100];
int i = 0;
int compare(const void* one, const void* two) {
	if (*(int*)one > *(int*)two) return -1;
	else if (*(int*)one < *(int*)two) return 1;
	else return 0;
}
void sol() {
	while (1) {
		if (N <= 0) break;
		arr[i] = N % 10;
		N /= 10;
		i++;
	}
	qsort(arr, i, sizeof(int), compare);
	for (int j = 0; j < i; j++) {
		printf("%d", arr[j]);
	}
}
int main() {
	scanf("%d", &N);
	sol();
	return 0;
}
