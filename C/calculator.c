#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Displaying the menu
    printf("Select an operation:\n");
    printf(" + : Addition\n");
    printf(" - : Subtraction\n");
    printf(" * : Multiplication\n");
    printf(" / : Division\n");
    printf("Enter operator: ");
    scanf(" %c", &operator);  // Read the operator

    // Reading the two operands
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Performing the operation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            // Checking for division by zero
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}

