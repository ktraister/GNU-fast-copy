 /* read files in /jail directory 
 *things I still need:
 *threading (10 threads to start, 9 moving 1 logging)
 *#program will run on crontab, move all files per one snap of dir
 *program needs to detect running instances and stop if detected
 *program need to NOT open files that are already open for writing
 *iterate thru proc to do this^
 */

//create a function to create filesList and divide load among concurrent threads
//function should continue to iterate untill there are no files left ;)  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

//enum { MAXLINES = 30 };

char* concat( const char *s1, const char *s2);
void copy (const char *args);
//void copy(char *read, const char *write);
//void *worker1(void *vargp);
//void *worker2(void *vargp);

int main(void)
{
int n=0, i=0;
DIR *d;
struct dirent *dir;
int elements;
d = opendir("/jail");
pthread_t tid;

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
printf("Contents of fileslist: %s", filesList[i]);
//printf("THIS STATEMENT IS I: %s", i);
//printf("THIS STATEMENT IS N: %s", n);
//call function to operate on filenames in copy() in order to pass 1 var to copy!
//call copy function in multi-threads

while(readdir(d) != 0){
for (i=0; i<n; i++)
        {
        //debugging statement
        printf("%s\n", filesList[i]);
        
        //char *out;
        //char *in;
        
        //out = concat("/vol/qualifier/data/", filesList[i]);
        //in = concat("/jail/", filesList[i]);
        
        //more debugging statements
        //printf("concat output: %s \n", out );
        printf("filelist output: %s \n", filesList[i] );
        printf("starting threads!");
        
        //following code sends threads to copy files
        pthread_create(&tid, NULL, copy, filesList[i]);
        i++;
        pthread_create(&tid, NULL, copy, filesList[i]);
        i++;
        pthread_create(&tid, NULL, copy, filesList[i]);
        i++;
        pthread_create(&tid, NULL, copy, filesList[i]);
        i++;
        //pthread_create(&tid, NULL, copy, filesList[i]);
        //i++;
        pthread_create(&tid, NULL, copy, filesList[i]);
        pthread_join(tid, NULL);
        printf("\nafter threads!\n");
        //copy( in, out );
        }
return 0;
}



//printf("starting threads!\n");
//pthread_create(&tid, NULL, worker1, NULL);
//pthread_create(&tid, NULL, copy, filesList[i]);
//pthread_join(tid, NULL);
//printf("after threads!\n");
//exit(0);
}


/*****************************function to copy files********************************************/

void copy (const char *args)
//void copy (char *read, const char *write)
{
     //compute_prime_struct *actual_args = args;
     FILE *fp1, *fp2;
     char ch;
     char *read;
     char *write;     
 
     read = concat("/jail/", args);
     write = concat("/vol/qualifier/data/", args);


     //printf("\nContents of fp1: %s ", read);    
     //printf("\nContents of 
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


/******************************function to concatenate filenames*********************************/

char* concat( const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
    return result;
}


/**************************************function to create array************************************************************/
//reintegrated this into main function for simplicity's sake
/*
void *array_maker(char *filesList[n])
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

//char *filesList[n];

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
printf("Contents of fileslist: %s", filesList[i]);
}

*/
