#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
typedef struct {
	int age;
	int turn;
	char name[101];
} person;

int compare(const void* one, const void* two) {
	person A = *(person*)one;
	person B = *(person*)two;
	return A.age > B.age ? 1 : A.age < B.age ? -1 : A.turn > B.turn ? 1 : -1;
}
int main() {
	scanf("%d", &N);
	int age[100001];
	char name[101];
	person arr[100001];
	for (int i = 0; i < N; i++) {
		scanf("%d %s",&age[i], &arr[i].name);
		arr[i].turn = i;
		arr[i].age = age[i];
	}
	qsort(arr, N, sizeof(person), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}
	return 0;
}
