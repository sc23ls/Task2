#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


FILE *open_file(char fileName[], char mode[]) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        printf("Error: could not open file");
        exit(1);
    }
    return file;
}

// Complete the main function
int main() {
    FILE *file;
    char *filename;
    char *option;
    FITNESS_DATA data[128];
    printf("Choose from the following options: \n
    A: Specify the filename to be imported \n
    B: Display the total number of records in the file \n
    C: Find the date and time of the timeslot with the fewest steps \n
    D: Find the data and time of the timeslot with the largest number of steps \n
    E: Find the mean step count of all the records in the file \n
    F: Find the longest continuous period where the step count is above 500 steps \n
    Q: Exit \n");
    scanf("%s", option);
    switch(option){
        case 'A': 
            printf("Input filename:");
            scanf("%s", filename);
            file=open_file(filename, "r");
            
        break;

        case 'B':
        break;

        case 'C':
        break;

        case 'D':
        break;

        case 'E':
        break;

        case 'F':
        break;

        case 'Q':
        break;

    }
}









