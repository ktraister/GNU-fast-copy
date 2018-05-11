/*
 * I need to write a program to move files from Kani2 chroot to /vol/qualifier
 *
 *I want to use multi-threaded compiled program, leaning towards Java or C
 * C Program to Copy a File into Another File
 * Need to add multi-threaded support and to look for files in directory
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/*
*  read_dir function reads directory and creates array filesList for use with main(move) function
*/

int n=0, i=0;

void read_dir()
{
        //int n=0, i=0;
        DIR *d;
        struct dirent *dir;
        d = opendir("/jail");
        //char *filesList[n];

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
                  filesList[i] = (char*) malloc (strlen(dir->d_name)+1);
                  strncpy (filesList[i],dir->d_name, strlen(dir->d_name) );
                  i++;
             }
        }
        rewinddir(d);

        //statement to print the filesList array for testing
        //for(i=0; i<=n; i++)
        //     printf("%s%s \n", "/tmp/", filesList[i]);
        //return;
}

/*
 * Just to get this working quickly, write to file list of files, read list in copy function
 */


//This is main function
//files to copy are declared, need to declare files to copy
void main(int n, char *filesList[] )
{
   //File line was for original function, now take input from array[slice] 
    FILE *fp1, *fp2, *logptr;
    char ch;
    int pos;
    char mystr[80];
    char dest[100];
    logptr = fopen("/var/log/LZlog","a");
 //   char filesList[n]; 
    //read_dir();
    printf("I got this far!");
    for(i=0; i<sizeof(filesList[n]); i++) 
    {
 
    	if ((fp1 = fopen(filesList[n],"r")) == NULL)    
    	{    
        	fprintf(logptr,"\nFile cannot be opened");
        	return;
    	}
	strcpy(mystr, "/vol/qualifier/data/") ;
        strcat(mystr, filesList[n]);
        //dest = mystr;	
    	printf (mystr);
	fp2 = fopen(mystr, "w");  
    	fseek(fp1, 0L, SEEK_END); // file pointer at end of file
    	pos = ftell(fp1);
    	fseek(fp1, 0L, SEEK_SET); // file pointer set at start
    	while (pos--)
    	{
        	ch = fgetc(fp1);  // copying file character by character
        	fputc(ch, fp2);
    	}    
    	fclose(logptr);
    	fclose(fp1);
    	fclose(fp2);
    }
}
