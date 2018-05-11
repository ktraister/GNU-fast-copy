#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void concat(char *s1, char *s2);


int main ()
{
    concat("what", "thefuck");
    return 0;
}

void concat(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t lent = len1 + len2 + 1;

    char* result = malloc(len1+len2+1);//+1 for the zero-terminator
    //char* result = calloc(1, lent);
    strcpy(result, s1);
    strcat(result, s2);
    int q = len1+len2+1;
    result[q] = 0;
    printf("\nMy result was: %s\n", result);
    free(result);
    result = '\0';
    return;
}
