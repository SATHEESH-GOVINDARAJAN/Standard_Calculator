#include <stdio.h>

/* Function Prototypes */
void display_menu(void);
int get_user_selection(void);
void handle_addition(void);
void handle_subtraction(void);

int main() {
    int selection;

    display_menu();
    selection = get_user_selection();

    // Structural routing based on user input
    switch (selection) {
        case 1:
            handle_addition();
            break;
        case 2:
            handle_subtraction();
            break;
        case 0:
            printf("Exiting application cleanly.\n");
            break;
        default:
            printf("Error: Operation invalid or not yet implemented.\n");
            break;
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
    printf("0. Exit\n");
    printf("================================\n");
}

int get_user_selection(void) {
    int choice;
    printf("Select an operation [0-4]: ");
    if (scanf("%d", &choice) != 1) {
        printf("Error: Invalid input detected.\n");
        return -1; 
    }
    return choice;
}

/**
 * Math Logic Modules
 * Keeping operations isolated inside individual functions
 */
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