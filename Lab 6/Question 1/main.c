#include <stdio.h>
#include <stdlib.h>
#include "filing.c"

int main()
{
    char myName[100] = "lab6.txt";
    //readFromFile(myName);
    //writing(myName);
    int val = fileExists(myName);

    if (val)
    {
        printf("YES");

    } else if (val == 0)
    {
        printf("No");
    }
    return 0;
}
