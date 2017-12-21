 /* read files in /jail directory 
 *things I still need:
 *threading (10 threads to start, 9 moving 1 logging)
 *#program will run on crontab, move all files per one snap of dir
 *program needs to detect running instances and stop if detected
 *program need to NOT open files that are already open for writing
 *iterate thru proc to do this^
 */

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
void copy(char *read, const char *write);
void *worker1(void *vargp);
//int worker2(void);



int main(void)
{
pthread_t tid;
//pthread_t tid2;
printf("starting threads!\n");
pthread_create(&tid, NULL, worker1, NULL);
pthread_join(tid, NULL);
printf("after thread\n");
//pthread_create(&tid2, NULL, worker2, NULL);
exit(0);
}

/*********************************************worker 1 for thread1************************************************************************/

void *worker1(void *vargp)
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

for(i=0; i<n; i++)
	{
    	//printf("%s\n", filesList[i]);
	char *s;
        char *f;
        s = concat("/vol/qualifier/data/", filesList[i]);
	f = concat("/jail/", filesList[i]);
        printf("concat output: %s \n", s ); 
	printf("filelist output: %s \n", filesList[i] );
	copy( f, s );
	}
return NULL;
}


/********************************************worker2 for thread2*****************************************************************/
/*

int worker2(void)
{
int n=0, i=0;
DIR *d;
struct dirent *dir;
int elements;
d = opendir("/jail");

//Determine the number of files
while((dir = readdir(d)) != NULL) {
    if ( (30 < n < 60) && (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) )
    {

    }
    if (n >= 60)
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
while(((dir = readdir(d)) != NULL) && (30<i<60)) {
    if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
    {}
    else {
        filesList[i]= dir->d_name;
        i++;
    }
}
rewinddir(d);

for(i=0; i<n; i++)
        {
        //printf("%s\n", filesList[i]);
        char *s;
        char *f;
        s = concat("/vol/qualifier/data/", filesList[i]);
        f = concat("/jail/", filesList[i]);
        printf("concat output: %s \n", s );
        printf("filelist output: %s \n", filesList[i] );
        copy( f, s );
        }
return 0;
}

*/

/*****************************function to copy files********************************************/

void copy (char *read, const char *write)
//void copy(const char *argc, char *argv)
{
     FILE *fp1, *fp2;
     char ch;
     int pos;
     
     //printf("\nContents of fp1: %s ", read);    
     fp1 = fopen(read,"rb"); 
     if (fp1 == NULL)
     {
         printf("\nRead file cannot be opened");
         return;
     }
     fp2 = fopen(write, "wb");
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
