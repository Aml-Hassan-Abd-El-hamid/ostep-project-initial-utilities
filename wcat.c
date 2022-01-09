#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
  int   file;
  char  buffer[5];
  int   read_size;

  if (argc < 2)
    {
      return (0);
    }
   for(int j=1;j<argc;j++){
   
	  file = open(argv[j], O_RDONLY);
	  if (file == -1)
	    {
		    printf("wcat: cannot open file\n");
	      return (1);
	    }
	    
	   // printf("%d\n\n",file);
	  while ((read_size = read(file, buffer, 5)) > 0)
	  {
	    for(int i=0;i<read_size;i++) printf("%c",buffer[i]);
	    //printf("\n");
	    //write(1, &buffer, read_size);
	    }
	    //printf("%d\n",read_size);}

	  close(file);
	}
  return (0);
}
