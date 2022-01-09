#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
    FILE *fp;
    char newbuff[5], oldbuff[5];
    int count[2];
    int a=argc-1;
    //printf("%d",argc);
    if (argc < 2){
        printf("wzip: file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    // open files
    for (size_t i = 1; i < argc; i++){
        if ((fp = fopen(argv[i], "r")) == NULL){
            printf("wzip: cannot open file\n");
            exit(EXIT_FAILURE);
        }
        int i=1;
        while (a){
                fp = fopen(argv[i], "r");
		while (fread(newbuff, 1, 1, fp)){ 
		    if (newbuff[0]==oldbuff[0]){
		        //printf("hi hi");
		        count[0]++;
		    } else {
		        if (oldbuff[0] != '\0'){
		           if (count[0] !=0){
		            //printf("%d%c\n",count[0],oldbuff[0]);
		            fwrite(count,1,4,stdout);
		            fwrite(oldbuff,1,1,stdout);
		            }
		        }
		        count[0] = 1;
		        strcpy(oldbuff, newbuff);
		    }
		}
		fclose(fp);
	i++;	
        a--;
        }
        //if(p==false && oldbuff!='\0'){
        
        //}
    }
	fwrite(count,1,4,stdout);
        fwrite(oldbuff,1,1,stdout);
    return 0;
}

