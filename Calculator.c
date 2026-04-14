Task 1 : Calculator Program

#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            printf("Addition = %d", a + b);
            break;

        case '-':
            printf("Subtraction = %d", a - b);
            break;

        case '*':
            printf("Multiplication = %d", a * b);
            break;

        case '/':
            if(b != 0)
                printf("Division = %d", a / b);
            else
                printf("Division by zero not allowed");
            break;

        default:
            printf("Invalid operation");
    }

    return 0;
}