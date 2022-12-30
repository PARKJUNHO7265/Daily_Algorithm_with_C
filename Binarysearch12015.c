#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int A[1000000];
int list[1000000];
int j = 0;
int lowerbound(int j, int A_num) {
	int low = 0;
	int high = j;
	while (low < high) {
		int mid = (low + high) / 2;
		if (list[mid] >= A_num) {
			high = mid;
		}
		else low = mid + 1;
	}
	return high;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	list[j] = A[0];
	for (int i = 1; i < N; i++) {
		if (list[j] < A[i]) {
			list[++j] = A[i];
		}
		else {
			int point = lowerbound(j, A[i]);
			list[point] = A[i];
		}
	}
	printf("%d", j + 1);
	return 0;
}
