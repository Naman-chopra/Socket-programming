#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void my_write(FILE *fp)
{
    fprintf(fp, "%s", str);
}

int main(void)
{
    char *str = "test text\n";
    FILE *fp;

    fp = fopen("index.html", "a");
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    my_write(fp);

    fclose(fp);

    return 0;
}