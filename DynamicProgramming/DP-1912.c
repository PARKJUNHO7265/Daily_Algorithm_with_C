#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int max = -10000;
int arr[100001] = { 0 };
int sum = 0;
void sol(int n) {
	for (int i = 0; i <= n-1; i++) {
		if (arr[i] > 0) {
			if (sum < 0) { //합 음수, arr양수
				sum = 0;
				sum += arr[i];
			}
			else { //합 양수, arr 양수
				sum += arr[i];
			}
			if (max < sum) { //max 값 저장
				max = sum;
			}
		}
		else {
			if (sum <= 0) { //합 음수, arr 음수
				if (max < arr[i]) {
					max = arr[i];
				}
			}
			else { //합 양수, arr 음수
				sum += arr[i];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sol(n);
	printf("%d", max);
	return 0;
}
