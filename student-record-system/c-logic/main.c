#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: <roll> <name> <marks>\n");
        return 1;
    }

    // Print arguments to ensure they are received correctly
    printf("Received data: Roll: %s, Name: %s, Marks: %s\n", argv[1], argv[2], argv[3]);

    // Open the file to append
    FILE *fp = fopen("students.txt", "a");  
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write to the file in a readable format
    fprintf(fp, "Roll: %s, Name: %s, Marks: %s\n", argv[1], argv[2], argv[3]);

    fclose(fp);

    printf("Student added: Roll: %s, Name: %s, Marks: %s\n", argv[1], argv[2], argv[3]);
    return 0;
}
