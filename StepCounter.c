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
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

FILE *open_file(char fileName[], char mode[])
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error: could not open file\n");
        exit(1);
    }
    printf("File successfully loaded.\n");
    return file;
}

FITNESS_DATA minStep(FITNESS_DATA fitnessData[], int arrayLen)
{
    FITNESS_DATA min;
    min.steps = 100000;
    int a;
    for (a = 0; a < arrayLen; a++)
    {
        if (fitnessData[a].steps < min.steps)
        {
            min = fitnessData[a];
        }
    }
    return min;
}

FITNESS_DATA maxStep(FITNESS_DATA fitnessData[], int arrayLen)
{
    FITNESS_DATA max;
    max.steps = -1;
    int a;
    for (a = 0; a < arrayLen; a++)
    {
        if (fitnessData[a].steps > max.steps)
        {
            max = fitnessData[a];
        }
    }
    return max;
}

// Complete the main function
int main()
{
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int counter = 0;
    float mean = 0;

    int i = 0;
    FILE *file;
    char filename[buffer_size];
    char option = ' ';
    FITNESS_DATA data[128];
    while (1)
    {
        printf("Choose from the following options:\n A: Specify the filename to be imported\n B: Display the total number of records in the file\n C: Find the date and time of the timeslot with the fewest steps\n D: Find the data and time of the timeslot with the largest number of steps\n E: Find the mean step count of all the records in the file\n F: Find the longest continuous period where the step count is above 500 steps\n Q: Exit\n Enter choice: ");
        scanf(" %c", &option);
        switch (option)
        {
        case 'A':
            printf("Input filename:");
            scanf("%s", filename);
            file = open_file(filename, "r");

            char *delimeter = ", ";
            while (fgets(line_buffer, buffer_size, file) != NULL)
            {
                char *stepsTemp = (char *)malloc(6);
                char *dateTemp = (char *)malloc(11);
                char *timeTemp = (char *)malloc(6);
                tokeniseRecord(line_buffer, delimeter, dateTemp, timeTemp, stepsTemp);

                strcpy(data[i].date, dateTemp);
                strcpy(data[i].time, timeTemp);
                data[i].steps = atoi(stepsTemp);

                i++;
            }

            break;
        case 'B':
            printf("Total records: %d\n", i);
            break;
        case 'C':;
            FITNESS_DATA minimumSteps = minStep(data, i);
            printf("Fewest steps: %s %s\n", minimumSteps.date, minimumSteps.time);
            break;
        case 'D':;
            FITNESS_DATA maximumSteps = maxStep(data, i);
            printf("Largest steps: %s %s\n", maximumSteps.date, maximumSteps.time);
            break;
        case 'E':
            file = open_file(filename, "r");
            counter = 0;
            while (fgets(line_buffer, buffer_size, file))
            {
                mean += data[counter].steps;
                counter++;
            }
            mean /= counter;
            int meanInt = (int)mean;
            mean -= meanInt;
            if (mean > 0.5)
            {
                meanInt++;
            }
            printf("Mean step count: %d\n", meanInt);
            break;
        case 'F':
            break;
        case 'Q':
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.");
        }
    }
    fclose(file);
}