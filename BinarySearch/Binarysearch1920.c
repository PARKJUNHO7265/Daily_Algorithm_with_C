#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int arr[100001];
int num;
int compare(const void* one, const void* two) {
	int A = *(int*)one;
	int B = *(int*)two;
	if (A > B) return 1;
	else if (A < B) return -1;
	else return 0;
}
int binary_search(int data[], int n, int key) {
	int low, high;
	int mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {
			return 1;
		}
		else if (key < data[mid]) {
			high = mid - 1;
		}
		else if (key > data[mid]) {
			low = mid + 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), compare);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		printf("%d\n",binary_search(arr, N, num));
	}
	return 0;
}
