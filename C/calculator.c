#include <stdio.h>
#include <stdlib.h>

// Function prototypes for calculator operations
void add();
void subtract();
void multiply();
void divide();
void modulus();
void power();
void exitCalculator();

// Function for printing the menu
void printMenu() {
    printf("\n*** Calculator Menu ***\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
}

// Main calculator function
int main() {
    int choice;

    while (1) {
        // Display the menu
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: power(); break;
            case 7: exitCalculator(); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add two numbers
void add() {
    double num1, num2;
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 + num2);
}

// Function to subtract two numbers
void subtract() {
    double num1, num2;
    printf("Enter two numbers to subtract (num1 - num2): ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 - num2);
}

// Function to multiply two numbers
void multiply() {
    double num1, num2;
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 * num2);
}

// Function to divide two numbers
void divide() {
    double num1, num2;
    printf("Enter two numbers to divide (num1 / num2): ");
    scanf("%lf %lf", &num1, &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2lf\n", num1 / num2);
    }
}

// Function to find modulus of two integers
void modulus() {
    int num1, num2;
    printf("Enter two integers to find modulus (num1 %% num2): ");
    scanf("%d %d", &num1, &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %d\n", num1 % num2);
    }
}

// Function to calculate the power of a number
void power() {
    double base, exp;
    printf("Enter base and exponent (base^exp): ");
    scanf("%lf %lf", &base, &exp);
    printf("Result: %.2lf\n", pow(base, exp));
}

// Function to exit the calculator
void exitCalculator() {
    printf("Exiting the calculator. Goodbye!\n");
    exit(0);
}
