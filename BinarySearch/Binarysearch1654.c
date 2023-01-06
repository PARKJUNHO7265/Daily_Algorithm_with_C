#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, K;
long long arr[1000001];

int compare(const void* one, const void* two) {
	long long A = *(long long*)one;
	long long B = *(long long*)two;
	if (A > B) return 1;
	else if (A < B) return -1;
	else return 0;
}
long long sol() {
	long long low = 1;
	long long high = arr[N - 1];
	long long mid;
	while (low <= high) {
		long long count = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			count += arr[i] / mid;
		}
		if (count >= K) low = mid + 1;
		else if (count < K) high = mid - 1;
	}
	return (low + high) / 2;
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	qsort(arr, N, sizeof(long long), compare);
	printf("%lld", sol());
	return 0;
}
