#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int M;
int arr[101];

void Input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}
void solution() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				if (max < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= M) {
					max = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	printf("%d", max);
}
int main() {
	Input();
	solution();
}
