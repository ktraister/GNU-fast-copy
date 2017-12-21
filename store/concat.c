#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


//int main(void)
//{
//	char shit;
//	shit = concat("Itfucking", "Works");
//	printf("%s \n", shit);
//	free(shit);
//}

int main(int x, const char **s1, const char **s2)
{
    s1="hot";
    s2="garbage";   
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
    printf(result);
}
