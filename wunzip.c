#include <stdio.h>
#include <stdlib.h>    // exit
#include <string.h>    // memset
#include <arpa/inet.h> // ntohl

int main(int argc, char *argv[])
{
    FILE *fp;
    char buff[5];

    if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (uint i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("wunzip: cannot open file\n");
            exit(EXIT_FAILURE);
        }

        int count[3];
	fread(count, 1, 4, fp);
        while (fread(buff, 1, 1, fp)) {
        	for (uint i = 0; i < count[0]; i++) {
            	    printf("%c", buff[0]);
          	}
            //printf("count :%d\n\n",count[0]);
            //count = ntohl(count);    // read from network byte order
            //memset(buff, 0, strlen(buff));
	    fread(count, 1, 4, fp);
            //printf("buffer: %c\n",buff[0]);
        }
        fclose(fp);
    }

return 0;
}
