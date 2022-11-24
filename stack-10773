#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int K;
int num;
int sum = 0;
int arr[100100];
int count = -1;

void Push(int A) {
	count++;
	arr[count] = A;
}
void Pop() {
	arr[count] = 0;
	count--;
}



int main() {
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		if (num == 0) {
			Pop();
		}
		else {
			Push(num);
		}
	}
	for (int i = 0; i <= count; i++) {
		sum += arr[i];
	}
	printf("%d", sum);
	return 0;
}
