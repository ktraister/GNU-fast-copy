#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void copy (char *args)
//void copy (char *read, const char *write)
{
     compute_prime_struct *actual_args = args;
     FILE *fp1, *fp2;
     char ch;
     //int pos;
     char *read, 
     char *write,     

     // insert code to call copy() here from single input
     read = concat("/jail/", filesList[i]);
     write = concat("/vol/qualifier/data/", filesList[i]);

 
     fp1 = fopen(read,"rb");
     printf("\nContents of read: %s ", read);
     printf("\nContents of fp1: %s ", fp1);
     if (fp1 == NULL)
     {
         printf("\nRead file cannot be opened");
         //return;
     }
     fp2 = fopen(write, "wb");
     printf("\nContents of fp2: %s ", fp2);
     printf("\nContents of write: %s", write);
     if (fp2 == NULL)
     {
         printf("/nWrite file cant be opened");
     }
     ch = fgetc(fp1);
     while (ch != EOF)
     {
         fputc(ch, fp2);
         ch = fgetc(fp1);
     }
     fclose(fp1);
     fclose(fp2);
 }

