/* Write a C program to read a sentence and replace lowercase characters with uppercase and vice
versa.*/

#include <stdio.h>
#include <ctype.h>

int main (){

    char sentence[] = "This is a Sentence.";

    for (int i = 0; i < sizeof(sentence); i++){             
        
        if (islower(sentence[i])){
            sentence[i] = toupper(sentence[i]);
        }

        else{
            sentence[i] = tolower(sentence[i]);
        }
    }

    printf("%s", sentence);

    return 0;
}