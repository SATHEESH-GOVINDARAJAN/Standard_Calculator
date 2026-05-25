#include <stdio.h>
#include <math.h>

/* Engineering Constants */
#define PI 3.14159265358979323846

/* Function Prototypes */
void display_menu(void);
int get_user_selection(void);
void handle_addition(void);
void handle_subtraction(void);
void handle_multiplication(void);
void handle_division(void);
void handle_power(void); 
void handle_sqrt(void);
void handle_sine(void);    // New prototype
void handle_cosine(void);  // New prototype
void handle_tangent(void); // New prototype

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
            break;
        case 7: handle_sine(); 
            break;   // New route
        case 8: handle_cosine(); 
            break; // New route
        case 9: handle_tangent(); 
            break;// New route
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
    printf("6. Square Root \n"); 
    printf("7. Sine (sin x) \n");
    printf("8. Cosine (cos x) \n");
    printf("9. Tangent (tan x) \n");

    printf("0. Exit\n");
    printf("================================\n");
}

int get_user_selection(void) {
    int choice;
    printf("Select an operation [0-9]: ");  // range extended
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

void handle_sine(void) {
    double degrees, radians, result;
    printf("\n--- Sine Module (sin x) ---\n");
    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);
    
    // Converting degrees to radians for math.h
    radians = degrees * (PI / 180.0);
    result = sin(radians);
    
    printf("Result: %.6f\n", result);
}

void handle_cosine(void) {
    double degrees, radians, result;
    printf("\n--- Cosine Module (cos x) ---\n");
    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);
    
    radians = degrees * (PI / 180.0);
    result = cos(radians);
    
    printf("Result: %.6f\n", result);
}

void handle_tangent(void) {
    double degrees, radians, result;
    printf("\n--- Tangent Module (tan x) ---\n");
    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);
    
    /* Critical Mathematical Safeguard */
    // Tangent is undefined at 90, 270, etc. (odd multiples of 90)
    if (fmod(degrees - 90.0, 180.0) == 0.0) {
        printf("Error: Mathematical contradiction. Tangent of %.1f degrees is undefined (Infinity).\n", degrees);
        return;
    }
    
    radians = degrees * (PI / 180.0);
    result = tan(radians);
    
    printf("Result: %.6f\n", result);
}