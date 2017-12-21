
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void main( int arg) //char *filesList[])
{
int n=0, i=0;
DIR *d;
struct dirent *dir;
int elements;
d = opendir("/jail");

//Determine the number of files
while((dir = readdir(d)) != NULL) {
    if ( (n < 30) && (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) )
    {

    }
    if (n >= 30)
    {
        exit;
    }
    else
    {
        n++;
    }
}
rewinddir(d);

char *filesList[n];

//Put file names into the array
while(((dir = readdir(d)) != NULL) && (i<30)) {
    if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
    {}
    else {
        filesList[i]= dir->d_name;
        i++;
    }
}
rewinddir(d);
printf("Contents of fileslist: %s\n", filesList[i] );
}
