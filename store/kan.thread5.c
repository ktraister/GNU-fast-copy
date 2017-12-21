 /* read files in /jail directory 
 *things I still need:
 *#program will run on crontab, move all files per one snap of 30 files in /jail
 *program needs to detect running instances and stop if detected
 *verbosely log errors in log file
 *program need to NOT move files that are already open for writing
 *iterate thru proc to do this^
 */


//ARRAY HAS TO STAY A FIXED SIZE; iterate thru defined array multiple times 
//move main() to new funct; use main() to call new_funct() as long as files exist in /jail 
//^ x=numfiles(); while (x !=0){main(); x=numfiles()}
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
void copy(const char *args);
int numfiles(void);
int fsize(char* argv);
//void (void)
//void copy(char *read, const char *write);





/*************************************Heavy lifting function to be called by main**********************************************************/



int main(void)
{
//int n is for array length, x is for # of files
int n=30, x=0, i=0;
DIR *d;
struct dirent *dir;
int elements;
char *filesList[n];
d = opendir("/jail");
pthread_t tid;

x = numfiles();
//printf("\n output of numfiles: %d", x); 

//while(x != 0){
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
//printf("Contents of fileslist: %s", filesList[i]);
//printf("THIS STATEMENT IS I: %s", i);
//printf("THIS STATEMENT IS N: %s", n);
//call function to operate on filenames in copy() in order to pass 1 var to copy!
//call copy function in multi-threads

//while(x != 0){
for (i=0; i<n; i++)
        {
        //debugging statement
        //printf("%s\n", filesList[i]);
        
        //char *out;
        //char *in;
        
        //out = concat("/vol/qualifier/data/", filesList[i]);
        //in = concat("/jail/", filesList[i]);
        
        //more debugging statements
        //printf("concat output: %s \n", out );
        //printf("filelist output: %s \n", filesList[i] );
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
        //pthread_create(&tid, NULL, copy, filesList[i]);
        pthread_join(tid, NULL);
        //x = numfiles();
        printf("\nafter threads!\n");
        //copy( in, out );
        }
//call function to check number of files in dir and set x= to it
//x = numfiles();
//printf("my x value is %d", x);
//}
//printf("my x value is %d", x);
return 0;
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
     int size1; 
     int size2;

     read = concat("/jail/", args);
     write = concat("/vol/qualifier/data/", args);

     size1 = fsize(read);
     printf("\nSize1: %d", size1);
     //printf("\nContents of fp1: %s ", read);    
     //printf("\nContents of 
     fp1 = fopen(read,"rb"); 
     //printf("\nContents of read: %s ", read);
     //printf("\nContents of fp1: %s ", fp1);
     if (fp1 == NULL)
     {
         printf("\nRead file cannot be opened");
         //return;
     }
     fp2 = fopen(write, "wb");
     //printf("\nContents of fp2: %s ", fp2);
     //printf("\nContents of write: %s", write);
     //size2 = fsize(read);
     //printf("\nSize2: %d", size2);
     if (fp2 == NULL)
     {
         printf("/nWrite file cant be opened");
     }
     
     size2 = fsize(read);
     printf("\nSize2: %d", size2);
     if (size1 != size2)
     {
	 printf("/nFilesize changed while reading!");
         exit(0);        
     }
     ch = fgetc(fp1);
     while (ch != EOF)
     {
         fputc(ch, fp2);
         ch = fgetc(fp1);
     }
     fclose(fp1);
     fclose(fp2);
//Add logic to remove files once they have been copied
     remove(read);
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


/*******************************function to determine # of files in /jail*****************************************************************/
int numfiles(void)
{

int x=0;
DIR *d;
struct dirent *dir;
d = opendir("/jail");
//Determine the number of files
while((dir = readdir(d)) != NULL) {
    if ( (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) )
    {
    }
//    if (n >= 30)
//    {
//        exit;
//    }
    else
    {
        x++;
    }
//    printf("my x value is %d", x);
}
rewinddir(d);
x = x - 1;
//debugging statement
//printf("my x value is %d", x);
return x;
}



/***************************function to find size of files**************************************/
int fsize(char* argv)
{
    FILE *fp;
    char ch;
    int size = 0;

    fp = fopen(argv, "rb");
    if (fp == NULL)
        printf("\nFsize unable to open file ");
    //else
    //    printf("\nFile opened ");
    fseek(fp, 0, 2);    /* file pointer at the end of file */
    size = ftell(fp);   /* take a position of file pointer un size variable */
    //printf("\nThe size of given file is : %d\n", size);
    fclose(fp);
    return size;
}
