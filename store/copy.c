#include <stdio.h>

void main(int argc,char **argv)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;
    struct flock fl;
    fl.l_type   = F_WRLCK;  /* F_RDLCK, F_WRLCK, F_UNLCK */
    fl.l_whence = SEEK_SET; /* SEEK_SET, SEEK_CUR, SEEK_END */
    fl.l_start  = 0; /* Offset from l_whence */
    fl.l_len    = 0; /* length, 0 = to EOF */

    if (fcntl(fd, F_SETLK, &fl) == -1)
    {
    printf("%s\n", errno == EACCESS||errno == EAGAIN ? "In use by another process":"another error occurred");
    }

    if ((fp1 = fopen(argv[1],"r")) == NULL)
    {
        printf("\nFile cannot be opened");
        return;
    }
    else
    {
        printf("\nFile opened for copy...\n ");
    }
    
    fp2 = fopen(argv[2], "w");
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
