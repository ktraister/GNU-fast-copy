/********************************************worker2 for thread2*****************************************************************/

//void *worker2(char* filesList[n], int n = 0)
//{
//int n=0, i=0;
//int i=0;
//DIR *d;
//struct dirent *dir;
//int elements;
//d = opendir("/jail");

//Determine the number of files
//sleep(2);
/*printf("\n Start of worker2!");
while((dir = readdir(d)) != NULL) {
    if  ( (n < 60) && (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) )
    {
    }
    if (n <= 30)
    {
        n = 31;
        exit;
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
while(((dir = readdir(d)) != NULL) && (30<i)) {
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
        printf("%s\n", filesList[i]);
-- INSERT (paste) --
        {
        printf("%s\n", filesList[i]);
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
*/
