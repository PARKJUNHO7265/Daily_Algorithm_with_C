#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
typedef struct {
	int len;
	char alpha[51];
} word;

int compare(const void* one, const void* two) {
	word A = *(word*)one;
	word B = *(word*)two;
	return A.len > B.len ? 1 : A.len < B.len ? -1 : strcmp(A.alpha, B.alpha);
}
int main() {
	scanf("%d ", &N);
	word arr[20001];
	char input[20001][51];
	for (int i = 0; i < N; i++) {
		gets(arr[i].alpha);
		arr[i].len = strlen(arr[i].alpha);
	}
	qsort(arr, N, sizeof(word), compare);
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		if (strcmp(arr[temp].alpha, arr[i].alpha)) {
			puts(arr[temp].alpha);
			temp = i;
		}
	}
	return 0;
}
