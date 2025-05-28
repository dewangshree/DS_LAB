#include <stdio.h>

// Function to generate Fibonacci series recursively
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print disk movements in Tower of Hanoi problem recursively
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int choice, n;
    
    printf("Enter your choice:\n");
    printf("1. Fibonacci Series\n");
    printf("2. Tower of Hanoi\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the number of terms for Fibonacci Series: ");
            scanf("%d", &n);
            printf("Fibonacci Series: ");
            for (int i = 0; i < n; ++i)
                printf("%d ", fibonacci(i));
            printf("\n");
            break;
        case 2:
            printf("Enter the number of disks: ");
            scanf("%d", &n);
            printf("Tower of Hanoi Moves:\n");
            towerOfHanoi(n, 'A', 'C', 'B');
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
