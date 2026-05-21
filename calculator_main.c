#include <stdio.h>

void display_menu(void);
int get_user_selection(void);

int main() {
    int selection;

    display_menu();
    selection = get_user_selection();

    printf("\nUser Selection: %d\n", selection);
    printf("Status: Base system initialized.\n");

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