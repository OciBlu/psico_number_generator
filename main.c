//PsicoNumGenerator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, max_value;

    // Seed the random number generator using the current time
    // This ensures a different sequence of numbers with each program execution.
    srand(time(NULL));

    // Get user input for rows, columns, and max value
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the maximum value for the random numbers: ");
    scanf("%d", &max_value);

    // Add a header for clarity
    printf("\nGenerated Numbers:\n");

    // Open a file for writing the number
    FILE *fp = fopen("number.txt", "w");
    if (fp == NULL) {
      printf("Error opening file!\n");
      return 1;
    }

    // Loop through each row
    for (int i = 0; i < rows; i++) {
        // Loop through each column
        for (int j = 0; j < cols; j++) {
            // Generate a random number between 0 and max_value-1
            int random_number = rand() % max_value;

            // Print the number with padding for consistent column width
            // For example, "%5d" pads integers to a width of 5 characters (Right-Justified).
            // For example, "%-5d" pads integers to a width of 5 characters (Left-Justified).
            //printf("%5d", random_number);

            // Write the number to the file
            fprintf(fp, "%-5d", random_number);

            // Close the file
            //fclose(fp);

        }
        // Print a new line to end the row.
        fprintf(fp,"%s", "\n");
        fprintf(fp,"%s", "\n");
    }
    //Close the file
    fclose(fp);
    printf("Generated number has been saved to number.txt\n");
    return 0;
}