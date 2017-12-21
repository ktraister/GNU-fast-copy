#include <stdio.h>
//THIS IS BROKEN AND IN NO WAY AN IMPROVEMENT IN CODE
//what if i made function light as possible to copy files
int main(int x, char **argc, char **argv)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;

    //if ((fp1 = fopen(argc,"rb")) == NULL)
    //{
    //    printf("\nFile cannot be opened");
    //}
    //else
    //{
    //    printf("\nFile opened for copy...\n ");
    //}
    //errno=0;
    fp1 = fopen(argc,"rb");
    fp2 = fopen(argv, "wb");
    //if (argv[1] == NULL);
    //  {
    //          printf("Error! %s\n", strerror(errno));
    //  }

    fseek(fp1, 0L, SEEK_END); // file pointer at end of file
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET); // file pointer set at start
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    }
    //fclose();
    fclose(fp2);
    fclose(fp1);
    return 0;
}
