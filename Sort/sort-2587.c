#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[5];
int temp;
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	printf("%d\n", (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5);
	printf("%d\n", arr[2]);
}
