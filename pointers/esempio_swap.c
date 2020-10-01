#include <stdio.h>

int main() {
    int i = 0;
    int j = 5;
    swap(i, j);
    printf("i vale %d", i);
    printf("j vale %d", j);
    return 0;
}

void swap(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}