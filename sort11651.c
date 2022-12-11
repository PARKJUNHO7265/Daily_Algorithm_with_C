#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
typedef struct {
	int x;
	int y;
} point;

int compare(const void* one, const void* two) {
	point A = *(point*)one;
	point B = *(point*)two;
	if (A.y > B.y) return 1;
	else if (A.y < B.y) return -1;
	else {
		if (A.x > B.x) return 1;
		else if (A.x < B.x) return -1;
		else return 0;
	}
}
int main() {
	scanf("%d", &N);
	point p[100001];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	qsort(p, N, sizeof(point), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
	return 0;
}
