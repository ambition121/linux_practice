#include <sys/stat.h> 
 #include <sys/types.h> 
  #include <stdio.h> 


   int main(int argc, char *argv[]){ 

	      int rt; 
	         if( (rt = mkdir (argv[1],10705)) == -1 ){ 
			       fprintf(stderr,"cannot mkdir"); 
			          } 

				     return 0; 

				      }
