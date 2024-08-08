/*
    This program provides a simple arithmetic quiz with random numbers.
    The user selects a difficulty level (single, double, or triple digit addition),
    and the program generates random numbers within the selected range. 
    The user is prompted to enter the sum of the numbers, and points are awarded 
    for correct answers and deducted for incorrect answers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Colors
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// Function to handle calculations and user interaction
void calculate(int max) {
    // Variables
    int number_of_calculations;
    int ans;
    int points = 0;

    srand(time(NULL));

    printf("Enter number of times to play: ");
    scanf("%d", &number_of_calculations);  // Use & to store input in variable

    for(int i = 1; i <= number_of_calculations; i++) {
        int random_number1 = rand() % (max * 2 + 1) - max;  // Range from -max to max
        int random_number2 = rand() % (max * 2 + 1) - max;  // Range from -max to max
        int sum = random_number1 + random_number2;

        printf("\n1st number: %d\n2nd Number: %d\nEnter Answer: ", random_number1, random_number2);
        scanf("%d", &ans);  // Use & to store input in variable

        if(ans == sum) {
            points++;
            printf(GREEN "\n\nCorrect Answer!" RESET);
        } else {
            points--;
            printf(RED "\nWrong Answer!" RESET);
        }
        printf("\nPoints: %d\n", points);  // Move points output outside of color codes
    }
}

// Main function to handle user input and call the calculate function
int main() {
    // Variable Declaration
    char ch;

    printf("Enter your level!\n1. Single Digit Addition\n2. Double Digit Addition\n3. Triple Digit Addition\nEnter: ");
    scanf(" %c", &ch);  // Use & to store input in variable and space to ignore whitespace

    if(ch == '1') {
        calculate(9);
    } else if(ch == '2') {
        calculate(99);
    } else if(ch == '3') {
        calculate(999);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
