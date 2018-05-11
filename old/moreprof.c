#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void main()
{
        int n=0, i=0;
        DIR *d;
        struct dirent *dir;
        d = opendir("/jail");
        FILE *fp1, *fp2, *logptr;
        char ch;
        int pos;
        char mystr[80];
        char dest[100];
        logptr = fopen("/var/log/LZlog","a");

        //Determine the number of files
        while((dir = readdir(d)) != NULL) {
            if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
                {

             } else {
                n++;
             }
        }
        rewinddir(d);

        char *filesList[n];

        //Put file names into the array
        while((dir = readdir(d)) != NULL) {
             if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
             {}
             else {

                  //filesList[i]= dir->d_name;
                   filesList[n] = (char*) malloc (strlen(dir->d_name)+1);
                   strncpy (filesList[n],dir->d_name, strlen(dir->d_name) );
                  // n++;
             }
        }

	printf(("%s \n", filesList[n]));
	rewinddir(d);
	return;
}
