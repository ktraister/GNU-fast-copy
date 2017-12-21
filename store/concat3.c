#include <stdlib.h>
#include <string.h>


void concat(char *s1, char *s2);

int main ()
{
    concat("what", "thefuck");
    return 0;
}

void concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    printf("\nMy result was: %s\n", result);
}
