#include <stdio.h>
#include <math.h>

/* Function Prototypes */
void display_menu(void);
int get_user_selection(void);
void handle_addition(void);
void handle_subtraction(void);
void handle_multiplication(void);
void handle_division(void);
void handle_power(void); 
void handle_sqrt(void); // New square root prototype

int main() {
    int selection;
/* This creates an infinite loop, exactly like an operating system or micro-controller loop */
    while (1) {
        display_menu();
        selection = get_user_selection();



    switch (selection) {
        case 1:
            handle_addition();
            break;
        case 2:
            handle_subtraction();
            break;
        case 3:
            handle_multiplication();
            break;
        case 4:
            handle_division();
            break;
        case 5: handle_power();
            break; 
        case 6: handle_sqrt(); 
            break; // New route for square root
        case 0:
            printf("Exiting application cleanly.\n");
            break;
        default:
            printf("Error: Operation invalid or not yet implemented.\n");
            break;
    }

      // If user selects 0, break the loop and exit cleanly
        if (selection == 0) {
            printf("\nExiting application cleanly. Goodbye!\n");
            break; 
        }
    }

    return 0;
}

void display_menu(void) {
    printf("================================\n");
    printf("      STANDARD CALCULATOR       \n");
    printf("================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Square Root \n"); // Menu option updated
    printf("0. Exit\n");
    printf("================================\n");
}

int get_user_selection(void) {
    int choice;
    printf("Select an operation [0-6]: ");  // range extended
    if (scanf("%d", &choice) != 1) {
        printf("Error: Invalid input detected.\n");
        return -1; 
    }
    return choice;
}

void handle_addition(void) {
    float num1, num2, result;
    printf("\n--- Addition Module ---\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 + num2;
    printf("Result: %.2f\n", result);
}

void handle_subtraction(void) {
    float num1, num2, result;
    printf("\n--- Subtraction Module ---\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 - num2;
    printf("Result: %.2f\n", result);
}

void handle_multiplication(void) {
    float num1, num2, result;
    printf("\n--- Multiplication Module ---\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    result = num1 * num2;
    printf("Result: %.2f\n", result);
}

void handle_division(void) {
   double num1, num2, result; // Upgraded from float to double for scientific accuracy
    printf("\n--- High-Precision Division Module ---\n");
    printf("Enter numerator: ");
    scanf("%lf", &num1); // %lf is the format specifier for double
    printf("Enter denominator: ");
    scanf("%lf", &num2);
    
    if (num2 == 0) {
        printf("Error: Mathematical contradiction. Division by zero is undefined.\n");
        return;
    }
    
    result = num1 / num2;
    printf("Result: %.6f\n", result);
}
void handle_power(void) {
    double base, exponent, result;
    printf("\n--- Power Module (x^y) ---\n");
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (y): ");
    scanf("%lf", &exponent);
    
    // Using the standard math.h function
    result = pow(base, exponent);
    printf("Result: %.4f\n", result);
}

void handle_sqrt(void) {
    double num, result;
    printf("\n--- Square Root Module ---\n");
    printf("Enter number: ");
    scanf("%lf", &num);
    
    /* Critical Hardware Safeguard: Intercepting domain errors */
    if (num < 0) {
        printf("Error: Domain violation. Square root of a negative number yields imaginary values.\n");
        return; // Exit the function safely without computing
    }
    
    result = sqrt(num);
    printf("Result: %.6f\n", result); // Maintained our high-precision 6-digit standard
}