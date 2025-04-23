#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function to calculate the area of a circle
float area_circle(float radius) {
    return M_PI * radius * radius;
}

// Function to calculate the circumference of a circle
float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

// Function to calculate the area of a rectangle
float area_rectangle(float length, float width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

// Function to check if sides form a valid triangle
int is_valid_triangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Function to calculate the area of a triangle using Heron's formula
float area_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate the perimeter of a triangle
float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

int main() {
    int choice;

    do {
        printf("\n--- Mensuration Calculator ---\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: {
                float radius;
                printf("Enter the radius of the circle: ");
                if (scanf("%f", &radius) == 1 && radius >= 0) {
                    printf("Area: %.2f\n", area_circle(radius));
                    printf("Circumference: %.2f\n", circumference_circle(radius));
                } else {
                    printf("Invalid radius. Please enter a non-negative number.\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 2: {
                float length, width;
                printf("Enter the length of the rectangle: ");
                if (scanf("%f", &length) == 1 && length >= 0) {
                    printf("Enter the width of the rectangle: ");
                    if (scanf("%f", &width) == 1 && width >= 0) {
                        printf("Area: %.2f\n", area_rectangle(length, width));
                        printf("Perimeter: %.2f\n", perimeter_rectangle(length, width));
                    } else {
                        printf("Invalid width. Please enter a non-negative number.\n");
                        while (getchar() != '\n');
                    }
                } else {
                    printf("Invalid length. Please enter a non-negative number.\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 3: {
                float a, b, c;
                printf("Enter the lengths of the three sides of the triangle:\n");
                printf("Side 1: ");
                if (scanf("%f", &a) == 1 && a > 0) {
                    printf("Side 2: ");
                    if (scanf("%f", &b) == 1 && b > 0) {
                        printf("Side 3: ");
                        if (scanf("%f", &c) == 1 && c > 0) {
                            if (is_valid_triangle(a, b, c)) {
                                printf("Area: %.2f\n", area_triangle(a, b, c));
                                printf("Perimeter: %.2f\n", perimeter_triangle(a, b, c));
                            } else {
                                printf("Invalid triangle. The sum of any two sides must be greater than the third.\n");
                            }
                        } else {
                            printf("Invalid input for side 3.\n");
                            while (getchar() != '\n');
                        }
                    } else {
                        printf("Invalid input for side 2.\n");
                        while (getchar() != '\n');
                    }
                } else {
                    printf("Invalid input for side 1.\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 4:
                printf("Exiting the calculator.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                while (getchar() != '\n');
        }

    } while (choice != 4);

    return 0;
}
