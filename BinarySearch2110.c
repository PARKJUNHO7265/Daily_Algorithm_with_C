#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, C;
long long home[200001];
int compare(const void* one, const void* two) {
	long long A = *(long long*)one;
	long long B = *(long long*)two;
	if (A > B) return 1;
	else if (A < B) return -1;
	else return 0;
}
long long findMin() {
	long long min = home[1] - home[0];
	for (int i = 2; i < N; i++) {
		if (min > home[i] - home[i - 1]) {
			min = home[i] - home[i - 1];
		}
	}
	return min;
}
long long sol(long long Min) {
	long long min = Min;
	long long max = home[N - 1] - home[0];
	long long mid = (max + min) / 2;
	long long maxDist;
	while (max >= min) {
		int count = 1;
		mid = (max + min) / 2;
		int start = home[0];
		for (int i = 1; i < N; i++) {
			int end = home[i];
			if (end - start >= mid) {
				count++;
				start = end;
			}
		}
		if (count >= C) {
			maxDist = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	return maxDist;
}
int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &home[i]);
	}
	qsort(home, N, sizeof(long long), compare);
	long long min = findMin();
	printf("%d", sol(min));
	return 0;
}
