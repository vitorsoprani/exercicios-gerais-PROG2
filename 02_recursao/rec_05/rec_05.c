#include <stdio.h>

int fatorial(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fatorial(n));
    return 0;
}

int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}