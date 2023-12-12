#include "file.h"

void readFromFile(char* fileName)
{
    FILE* fileptr;
    fileptr = fopen(fileName, "r");
    char myString[1000];
    if (fileptr == NULL)
    {
        return -1;
    }
    while(fgets(myString, 1000, fileptr))
    {
        printf("%s", myString);
    }
    fclose(fileptr);
}
void writing(char* name)
{
    FILE* fileptr;
    fileptr = fopen(name, "w");
    char myString[1000];
    printf("Enter a string: ");
    fgets(myString, sizeof(myString), stdin);
    fprintf(fileptr, "%s", myString);
    fclose(fileptr);
    printf("Successfully Write!");
}

int fileExists(char* fileName)
{
    FILE* fileptr;
    fileptr = fopen(fileName, "r");
    if (fileptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
