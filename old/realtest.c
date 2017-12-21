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
	      	  i++;
	     }
        }
        rewinddir(d);

        //FILE *f = fopen("testfile", "wb");
        //fwrite(testfile, sizeof(char), sizeof(testfile), f);
        //fclose(f);
	
	//statement to print the filesList array for testing
	//for(i=0; i<=n; i++)
	//{
	//	printf("%s%s \n", "/tmp/", filesList[i]);
	//}
	//	//return;


//This is main function
//files to copy are declared, need to declare files to copy
   //File line was for original function, now take input from array[slice]
        printf ("test print statement");
	for(i=0; i<sizeof(filesList[n]); i++)
	{

              if ((fp1 = fopen(filesList[n],"r")) == NULL)
              {
                    fprintf(logptr,"\nFile cannot be opened");
              }
              else
              {
		    strcpy(mystr, "/vol/qualifier/data/") ;
        	    strcat(mystr, filesList[n]);
                    fp2 = fopen(mystr, "w");
                    fseek(fp1, 0L, SEEK_END); // file pointer at end of file
                    pos = ftell(fp1);
                    fseek(fp1, 0L, SEEK_SET); // file pointer set at start
         
	 	    while (pos--)
                    {
                             ch = fgetc(fp1);  // copying file character by character
                             fputc(ch, fp2);
                    }
	      }    
        fclose(logptr);
        fclose(fp1);
        fclose(fp2);
        return;
    }
}
