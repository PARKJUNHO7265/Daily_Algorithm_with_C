#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
long long k;
long long count(long long Mid) {
	long long mid = Mid;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (mid / i < N) {
			sum += mid / i;
		}
		else {
			sum += N;
		}
	}
	return sum;
}
long long sol() {
	long long min = 1;
	long long max = k;
	long long mid = (min + max) / 2;
	long long result;
	while (max >= min) {
		mid = (min + max) / 2;
		long long countnum = count(mid);
		if (countnum >= k) {
			result = mid;
			max = mid - 1;
		}
		else if (countnum < k) {
			min = mid + 1;
		}
	}
	return result;
}
int main() {
	scanf("%d", &N);
	scanf("%lld", &k);
	printf("%lld", sol());
	return 0;
}
