#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long N, M;
long long tree[1000001];
long long cut(long long mid) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (mid < tree[i]) {
			sum += tree[i] - mid;
		}
	}
	return sum;
}
int compare(const void* one, const void* two) {
	long long A = *(long long*)one;
	long long B = *(long long*)two;
	if (A > B) return 1;
	else if (A < B) return -1;
	else return 0;
}
long long sol() {
	long long high = tree[N - 1] - 1;
	long long low = 0;
	long long mid;
	while (low < high) {
		mid = (high + low) / 2;
		long long sum = cut(mid);
		if (sum >= M && cut(mid + 1) < M) {
			break;
		}
		else if (sum > M) {
			low = mid + 1;
		}
		else if (sum < M) {
			high = mid - 1;
		}
	}
	return (high + low) / 2;
}
int main() {
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &tree[i]);
	}
	qsort(tree, N, sizeof(long long), compare);
	printf("%d",sol());
	return 0;
}
