 /* read files in /jail directory 
 * set files equal to array
 * move files to /vol/qualifier/data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

//enum { MAXLINES = 30 };

void copy(char *argc, char *argv);
//void extra(int elements, char *filesList, int i);
//void extra();

int main(void)
{
int n=0, i=0;
DIR *d;
struct dirent *dir;
int elements;
d = opendir("/jail");

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
        filesList[i]= dir->d_name;
        i++;
    }
}
rewinddir(d);

for(i=0; i<=n; i++)
	{
    	//printf("%s\n", filesList[i]);
	copy("tempfile", "otherfile");
	}
//extra(sizeof(filesList), filesList, i ); 
//extra();
return 0;
}


/*void extra() {
*	printf("Hey, C is hard, and you should be proud of yourself");
*/


//void extra(int elements, char *filesList, int i ) {
//	char *x;
//	x = "dog";
	//for (x = 0; x < elements; x++)
	//{}
	//	printf("%s %s %s\n", "EXTRA", "PRINT:", filesList[x]);
	//}
//}





/*****************************function to copy files********************************************/

//what if i made function light as possible to copy files 
void copy(char *argc, char *argv)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;

    //if ((fp1 = fopen(argv[1],"r")) == NULL)    
    //{    
    //    printf("\nFile cannot be opened");
    //    return;
    //}
    //else     
    //{
    //    printf("\nFile opened for copy...\n ");    
    //}
    errno=0;
    fp1 = fopen(&argc[0],"rb");
    fp2 = fopen(&argv[0], "wb");  
    if (argv[1] == NULL);
	{
		printf("Error! %s\n", strerror(errno));
	}

    fseek(fp1, 0L, SEEK_END); // file pointer at end of file
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET); // file pointer set at start
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    }    
    //fclose(); 
    fclose(fp1);
    fclose(fp2);   
}

