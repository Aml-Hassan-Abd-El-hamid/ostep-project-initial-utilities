#include <stdlib.h>
#include <stdio.h>
#include <string.h>    // memset

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
  int file;//file descreptor
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  int line_size =0;

  //memset(line, 0, strlen(line));

  if (argc < 2)
    {
      printf("wgrep: searchterm [file ...]\n");
      return (1);
    }
   else if(argc<3){
         while ((line_size = getline(&line_buf, &line_buf_size, stdin))!= -1)
   {
      if(strstr(line_buf, argv[1])!=NULL){
      for(int i=0;i<line_size;i++)printf("%c",line_buf[i]);
      }
     // for(int i=0;i<line_size;i++)printf("%c",line_buf[i]);
     
   }
   }
   else{
   file = open(argv[2], O_RDONLY);
   if (file == -1)
	{
	   printf("wgrep: cannot open file\n");
	   return (1);
	 }  
   FILE* fp = fopen(argv[2], "r"); 
   while ((line_size = getline(&line_buf, &line_buf_size, fp))!= -1)
   {
      if(strstr(line_buf, argv[1])!=NULL){
      for(int i=0;i<line_size;i++)printf("%c",line_buf[i]);
      }
     // for(int i=0;i<line_size;i++)printf("%c",line_buf[i]);
     
   }
    }
  return (0);
}
