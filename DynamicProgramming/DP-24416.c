#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f[41];
int count = 0;
int count2 = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        count++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        count2++;
    }
    return f[n];
}

int main() {
    int n;
    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d", count , count2);
}
